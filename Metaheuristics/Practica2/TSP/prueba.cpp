#include "InstanceTSP.hpp"
#include "SolutionTSP.hpp"
#include "SolGeneratorTSP.hpp"
#include <iostream>

int main(){
	std::string fileName;
	int option;
	double optimalDistance;
	
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

	instance.readFile();



	SolGeneratorTSP generator(instance);
		//cout the optimal distance
	optimalDistance = generator.getDistance(instance.getSolutionTSP());
	std::cout << "Optimal distance inside: " << optimalDistance << std::endl << std::endl;
	generator.generateSol(instance);

	return 1;
}