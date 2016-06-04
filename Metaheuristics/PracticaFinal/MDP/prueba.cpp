#include <iostream>
#include "InstanceMDP.hpp"
#include "SolGeneratorMDP.hpp"
#include "BINeighExploratorMDP.hpp"
#include "FINeighExploratorMDP.hpp"
#include "NeighOperatorMDP.hpp"

int main(int argc, char ** argv){
	std::string fileName;
	srand(time(NULL));
	std::string fileNameWrite;
	int iterations;
	std::ofstream myfile;

	//Metemos por comandos el numero de iteraciones y el fichero de los datos
	if(argc!=3){
		std::cout << "Comandos mal" << std::endl;
		std::cout << "Programa iteraciones ficheroSalida" << std::endl;
	}else{
		iterations = atoi(argv[1]);
		fileNameWrite = argv[2];
	}
	
	/*
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
*/
	fileName = "GKD-a_9_n10_m3.txt";
	InstanceMDP instance(fileName);

	instance.readFile();
	SolGeneratorMDP solgen(instance);
	myfile.open(fileNameWrite.c_str());
	
	for(int i =0; i<iterations; i++){
	
	solgen.generateSol();
	SolutionMDP sol(solgen.getSolutionMDPVector(), instance);
	if(i==0){
		SolutionMDP solBest(solgen.getSolutionMDPVector(), instance);
	}
	if(sol.getDistancia() > solBest.getDistancia()){
		solBest.setSolution(sol.getSolution());
	}
	myfile << i << " " << sol.getDistancia() << " " << solBest.getDistancia();
	}
	return 1;
}