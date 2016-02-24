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
	void printSol(const vector<knapsack> &v);
	bool compareSol(const vector<knapsack> &v, const int &weigth);
	void generateSol(const vector<knapsack> &v);

	int getWeight(const vector<knapsack> &v);

	inline int getWeight()const{
		return weightAux_;
	};

	inline void setWeight(const int &w){
		weightAux_=w;
	};
};

#endif