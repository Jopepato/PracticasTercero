#include "InstanceTSP.hpp"
#include "SolutionTSP.hpp"
#include <iostream>
#include <ctime>
#include <fstream>
#include "ClaseTiempo.hpp"
#include "NeighOperatorTSP.hpp"
#include "grasp.hpp"

int main(int argc, char ** argv){

	std::string fileName;
	int option;
	SolutionTSP sol;
	srand(time(NULL));
	std::string nombreFichero;
	if(argc!=2){
		//Numero de argumentos invalido
		std::cout << "NombrePrograma Fichero" << std::endl;
		exit(-1);
	}else{
		nombreFichero = argv[1];
	}


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

	Grasp graspito(instance);

	graspito.runGraspFile(nombreFichero);

}