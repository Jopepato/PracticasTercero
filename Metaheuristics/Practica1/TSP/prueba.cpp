#include "InstanceTSP.hpp"
#include "SolutionTSP.hpp"
#include "SolGeneratorTSP.hpp"
#include <iostream>

int main(){
	std::string fileName;
	int option;
	
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
			std::cout << std::endl << "I can't take the exponent :<" << std::endl << std::endl;
			exit(EXIT_SUCCESS);
			break;
		default:
			fileName = "berlin52.tsp";
			break;
	}

	InstanceTSP instance(fileName);

	instance.readFile();

	SolGeneratorTSP generator(instance);
	generator.generateSol(instance);

	return 1;
}