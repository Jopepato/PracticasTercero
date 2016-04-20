#ifndef GRASP_HPP_
#define GRASP_HPP_

#include "SolutionTSP.hpp"
#include "FINeighExploratorTSP.hpp"
#include "InstanceTSP.hpp"
#include <fstream>
#include <vector>

class Grasp{
	private:
		SolutionTSP solution_;
		SolutionTSP bestSolution_;
		InstanceTSP instancia_;

	public:
		Grasp(const InstanceTSP &instancia){
			//TODO
			setInstancia(instancia);
			getRandomGreedy();
		};


		inline SolutionTSP getSolution() const{
			return solution_;
		};

		inline void setSolution(const SolutionTSP &solution){
			solution_ = solution;
		};

		inline InstanceTSP getInstancia()const{
			return instancia_;
		}

		inline void setInstancia(const InstanceTSP &instancia){
			instancia_ = instancia;
		}

		inline void setBestSolution(const SolutionTSP &bestSol){
			bestSolution_ = bestSol;
		}

		inline SolutionTSP getBestSolution() const{
			return bestSolution_;
		}

		void getRandomGreedy();

		void runGraspFile(const std::string &fileName);
		void runGrasp();

		double getDistanciaNodos(node n1, node n2);
};



#endif