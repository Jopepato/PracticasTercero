#include "InstanceKP.hpp"
#include "SolutionKP.hpp"
#include "SolGeneratorKP.hpp"
#include <iostream>
int main(){
	InstanceKP instance("knapPI_12_500_1000.csv");
	//std::vector<knapsack> sol;
	
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