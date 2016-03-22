#ifndef FI_NEIGH_EXPLORATOR_KP_
#define FI_NEIGH_EXPLORATOR_KP_

#include "NeighOperatorKP.hpp"

class FINeighExploratorKP{

	private:
		SolutionKP first_;
		int capacity_;
	public:
	
	FINeighExploratorKP(const SolutionKP &sol, const int &c){
		setFirst(sol);
		setCapacity(c);
	};

	inline void setFirst(const SolutionKP &sol){
		first_ = sol;
	};

	inline SolutionKP getFirst(){
		return first_;
	};

	inline void setCapacity(const int &c){
		capacity_ = c;
	};

	inline int getCapacity(){
		return capacity_;
	};

	SolutionKP getFirstImprovement(){
		SolutionKP aux = getFirst();
		NeighOperatorKP ope;

		for (int i = 0; i < 1000; ++i)
		{
			aux = ope.getNeighSolution(aux, getCapacity());
			if(aux.getPrice()> getFirst().getPrice()){
				setFirst(aux);
				break;
			}
		}
		return getFirst();
	};


};

#endif