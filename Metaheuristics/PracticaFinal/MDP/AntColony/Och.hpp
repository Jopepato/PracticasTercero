#ifndef OCH_HPP
#define OCH_HPP

#include <vector>
#include <limits>
#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include "InstanceMDP.hpp"
#include "SolutionMDP.hpp"
#include "SolGeneratorMDP.hpp"

//CAMBIOS

struct Ant{
	std::vector <int> solution;
	double aportePheromonas;
	double distancia;
};


class Och{

	private:
		double pheromone_;
		double alpha_;
		double beta_;
		int numAnt_;
		SolutionMDP bestSolution_;
		double vaporizePercentage_;
		std::vector< std::vector <double> > pheromoneMatrix_;
		std::vector< std::vector <double> > heuristicMatrix_;
		std::vector<Ant> hormiguitas_;
		InstanceMDP instance_;

	public:


		Och(const InstanceMDP &instance){
			setPheromone(10);
			setVaporizePercentage(0.05);
			setBeta(2);
			setAlpha(1);
			setNumAnt(10);
			//CAMBIOS
			setInstance(instance);
			fillMatrix(instance.getSize());
		}

		void setInstance(const InstanceMDP &i){
			instance_=i;
		}

		InstanceMDP getInstance()const{
			return instance_;
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

		SolutionMDP getBestSolution() const{
			return bestSolution_;
		}

		void setBestSolution(const std::vector<int> &solution){
			bestSolution_.setSolution(solution);
			bestSolution_.setInstance(instance_);
		}

		//Funciones para la construncción y uso de las hormigüitas

		void fillMatrix(const int &length);

		double aporteArco(const int &x, const int &y);

		double getProbability();

		void runAnts(int &iterations, std::string ficheroSolucionesHormigas);

		void refreshPheromoneMatrix();

		int getNextNode(const int &x, const std::vector<int> &caminoHormiga);

		void getBestAntSolution();

		bool isInVector(const int &x, const std::vector<int> &caminoHormiga);

		void imprimeCamino(const std::vector<int> &primero, const std::vector<int> &segundo, std::string nombreFicheroCaminos);

		~Och(){
			pheromoneMatrix_.clear();
		}


};

#endif