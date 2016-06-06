#ifndef BI_NEIGH_EXPLORATOR_MDP_
#define BI_NEIGH_EXPLORATOR_MDP_

#include "NeighOperatorMDP.hpp"

class BINeighExploratorMDP{

	private:
		SolutionMDP best_;

	public:
	
	BINeighExploratorMDP(const SolutionMDP &sol){
		setBest(sol);
	};

	inline void setBest(const SolutionMDP &sol){
		best_ = sol;
	};

	inline SolutionMDP getBest(){
		return best_;
	};


	SolutionMDP getBestImprovement(){
		SolutionMDP aux = getBest();
		NeighOperatorMDP ope;
		SolutionMDP initial =getBest();

		for (int i = 0; i < 1000; ++i){
			aux = ope.getNeighSolution(initial);
			if(aux.getDistancia()> getBest().getDistancia()){
				setBest(aux);
			}
		}
		return getBest();
	};


};

#endif