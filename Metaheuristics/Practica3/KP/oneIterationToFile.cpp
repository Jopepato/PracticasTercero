#include "InstanceKP.hpp"
#include "SolutionKP.hpp"
#include "SolGeneratorKP.hpp"
#include <iostream>
#include <ctime>
#include <fstream>
#include "SimulatedAnnealing.hpp"
#include "ClaseTiempo.hpp"
#include "NeighOperatorKP.hpp"

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

	SolGeneratorKP generator(instance);


		double media = 0.0;

	//Calculamos la media de las diferencias
	for(int i=0; i<20; i++){
		SolutionKP sol1, sol2;
		NeighOperatorKP neigbour;

		generator.generateSol(instance);
		sol1 = generator.getSolutionKP();
		sol2 = neigbour.getNeighSolution(sol1, generator.getWeight());

		//Ahora la diferencia
		media = media + abs(sol1.getPrice() - sol2.getPrice());

	}
	media = media/20;


	generator.generateSol(instance);

	sol = generator.getSolutionKP();

	SimulatedAnnealing simulatedAnn(sol, generator.getWeight(), media);

	simulatedAnn.runSimulatedAnnealingToFile(nombreFichero);
}