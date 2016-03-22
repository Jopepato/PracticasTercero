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
	SolutionTSP sol_;
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

	double getDistance(const std::vector<node> &v);

	inline double getDistance()const{
		return distance_;
	};

	inline void setDistance(const double &d){
		distance_=d;
	};

	inline void setSolutionTSP(const std::vector<node>& solucion){
		sol_.setSolution(solucion);
	}

	inline std::vector<node> getSolutionTSP() const{
		return (sol_.getSolution());
	}
};


#endif