#include "InstanceKP.hpp"
#include "SolutionKP.hpp"
#include "SolGeneratorKP.hpp"
#include <iostream>
int main(){
	std::string fileName;
	int option;
	//std::vector<knapsack> sol;
	
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

	SolGeneratorKP generator(instance);
	generator.generateSol(instance);
	//sol = instance.getSolutionKP();
	/*
	for(int i =0; i<sol.size(); i++){
		std::cout << i << ", " << sol[i].price << ", " << sol[i].weight << std::endl;
	}
	*/


	return 1;
}