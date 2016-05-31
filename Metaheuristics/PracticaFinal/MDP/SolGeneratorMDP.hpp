#ifndef SOLGENERATORTSP_HPP_
#define SOLGENERATORTSP_HPP_

#include "InstanceTSP.hpp"
#include "SolutionTSP.hpp"
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <limits>

class SolGeneratorTSP{
private:
	double distance_;
	SolutionMDP sol_;
public:

	SolGeneratorTSP(){
		setDistance(0.0);
		srand(time(NULL));
	}

	SolGeneratorTSP(const InstanceTSP& instancia){
		setDistance(std::numeric_limits<double>::infinity());
		setSolutionTSP(instancia.getSolutionTSP());
		srand(time(NULL));
	}

	void generateSol(InstanceTSP instancia);

	inline void setSolutionMDP(const std::vector<int>& solucion){
		sol_.setSolution(solucion);
	}

	inline std::vector<node> getSolutionTSP() const{
		return (sol_.getSolution());
	}
};


#endif