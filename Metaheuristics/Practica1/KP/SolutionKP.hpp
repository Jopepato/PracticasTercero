#ifndef SOLUTIONKP_HPP_
#define SOLUTIONKP_HPP_

#include <vector>
#include <time.h>
#include <cstdlib>
#include "InstanceKP.hpp"

struct knapsack{
	int price;
	int weight;
	bool token;
};

class SolutionKP{

private:
		std::vector<knapsack> vectorKnapsack_;

public:
		SolutionKP(){
			vectorKnapsack_.clear();
			srand(time(NULL));
		}

		SolutionKP(const std::vector<knapsack> &vectorKnapsack){
			setSolution(vectorKnapsack);
		}

		inline std::vector<knapsack> getSolution()const{
			return vectorKnapsack_;
		};

		inline void setSolution(const std::vector<knapsack> &vectorKnapsack){
			vectorKnapsack_=vectorKnapsack;
		};
};

#endif