#include "InstanceKP.hpp"
#include "SolutionKP.hpp"
#include "SolGeneratorKP.hpp"
#include <iostream>
#include <ctime>
#include <fstream>
#include "ClaseTiempo.hpp"
#include "NeighOperatorKP.hpp"
#include "grasp.hpp"

int main(int argc, char ** argv){

	std::string fileName;
	int option;
	SolutionKP sol;
	srand(time(NULL));
	std::string nombreFichero;
	if(argc!=2){
		//Numero de argumentos invalido
		std::cout << "NombrePrograma Fichero" << std::endl;
		exit(-1);
	}else{
		nombreFichero = argv[1];
	}


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

	Grasp graspito(instance);

	std::cout << "Pasando a fichero! :D" << std::endl;

	SolutionKP best = graspito.runGraspFile(nombreFichero);

}