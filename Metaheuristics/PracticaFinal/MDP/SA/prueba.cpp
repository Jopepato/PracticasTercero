#include "InstanceMDP.hpp"
#include "SolutionMDP.hpp"
#include "SolGeneratorMDP.hpp"
#include <iostream>
#include <ctime>
#include <fstream>
#include "SimulatedAnnealing.hpp"
#include "ClaseTiempo.hpp"
#include "NeighOperatorMDP.hpp"
int main(int argc, char ** argv){
	std::string fileName;
	SolutionMDP sol;
	srand(time(NULL));
	int iterations;
	std::string fileNameWrite;
	std::ofstream myfile;
	int option;
	Clock reloj;
	Clock reloj2;

	//We check if the parameters are k :D
	if(argc!=3){
		//The parameters are wrong
		std::cout << "La forma de llamar al programa es:" << std::endl;
		std::cout << "'NombrePrograma' 'NombreFicheroDestino' 'NumeroIteraciones'" << std::endl;
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
	std::cout << "File? " << std::endl << "\t1) 50 " << std::endl <<"\t2) 100 "
	 << std::endl << "\t3) 150 " << std::endl;
	std::cin >> option;
	switch(option){
		case 1:
			fileName = "GKD-b_19_n50_m15.txt";
			break;
		case 2:
			fileName = "GKD-b_30_n100_m30.txt";
			break;
		case 3:
			fileName = "GKD-b_46_n150_m45.txt";
			break;
		default:
			fileName = "GKD-b_30_n100_m30.txt";
			break;
	}


	//Ask the user which one we want to read

	InstanceMDP instance(fileName);

	instance.readFile();


	//We generate the solutions and pass it to a file
	SolGeneratorMDP generator(instance);


	std::cout << "\x1b[32mPasando a fichero...\x1b[0m" << std::endl;

	reloj2.start();

	generator.generateSol();

	sol = generator.getSolutionMDP();



	double media = 0.0;

	//Calculamos la media de las diferencias
	for(int i=0; i<20; i++){
		SolutionMDP sol1, sol2;
		NeighOperatorMDP neigbour;

		generator.generateSol();

		sol1 = generator.getSolutionMDP();
		sol1.setInstance(instance);
		sol2 = neigbour.getNeighSolutionOut(sol1);

		//Ahora la diferencia
		media = media + abs(sol1.getDistancia() - sol2.getDistancia());

	}

	media = media/20;
	

	SimulatedAnnealing simulatedAnn(sol, media);


	for(int i=0; i<iterations; i++){
		generator.generateSol();
		sol = generator.getSolutionMDP();
		sol.setInstance(instance);
		//Hacemos uno nuevo por iteración
		SimulatedAnnealing simulatedAnn(sol, media);

		simulatedAnn.runSimulatedAnnealing();
		//Pasamos los resultados a fichero
		//SolucionFinal MejorSolucion TemperaturaFinal
		myfile << i << " " << simulatedAnn.getCurrentSolution().getDistancia() << " " << simulatedAnn.getBestSolution().getDistancia() << " " << simulatedAnn.getTemperature() << std::endl;
		std::cout << i << " " << simulatedAnn.getCurrentSolution().getDistancia() << " " << simulatedAnn.getBestSolution().getDistancia() << " " << simulatedAnn.getTemperature() << std::endl;

	}

	reloj2.stop();

	std::cout << reloj2.elapsed()/1000000 << " segundos ha tardado esto" << std::endl;

	//We close the file
	myfile.close();
	return 1;
}
