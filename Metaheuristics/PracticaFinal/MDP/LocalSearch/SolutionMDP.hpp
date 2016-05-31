#ifndef SOLUTIONMDP_HPP_
#define SOLUTIONMDP_HPP_

#include <vector>
#include <iostream>
#include <cstdio>
#include "InstanceMDP.hpp"

class SolutionMDP{

private:
		std::vector<int> vectorSol_;
		InstanceMDP instance_;
public:
		SolutionMDP(){
			vectorSol_.clear();
		}

		SolutionMDP(const std::vector<int> &vectorSol, const InstanceMDP &instance){
			setSolution(vectorSol);
			setInstance(instance);
		}

		inline std::vector<int> getSolution()const{
			return vectorSol_;
		};

		inline void setSolution(const std::vector<int> &vectorSol){
			vectorSol_=vectorSol;
		};

/*
		std::vector< std::vector<double> > getMatrizDistancias()const{
			return matrizDistancias_;
		}

		void setMatrizDistancias(const std::vector< std::vector<double> > &matriz){

		}
*/

		inline InstanceMDP getInstance()const{
			return instance_;
		}

		inline void setInstance(const InstanceMDP &instance){
			instance_ = instance;
		}

		double getDistancia(){
			//Devuelve la distancia que es la suma de las distancias Ü :D
			double distancia = 0.0;
			for(unsigned int i=0; i<vectorSol_.size()-1; i++){
				distancia = distancia + getInstance().getMatriz()[vectorSol_[i]][vectorSol_[i+1]];
			}

			return distancia;
		}

		inline void printSol(){
			std::vector<int> auxV = vectorSol_;
			for(unsigned int i=0; i<auxV.size(); i++){
				std::cout << auxV[i] << " ";
			}
			std::cout << std::endl;
	}

};

#endif