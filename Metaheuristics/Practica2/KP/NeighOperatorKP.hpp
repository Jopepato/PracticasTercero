#ifndef NEIGH_OPERATOR_KP_
#define NEIGH_OPERATOR_KP_

#include "SolutionKP.hpp"
#include <stdlib.h>     /* srand, rand */
#include <time.h>

#include <vector>
#include <iostream>

class NeighOperatorKP{

	public:

	SolutionKP getNeighSolution(const SolutionKP &sol, const int &capacity){
		std::vector <knapsack> aux = sol.getSolution();
		SolutionKP ret;
		SolGeneratorKP generator;
		bool flag=false;


		do{
			int a = rand()%aux.size();
			aux[a].token = !aux[a].token;
			ret.setSolution(aux);
			std::cout<<"hola"<<std::endl;
			ret.printSol();

		}while(ret.getWeight() > capacity);

		return ret;
	}

};

#endif