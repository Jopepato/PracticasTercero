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

	SolGeneratorTSP generator(instance);


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


	generator.generateSol(instance);

	sol = generator.getSolutionTSP();

	SimulatedAnnealing simulatedAnn(sol, media);

	simulatedAnn.runSimulatedAnnealingToFile(nombreFichero);
}