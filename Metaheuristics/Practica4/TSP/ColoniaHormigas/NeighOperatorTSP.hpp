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
		std::vector <node> aux2;
		node n;
		SolutionTSP ret;
		int a, b;

		do{
			a = std::rand()%aux.size();
			b = std::rand()%aux.size();
			n = aux[a];
			aux[a] = aux[b];
			aux[b] = n;
			if(a>b){
				int c;
				c = b;
				b = a;
				a = c;
			}
			for(int i = a+1, j=b-1; i<j; i++, j--){
				n = aux[i];
				aux[i] = aux[j];
				aux[j] = n;
			}

			ret.setSolution(aux);
		}while(a==b);

		return ret;
	}

};

#endif