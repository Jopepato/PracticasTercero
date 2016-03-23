#ifndef BI_NEIGH_EXPLORATOR_TSP_
#define BI_NEIGH_EXPLORATOR_TSP_

#include "NeighOperatorTSP.hpp"

class BINeighExploratorTSP{

	private:
		SolutionTSP best_;

	public:
	
	BINeighExploratorTSP(const SolutionTSP &sol){
		setBest(sol);
	};

	inline void setBest(const SolutionTSP &sol){
		best_ = sol;
	};

	inline SolutionTSP getBest(){
		return best_;
	};


	SolutionTSP getBestImprovement(){
		SolutionTSP aux = getBest();
		NeighOperatorTSP ope;
		SolutionTSP initial =getBest();

		for (int i = 0; i < 1000; ++i){
			aux = ope.getNeighSolution(initial);
			if(aux.getDistance()< getBest().getDistance()){
				setBest(aux);
			}
		}
		return getBest();
	};


};

#endif