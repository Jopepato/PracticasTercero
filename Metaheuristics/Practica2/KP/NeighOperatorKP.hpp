#ifndef NEIGH_OPERATOR_KP_
#define NEIGH_OPERATOR_KP_

#include "SolutionKP.hpp"
#include <cstdlib>     /* srand, rand */

#include <vector>
#include <iostream>
class NeighOperatorKP{

	public:
	//:D
	NeighOperatorKP(){};

	SolutionKP getNeighSolution(const SolutionKP &sol, const int &capacity){
		std::vector <knapsack> aux = sol.getSolution();
		SolutionKP ret;
		SolGeneratorKP generator;
		int a, b;
		bool flag=false;

		//We are doing this cheeky :D

		do{
			a = std::rand()%aux.size();
			if(aux[a].token == true){
				//nana
				while(true){
					//Buscamos el token falso
					b = std::rand()%aux.size();
					if(aux[b].token==false)
						break;
				}
			}else{
				//nano
				while(true){
					//Buscamos el token true
					b = std::rand()%aux.size();
					if(aux[b].token==true)
						break;
				}
			}


			aux[a].token = !aux[a].token;
			aux[b].token = !aux[b].token;
			ret.setSolution(aux);
			if (ret.getWeight()>capacity)
			{
				aux[a].token = !aux[a].token;
				aux[b].token = !aux[b].token;
				ret.setSolution(aux);
			}else{
				flag=true;
			}
		
		}while(!flag);

		return ret;
	}

};

#endif