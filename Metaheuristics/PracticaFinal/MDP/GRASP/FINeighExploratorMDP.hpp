#ifndef FI_NEIGH_EXPLORATOR_MDP_
#define FI_NEIGH_EXPLORATOR_MDP_

#include "NeighOperatorMDP.hpp"

class FINeighExploratorMDP{

	private:
		SolutionMDP first_;

	public:
	
	FINeighExploratorMDP(const SolutionMDP &sol){
		setFirst(sol);
	};

	inline void setFirst(const SolutionMDP &sol){
		first_ = sol;
	};

	inline SolutionMDP getFirst(){
		return first_;
	};

	SolutionMDP getFirstImprovement(int &j){
		SolutionMDP aux = getFirst();
		NeighOperatorMDP ope;
		int i=0;
		for (i = 0; i < 1000; i++){
			aux = ope.getNeighSolution(getFirst());
			if(aux.getDistancia()> getFirst().getDistancia()){
				setFirst(aux);
				break;
			}
		}
		j = j+i;
		return getFirst();
	};


};

#endif