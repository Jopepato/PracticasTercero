#ifndef NEIGH_OPERATOR_TSP_
#define NEIGH_OPERATOR_TSP_

#include "SolutionTSP.hpp"
#include <cstdlib>     /* srand, rand */

#include <vector>
#include <iostream>
class NeighOperatorTSP{

	public:
	//:D
	NeighOperatorTSP(){};

	SolutionTSP getNeighSolution(const SolutionTSP &sol){
		std::vector <node> aux = sol.getSolution();
		node n;
		SolutionTSP ret;
		SolGeneratorTSP generator;
		int a, b;

		do{
			a = std::rand()%aux.size();
			b = std::rand()%aux.size();
			n = aux[a];
			aux[a] = aux[b];
			aux[b] = n;

			ret.setSolution(aux);
		}while(a==b);

		return ret;
	}

};

#endif