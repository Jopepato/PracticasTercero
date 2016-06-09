#ifndef SOLGENERATORMDP_HPP_
#define SOLGENERATORMDP_HPP_

#include "InstanceMDP.hpp"
#include "SolutionMDP.hpp"
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <limits>
#include <iostream>

class SolGeneratorMDP{
private:
	SolutionMDP sol_;
	InstanceMDP instancia_;
public:

	SolGeneratorMDP(){
		srand(time(NULL));
	}

	SolGeneratorMDP(const InstanceMDP& instancia){
		srand(time(NULL));
		instancia_ = instancia;
	}

	//Generates a random solution
	void generateSol();

	inline void setSolutionMDP(const std::vector<int>& solucion){
		sol_.setSolution(solucion);
	}

	inline std::vector<int> getSolutionMDPVector() const{
		return (sol_.getSolution());
	}
	inline SolutionMDP getSolutionMDP() const{
		return(sol_);
	}

	//Print the vector solution
	inline void printSol(){
	std::vector<int> auxV = sol_.getSolution();
		for(unsigned int i=0; i<auxV.size(); i++){
			std::cout << auxV[i] << " ";
		}
		std::cout << std::endl;
	}
};


#endif