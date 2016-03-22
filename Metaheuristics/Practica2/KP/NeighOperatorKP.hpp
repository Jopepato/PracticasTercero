#ifndef NEIGH_OPERATOR_KP_
#define NEIGH_OPERATOR_KP_

#include "SolutionKP.hpp"
#include <stdlib.h>     /* srand, rand */
#include <time.h>

#include <vector>

class NeighOperatorKP{

	public:

	SolutionKP getNeighSolution(const SolutionKP &sol, const int &capacity){
		std::vector <knapsack> aux = sol.getSolution();
		SolutionKP ret;
		SolGeneratorKP generator;

		do{
			int a = rand()%aux.length();

			if(aux[a].token == true){
				aux[a].token = false;
			}else{
				aux[a].token = true;
			}
			ret.setSolution(aux);

		}while(ret.getWeight() > capacity);

		return ret;
	}

};

#endif