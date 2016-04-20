#ifndef FI_NEIGH_EXPLORATOR_TSP_
#define FI_NEIGH_EXPLORATOR_TSP_

#include "NeighOperatorTSP.hpp"

class FINeighExploratorTSP{

	private:
		SolutionTSP first_;

	public:
	
	FINeighExploratorTSP(const SolutionTSP &sol){
		setFirst(sol);
	};

	inline void setFirst(const SolutionTSP &sol){
		first_ = sol;
	};

	inline SolutionTSP getFirst(){
		return first_;
	};

	SolutionTSP getFirstImprovement(int &j){
		SolutionTSP aux = getFirst();
		NeighOperatorTSP ope;
		int i;
		for (i = 0; i < 1000; i++){
			aux = ope.getNeighSolution(getFirst());
			if(aux.getDistance()< getFirst().getDistance()){
				setFirst(aux);
				break;
			}
		}
		j = j+i;
		return getFirst();
	};


};

#endif