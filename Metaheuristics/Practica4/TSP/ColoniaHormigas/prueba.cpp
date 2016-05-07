#include "InstanceTSP.hpp"
#include "SolutionTSP.hpp"
#include <iostream>
#include <ctime>
#include <fstream>
#include "Och.hpp"
#include "ClaseTiempo.hpp"
#include "NeighOperatorTSP.hpp"

int main(int argc, char ** argv){
	std::string fileName;
	int option;
	SolutionTSP sol;
	SolutionTSP primero;
	srand(time(NULL));
	int iterations;
	std::string fileNameWrite;
	std::string ficheroCaminosHormigas, ficheroSolucionesHormigas;
	std::string matrizFinal;
	std::ofstream myfile;
	Clock reloj;
	Clock reloj2;

	//We check if the parameters are k :D
	if(argc!=5){
		//The parameters are wrong
		std::cout << "La forma de llamar al programa es:" << std::endl;
		std::cout << "'NombrePrograma' 'NombreFichero' 'NumeroIteraciones' 'NombreFicheroCaminosHormigas' 'ficheroSolucionesHormigas'" << std::endl;
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
		ficheroCaminosHormigas = argv[3];
		ficheroSolucionesHormigas = argv[4];
		remove(ficheroCaminosHormigas.c_str());
		remove(ficheroSolucionesHormigas.c_str());

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
	SolutionTSP best;

	instance.readFile();


	std::cout << "\x1b[32mPasando a fichero...\x1b[0m" << std::endl;

	reloj2.start();

	Och algoritmo(instance);
	for (int i = 0; i < iterations; ++i)
	{
		algoritmo.runAnts(i, ficheroSolucionesHormigas);
		best = algoritmo.getBestSolution();
		//std::cout << i << " " << best.getDistance() << std::endl;
		myfile << i << " " << best.getDistance() << std::endl;
		if(i==5){
			primero = best;
		}
	}
	

	reloj2.stop();
	algoritmo.imprimeCamino(primero.getSolution(), best.getSolution(), ficheroCaminosHormigas);
	std::cout << reloj2.elapsed()/1000000 << " segundos ha tardado esto" << std::endl;

	//We close the file
	myfile.close();
	return 1;
}
