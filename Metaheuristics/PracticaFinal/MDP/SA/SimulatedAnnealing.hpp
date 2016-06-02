#ifndef SIMULATEDANNEALING_HPP_
#define SIMULATEDANNEALING_HPP_

#include <vector>
#include <cmath>
#include "SolutionMDP.hpp"
#include <fstream>
#include <iostream>
#include <cmath>

class SimulatedAnnealing{

	private:
		SolutionMDP bestSolution_;
		SolutionMDP currentSolution_;
		double initialTemperature_;
		double temperature_;

	public:

		SimulatedAnnealing(SolutionMDP &randomSolution, double media= 1.0, double k=0.3, double probabilidad=0.9){
		//Coge una aleatoria para best y current
			setBestSolution(randomSolution);
			setCurrentSolution(randomSolution);
			setInitialTemperature((-1.0)*media/k*log(probabilidad));
			setTemperature(getInitialTemperature());
		}


		//Getters and Setters
		inline SolutionMDP getBestSolution() const
		{
			return bestSolution_;
		};

		inline void setBestSolution(const SolutionMDP &solution){
			bestSolution_ = solution;
		};

		inline SolutionMDP getCurrentSolution() const
		{
			return currentSolution_;
		};

		inline void setCurrentSolution(const SolutionMDP &solution){
			currentSolution_ = solution;
		};

		inline double getTemperature() const
		{
			return temperature_;
		};

		inline void setTemperature(const float &temp){
			temperature_ = temp;
		};

		inline double getInitialTemperature() const
		{
			return initialTemperature_;
		};

		inline void setInitialTemperature(const float &temp){
			initialTemperature_ = temp;
		};



		//Functions

		void runSimulatedAnnealing();

		void runSimulatedAnnealingToFile(const std::string &nameFile);


		//Freeze a little bit the temperature
		void freezeTemperature(const int &iteration);


		//Check if we get that neighbout solution
		bool acceptSolution(SolutionMDP &neighbour);



};






#endif
