#ifndef GRASP_HPP_
#define GRASP_HPP_

#include "SolutionKP.hpp"
#include "FINeighExploratorKP.hpp"
#include "InstanceKP.hpp"
#include <fstream>
#include <vector>

class Grasp{
	private:
		SolutionKP solution_;
		SolutionKP bestSolution_;
		InstanceKP instancia_;

	public:
		Grasp(const InstanceKP &instancia){
			//TODO
			setInstancia(instancia);
			getRandomGreedy();
		};


		inline SolutionKP getSolution() const{
			return solution_;
		};

		inline void setSolution(const SolutionKP &solution){
			solution_ = solution;
		};

		inline InstanceKP getInstancia()const{
			return instancia_;
		}

		inline void setInstancia(const InstanceKP &instancia){
			instancia_ = instancia;
		}

		inline void setBestSolution(const SolutionKP &bestSol){
			bestSolution_ = bestSol;
		}

		inline SolutionKP getBestSolution() const{
			return bestSolution_;
		}

		void getRandomGreedy();

		void muestraElementosGrasp();

		SolutionKP runGraspFile(const std::string &fileName);
		void runGrasp();
};



#endif