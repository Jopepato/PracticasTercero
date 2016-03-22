#include "LocalSearchKP.hpp"

#include <vector>

SolutionKP LocalSearchKP::getOptimal(){
	//We are going to watch over the solution and get the optimal
	//changing each of the tokens
	SolutionKP aux;
	SolutionKP best;
	std::vector<knapsack> auxV = getSol().getSolution();

	for(int i=0; i<auxV.length(), i++){
		//En cada paso cambias una y te quedas con la mejor solucion

		//This is pauperrim
		auxV.token = !auxV.token;

		aux.setSolution(auxV);

		if(aux.getPrice() > getSol().getPrice()){
			best.setSolution(auxV);
		}

		//We change it back :D
		auxV.token = !auxV.token;
	}

	setSol(best);

	return getSol();
}