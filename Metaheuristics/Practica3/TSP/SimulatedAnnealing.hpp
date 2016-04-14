#ifndef SIMULATEDANNEALING_HPP_
#define SIMULATEDANNEALING_HPP_

#include <vector>
#include <cmath>
#include "SolutionTSP.hpp"
#include <fstream>
#include <iostream>
#include <cmath>

class SimulatedAnnealing{

	private:
		SolutionTSP bestSolution_;
		SolutionTSP currentSolution_;
		double initialTemperature_;
		double temperature_;
		int capacity_;

	public:

		SimulatedAnnealing(SolutionTSP &randomSolution, const int &capacity, double media= 1.0, double k=0.3, double probabilidad=0.9){
		//Coge una aleatoria para best y current
			setBestSolution(randomSolution);
			setCurrentSolution(randomSolution);
			setCapacity(capacity);
			setInitialTemperature((-1.0)*media/k*log(probabilidad));
			//setInitialTemperature(1000);
			setTemperature(getInitialTemperature());
		}


		//Getters and Setters
		inline SolutionTSP getBestSolution() const
		{
			return bestSolution_;
		};

		inline void setBestSolution(const SolutionTSP &solution){
			bestSolution_ = solution;
		};

		inline SolutionTSP getCurrentSolution() const
		{
			return currentSolution_;
		};

		inline void setCurrentSolution(const SolutionTSP &solution){
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

		inline int getCapacity() const
		{
			return capacity_;
		};

		inline void setCapacity(const int &capacity){
			capacity_ = capacity;
		};


		//Functions

		void runSimulatedAnnealing();

		void runSimulatedAnnealingToFile(const std::string &nameFile);


		//Freeze a little bit the temperature
		void freezeTemperature(const int &iteration);


		//Check if we get that neighbout solution
		bool acceptSolution(SolutionTSP &neighbour);



};






#endif
