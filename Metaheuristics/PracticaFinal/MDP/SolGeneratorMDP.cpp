#include "SolGeneratorMDP.hpp"
#include <iostream>
#include <math.h>
#include <cstdlib>


	void SolGeneratorMDP::generateSol(){
		
		std::vector<int> aux;
		std::vector<int> final;
		int random;
		for (int i = 0; i < instancia_.getSize(); ++i)
		{
			aux.push_back(i);
		}

		//Ahora rellenamos el vector solucion de forma aleatoria
		for(int i=0; i<instancia_.getSubSize(); i++){
			//Sacamos un random del vector el otro y lo metemos, asi evitamos repeticiones
			random = rand()%aux.size();
			final.push_back(aux[random]);
			aux.erase(aux.begin()+random);
		}

		setSolutionMDP(final);
	}
