#include "InstanceKP.hpp"
#include "SolutionKP.hpp"
#include "SolGeneratorKP.hpp"
#include <iostream>
#include <ctime>
#include <fstream>
#include "NeighOperatorKP.hpp"
#include "Och.hpp"
#include "ClaseTiempo.hpp"
int main(int argc, char ** argv){
	std::string fileName;
	int option;
	SolutionKP sol;
	srand(time(NULL));
	int iterations;
	std::string ficheroMejoresSoluciones;
	std::string ficheroSolucionesHormigas;
	std::ofstream myfile;
	Clock reloj;
	Clock reloj2;

	//We check if the parameters are k :D
	if(argc!=4){
		//The parameters are wrong
		std::cout << "La forma de llamar al programa es:" << std::endl;
		std::cout << "'NombrePrograma' 'NombreFicheroMejores' 'NumeroIteraciones' 'NombreFicheroHormigas'" << std::endl;
		//We exit the program
		exit(-1);
	}else{
		ficheroMejoresSoluciones = argv[1];
		iterations = atoi(argv[2]);
		ficheroSolucionesHormigas = argv[3];
		myfile.open(ficheroMejoresSoluciones.c_str());
		if(!myfile.is_open()){
			std::cout << "Error con el fichero" << std::endl;
			exit(-1);
		}
	}

	//Ask the user which one we want to read
	std::cout << "File? " << std::endl << "\t1) 200 elements" << std::endl <<"\t2) 500 elements"
	 << std::endl << "\t3) 10000 elements" << std::endl;
	std::cin >> option;
	switch(option){
		case 1:
			fileName = "knapPI_1_200_10000.csv";
			break;
		case 2:
			fileName = "knapPI_12_500_1000.csv";
			break;
		case 3:
			fileName = "knapPI_1_10000_1000000.csv";
			break;
		default:
			fileName = "knapPI_1_10000_1000000.csv";
			break;
	}

	InstanceKP instance(fileName);

	instance.readFile();


	//We generate the solutions and pass it to a file
	SolGeneratorKP generator(instance);


	std::cout << "\x1b[32mPasando a fichero...\x1b[0m" << std::endl;

	reloj2.start();

	generator.generateSol(instance);
	sol = generator.getSolutionKP();
	Och hormiga(instance);
	SolutionKP best;

	for(int i=0; i<iterations; i++){
		hormiga.runAnts(i, ficheroSolucionesHormigas);
		best = hormiga.getBestSolution();
		std::cout << i << " " << best.getPrice() << " " << best.getSolution().size() << std::endl;
		myfile << i << " " << best.getPrice() << " " << best.getWeight() << best.getSolution().size() << std::endl;
	}


	reloj2.stop();

	std::cout << reloj2.elapsed()/1000000 << " segundos ha tardado esto" << std::endl;

	//We close the file
	myfile.close();
	return 1;
}
