#include "InstanceTSP.hpp"
#include "SolutionTSP.hpp"
#include "SolGeneratorTSP.hpp"
#include <iostream>
#include <ctime>
#include <fstream>
#include "SimulatedAnnealing.hpp"
#include "ClaseTiempo.hpp"
#include "NeighOperatorTSP.hpp"
int main(int argc, char ** argv){
	std::string fileName;
	int option;
	SolutionTSP sol;
	srand(time(NULL));
	int iterations;
	std::string fileNameWrite;
	std::ofstream myfile;
	Clock reloj;
	Clock reloj2;

	//We check if the parameters are k :D
	if(argc!=3){
		//The parameters are wrong
		std::cout << "La forma de llamar al programa es:" << std::endl;
		std::cout << "'NombrePrograma' 'NombreFichero' 'NumeroIteraciones'" << std::endl;
		//We exit the program
		exit(-1);
	}else{
		fileNameWrite = argv[1];
		iterations = atoi(argv[2]);
		myfile.open(fileNameWrite.c_str());
		if(!myfile.is_open()){
			std::cout << "Error con el fichero" << std::endl;
			exit(-1);
		}
	}

	//Ask the user which one we want to read
	std::cout << "File? " << std::endl << "\t1) 52 nodes" << std::endl <<"\t2) 150 nodes"
	 << std::endl << "\t3) 2103 nodes" << std::endl;
	std::cin >> option;
	switch(option){
		case 1:
			fileName = "berlin52.tsp";
			break;
		case 2:
			fileName = "ch150.tsp";
			break;
		case 3:
			fileName = "d2103.tsp";
			break;
		default:
			fileName = "berlin52.tsp";
			break;
	}

	InstanceTSP instance(fileName);

	instance.readFile();


	//We generate the solutions and pass it to a file
	SolGeneratorTSP generator(instance);


	std::cout << "\x1b[32mPasando a fichero...\x1b[0m" << std::endl;

	reloj2.start();

	generator.generateSol(instance);
	sol = generator.getSolutionTSP();



	double media = 0.0;

	//Calculamos la media de las diferencias
	for(int i=0; i<20; i++){
		SolutionTSP sol1, sol2;
		NeighOperatorTSP neigbour;

		generator.generateSol(instance);
		sol1 = generator.getSolutionTSP();
		sol2 = neigbour.getNeighSolution(sol1);

		//Ahora la diferencia
		media = media + abs(sol1.getDistance() - sol2.getDistance());

	}
	media = media/20;



	SimulatedAnnealing simulatedAnn(sol, media);

	for(int i=0; i<iterations; i++){
	generator.generateSol(instance);
	sol = generator.getSolutionTSP();
	//Hacemos uno nuevo por iteración
	SimulatedAnnealing simulatedAnn(sol, media);
	
	simulatedAnn.runSimulatedAnnealing();
	//Pasamos los resultados a fichero
	//SolucionFinal MejorSolucion TemperaturaFinal
	myfile << i << " " << simulatedAnn.getCurrentSolution().getDistance() << " " << simulatedAnn.getBestSolution().getDistance() << " " << simulatedAnn.getTemperature() << std::endl;
	std::cout << i << " " << simulatedAnn.getCurrentSolution().getDistance() << " " << simulatedAnn.getBestSolution().getDistance() << " " << simulatedAnn.getTemperature() << std::endl;

	}

	reloj2.stop();

	std::cout << reloj2.elapsed()/1000000 << " segundos ha tardado esto" << std::endl;

	//We close the file
	myfile.close();
	return 1;
}
