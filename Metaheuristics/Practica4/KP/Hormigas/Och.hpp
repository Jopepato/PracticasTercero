#ifndef OCH_HPP
#define OCH_HPP

#include <vector>
#include <limits>
#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include <fstream>
#include "InstanceKP.hpp"
#include "SolutionKP.hpp"
#include "SolGeneratorKP.hpp"

//CAMBIOS

struct Ant{
	std::vector <knapsack> solution;
	double aportePheromonas;
};


class Och{

	private:
		double pheromone_;
		double alpha_;
		double beta_;
		int numAnt_;
		double capacity_;
		SolutionKP bestSolution_;
		double vaporizePercentage_;
		std::vector <double> pheromoneVector_;
		std::vector <double> distanceVector_;
		std::vector <double> heuristicVector_;
		std::vector<knapsack> original_;
		std::vector<Ant> hormiguitas_;

	public:


		Och(const InstanceKP &instance){
			setPheromone(10);
			setVaporizePercentage(0.9);
			setBeta(1);
			setAlpha(1);
			setNumAnt(5);
			setCapacity(instance.getCapacity());
			//CAMBIOS
			setBestSolution(instance.getSolutionKP());
			setOriginal(instance.getSolutionKP());
			fillPheromoneVector(instance.getSolutionKP().size());
			fillHeuristicVector(instance.getSolutionKP());
		}

		void setPheromone(const double &pherom){
			pheromone_ = pherom;
		}

		double getPheromone() const{
			return pheromone_;
		}

		void setAlpha(const double &alpha){
			alpha_ = alpha;
		}
		
		void setCapacity(const double &capacity){
			capacity_ = capacity;
		}

		double getCapacity() const{
			return capacity_;
		}

		double getAlpha() const{
			return alpha_;
		}

		void setBeta(const double &beta){
			beta_ = beta;
		}

		double getBeta() const{
			return beta_;
		}

		int getNumAnt() const{
			return numAnt_;
		}

		void setNumAnt(const int &numAnt){
			numAnt_ = numAnt;
		}

		void setVaporizePercentage(const double &perc){
			vaporizePercentage_ = perc;
		}

		double getVaporizePercentage() const{
			return vaporizePercentage_;
		}

		void setHormiguitas(const std::vector<Ant> &hormi){
			hormiguitas_ = hormi;
		};

		std::vector<Ant> getHormiguitas() const{
			return hormiguitas_;
		}

		std::vector<knapsack> getOriginal() const{
			return original_;
		}

		void setOriginal(const std::vector<knapsack> &orig){
			original_ = orig;
		}

		SolutionKP getBestSolution() const{
			return bestSolution_;
		}

		void setBestSolution(const std::vector<knapsack> &solution){
			bestSolution_.setSolution(solution);
		}

		//Funciones para la construncción y uso de las hormigüitas

		void fillPheromoneVector(const int &length);

		double aporteArco(const int &x);

		void fillHeuristicVector(const std::vector<knapsack> &nodes);

		double getProbability();

		void runAnts(int &iterations, std::string ficheroSolucionesHormigas);

		void refreshPheromoneVector();

		knapsack getNextNode(const std::vector<knapsack> &caminoHormiga);

		void getBestAntSolution();

		bool isInVector(const int &x, const std::vector<knapsack> &caminoHormiga);


		~Och(){
			pheromoneVector_.clear();
		}


};

#endif