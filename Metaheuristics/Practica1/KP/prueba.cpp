#include "InstanceKP.hpp"
#include "SolutionKP.hpp"
#include <iostream>
int main(){
	InstanceKP instance("knapPI_12_500_1000.csv");
	std::vector<knapsack> sol;

	std::vector<knapsack> vector;
	SolutionKP solution(instance.readFile());
	sol = solution.getSolution();

	for(int i =0; i<sol.size(); i++){
		std::cout << i << ", " << sol[i].price << ", " << sol[i].weight << std::endl;
	}
	return 1;
}