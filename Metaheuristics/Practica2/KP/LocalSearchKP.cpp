#include "LocalSearchKP.hpp"

#include <vector>

SolutionKP LocalSearchKP::getOptimal(){
	//We are going to watch over the solution and get the optimal
	//changing each of the tokens
	SolutionKP aux;
	SolutionKP best;
	std::vector<knapsack> auxV = getSol().getSolution();

	for(unsigned int i=0; i<auxV.size(); i++){
		// In each step, you change one and you pick the best one.

		//This is pauperrim
		auxV[i].token = !auxV[i].token;

		aux.setSolution(auxV);

		if(aux.getPrice() > getSol().getPrice()){
			best.setSolution(auxV);
		}

		//We change it back :D
		auxV[i].token = !auxV[i].token;
	}

	setSol(best);

	return getSol();
}