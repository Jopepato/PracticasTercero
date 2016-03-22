#ifndef SOLGENERATORKP_HPP_
#define SOLGENERATORKP_HPP_

#include "InstanceKP.hpp"
#include "SolutionKP.hpp"
#include <stdlib.h>     /* srand, rand */
#include <time.h>

class SolGeneratorKP{
private:
	int weightAux_;
	SolutionKP sol_;
public:

	SolGeneratorKP(){
		setWeight(0);
		srand(time(NULL));
	}

	SolGeneratorKP(const InstanceKP& instancia){
		setWeight(instancia.getCapacity());
		setSolutionKP(instancia.getSolutionKP());
		srand(time(NULL));
	}

	void printSol();
	bool compareSol(const std::vector<knapsack> &v, const int &weigth);
	void generateSol(InstanceKP instancia);

	int getWeight(const std::vector<knapsack> &v);

	inline int getWeight()const{
		return weightAux_;
	};

	inline void setWeight(const int &w){
		weightAux_=w;
	};

	inline void setSolutionKP(const std::vector<knapsack>& solucion){
		sol_.setSolution(solucion);
	}

	inline std::vector<knapsack> getSolutionKP() const{
		return (sol_.getSolution());
	}
};


#endif