#include "LocalSearchTSP.hpp"

#include <vector>

SolutionTSP LocalSearchTSP::getOptimal(){
	//We are going to watch over the solution and get the optimal
	//changing each of the tokens
	SolutionTSP aux;
	SolutionTSP best = getSol();
	std::vector<node> auxV = getSol().getSolution();
	node n;

	for(unsigned int i=0; i<auxV.size(); i++){
		// In each step, you change one and you pick the best one.
		for(unsigned int j=0; j<auxV.size(); j++){
			//This is pauperrim
			if(i!=j){
				n = auxV[i];
				auxV[i] = auxV[j];
				auxV[j] = n;

				aux.setSolution(auxV);

				if(aux.getDistance()< best.getDistance()){
					best.setSolution(auxV);
				}

				n = auxV[i];
				auxV[i] = auxV[j];
				auxV[j] = n;
			}
		}
	}

	setSol(best);

	return getSol();
}