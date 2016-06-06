#include "InstanceMDP.hpp"
#include "SolutionMDP.hpp"
#include <iostream>
#include <ctime>
#include <fstream>
#include "Och.hpp"
#include "NeighOperatorMDP.hpp"

int main(int argc, char ** argv){
	std::string fileName;
	int option;
	SolutionMDP sol;
	SolutionMDP primero;
	srand(time(NULL));
	int iterations;
	std::string fileNameWrite;
	std::string ficheroSolucionesHormigas;
	std::ofstream myfile;

	//We check if the parameters are k :D
	if(argc!=4){
		//The parameters are wrong
		std::cout << "La forma de llamar al programa es:" << std::endl;
		std::cout << "'NombrePrograma' 'NombreFichero' 'NumeroIteraciones' 'ficheroSolucionesHormigas'" << std::endl;
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
		ficheroSolucionesHormigas = argv[3];
		remove(ficheroSolucionesHormigas.c_str());

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

	InstanceMDP instance(fileName.c_str());

	SolutionMDP best;

	std::cout << "\x1b[32mPasando a fichero...\x1b[0m" << std::endl;

	Och algoritmo(instance);

	for (int i = 0; i < iterations; ++i)
	{
		algoritmo.runAnts(i, ficheroSolucionesHormigas);
		best = algoritmo.getBestSolution();
		std::cout << i << " " << best.getDistancia() << std::endl;
		myfile << i << " " << best.getDistancia() << std::endl;
		if(i==algoritmo.getNumAnt()){
			primero = best;
		}
	}
	
	//algoritmo.imprimeCamino(primero.getSolution(), best.getSolution(), ficheroCaminosHormigas);

	//We close the file
	myfile.close();
	return 1;
}
