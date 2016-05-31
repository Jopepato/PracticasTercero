#ifndef SOLGENERATORMDP_HPP_
#define SOLGENERATORMDP_HPP_

#include "InstanceMDP.hpp"
#include "SolutionMDP.hpp"
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <limits>

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
};


#endif