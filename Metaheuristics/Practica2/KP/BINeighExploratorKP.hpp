#ifndef BI_NEIGH_EXPLORATOR_KP_
#define BI_NEIGH_EXPLORATOR_KP_

#include "NeighOperatorKP.hpp"

class BINeighExploratorKP{

	private:
		SolutionKP best_;
		int capacity_;
	public:
	
	BINeighExploratorKP(const SolutionKP &sol, const int &c){
		setBest(sol);
		setCapacity(c);
	};

	inline void setBest(const SolutionKP &sol){
		best_ = sol;
	};

	inline SolutionKP getBest(){
		return best_;
	};

	inline void setCapacity(const int &c){
		capacity_ = c;
	};

	inline int getCapacity(){
		return capacity_;
	};

	SolutionKP getBestImprovement(){
		SolutionKP aux = getBest();
		NeighOperatorKP ope;
		SolutionKP initial =getBest();

		for (int i = 0; i < 1000; ++i)
		{
			aux = ope.getNeighSolution(initial, getCapacity());
			if(aux.getPrice()> getBest().getPrice()){
				setBest(aux);
			}
		}
		return getBest();
	};


};

#endif