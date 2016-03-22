#ifndef BI_NEIGH_EXPLORATOR_KP_
#define BI_NEIGH_EXPLORATOR_KP_

#include "NeighOperatorKP.hpp"

class BINeighExploratorKP{

	private:
		SolutionKP best_;
		int capacity_;
	public:
	
	BINeighExploratorKP(const SolutionKP &sol, const int &c){
		setFirst(sol);
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
		SolutionKP aux = sol;
		NeighOperatorKP ope;

		for (int i = 0; i < 1000; ++i)
		{
			aux = ope.getNeighSolution(aux, getCapacity());
			if(aux.getPrice()> sol.getPrice()){
				setFirst(aux);
			}
		}
		return getBest();
	};


};

#endif