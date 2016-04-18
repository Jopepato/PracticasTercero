#ifndef GRASP_HPP_
#define GRASP_HPP_

#include "SolutionKP.hpp"
#include "FINeighExploratorKP.hpp"
#include "InstanceKP.hpp"
#include <vector>

class Grasp{
	private:
		SolutionKP solution_;

	public:
		Grasp(const InstanceKP &instancia){
			//TODO
			getRandomGreedy(instancia);
		};


		inline SolutionKP getSolution() const{
			return solution_;
		};

		inline void setSolution(const SolutionKP &solution){
			solution_ = solution;
		};

		void getRandomGreedy(const InstanceKP &instancia);

};



#endif