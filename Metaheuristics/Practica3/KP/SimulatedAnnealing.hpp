#ifndef SIMULATEDANNEALING_HPP_
#define SIMULATEDANNEALING_HPP_

#include <vector>
#include <cmath>
#include "SolutionKP.hpp"
#include <fstream>
#include <iostream>

class SimulatedAnnealing{

	private:
		SolutionKP bestSolution_;
		SolutionKP currentSolution_;
		double initialTemperature_;
		double temperature_;
		int capacity_;

	public:

		SimulatedAnnealing(SolutionKP &randomSolution, const int &capacity){
		//Coge una aleatoria para best y current
			setBestSolution(randomSolution);
			setCurrentSolution(randomSolution);
			setCapacity(capacity);
			//setInitialTemperature((10*randomSolution.getPrice())/-log(0.5));
			setInitialTemperature(10000);
			setTemperature(getInitialTemperature());
		}


		//Getters and Setters
		inline SolutionKP getBestSolution() const
		{
			return bestSolution_;
		};

		inline void setBestSolution(const SolutionKP &solution){
			bestSolution_ = solution;
		};

		inline SolutionKP getCurrentSolution() const
		{
			return currentSolution_;
		};

		inline void setCurrentSolution(const SolutionKP &solution){
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


		//Freeze a little bit the temperature
		void freezeTemperature(const int &iteration);


		//Check if we get that neighbout solution
		bool acceptSolution(SolutionKP &neighbour);



};






#endif
