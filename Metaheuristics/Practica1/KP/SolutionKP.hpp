#ifndef SOLUTIONKP_HPP_
#define SOLUTIONKP_HPP_

#include <vector>
#include "InstanceKP.hpp"

class SolutionKP{

private:
		std::vector<knapsack> vectorKnapsack_;

public:
		SolutionKP(){

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