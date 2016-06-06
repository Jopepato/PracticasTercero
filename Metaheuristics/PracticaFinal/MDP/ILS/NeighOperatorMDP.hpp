#ifndef NEIGH_OPERATOR_MDP_
#define NEIGH_OPERATOR_MDP_

#include "SolutionMDP.hpp"
#include <cstdlib>     /* srand, rand */

#include <vector>
#include <iostream>
class NeighOperatorMDP{

	public:
	//:D
	NeighOperatorMDP(){};

	SolutionMDP getNeighSolution(SolutionMDP sol){

		std::vector<int> auxV = sol.getSolution();
		int aux;

		int a = rand()%auxV.size();
		int b = rand()%auxV.size();

		aux = auxV[a];
		auxV[a] = auxV[b];
		auxV[b] = aux;

		sol.setSolution(auxV);
		return sol;
	}

	SolutionMDP getNeighSolutionOut(SolutionMDP sol){

		//Cambiamos un elemento por uno que esta fuera
		std::vector <int> auxV = sol.getSolution();
		int random;
		while(true){
			random = rand()%sol.getInstance().getSize();
			if(!isInVector(auxV, random)){
				//Cambiamos y nos salimos
				auxV[rand()%auxV.size()] = random;
				break;
			}
		}
		sol.setSolution(auxV);
		return sol;
	}

	inline bool isInVector(const std::vector<int> &v, const int &a){
		for(unsigned int i=0; i<v.size(); i++){
			if(v[i]==a){
				return true;
			}
		}
		return false;
	}

};

#endif