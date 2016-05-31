#include "SolGeneratorTSP.hpp"
#include <iostream>
#include <math.h>


	void SolGeneratorTSP::generateSol(InstanceTSP instancia){
		
		std::vector<int> aux;
		std::vector<int> final;
		for (int i = 0; i < instancia.getSize(); ++i)
		{
			aux.push_back(i);
		}

		//Ahora rellenamos el vector solucion de forma aleatoria
		for(int i=0; i<instancia.getSubSize(); i++){
			//Terminar perdon pero me he ido a ver got
		}
	}
