#ifndef GRASP_HPP_
#define GRASP_HPP_

#include "SolutionMDP.hpp"
#include "InstanceMDP.hpp"
#include <fstream>
#include <vector>

class Grasp{
	private:
		SolutionMDP solution_;
		SolutionMDP bestSolution_;
		InstanceMDP instancia_;

	public:
		Grasp(const InstanceMDP &instancia){
			//TODO
			setInstancia(instancia);
			getRandomGreedy();
		};


		inline SolutionMDP getSolution() const{
			return solution_;
		};

		inline void setSolution(const SolutionMDP &solution){
			solution_ = solution;
		};

		inline InstanceMDP getInstancia()const{
			return instancia_;
		}

		inline void setInstancia(const InstanceMDP &instancia){
			instancia_ = instancia;
		}

		inline void setBestSolution(const SolutionMDP &bestSol){
			bestSolution_ = bestSol;
		}

		inline SolutionMDP getBestSolution() const{
			return bestSolution_;
		}

		void getRandomGreedy();

		void runGraspFile(const std::string &fileName);
		void runGrasp();
};



#endif