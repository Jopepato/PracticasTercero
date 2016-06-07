#include "SolutionMDP.hpp"
#include "SimulatedAnnealing.hpp"
#include "NeighOperatorMDP.hpp"
#include <cstdlib>
#include <cstdio>

void SimulatedAnnealing::freezeTemperature(const int &iteration){
	//Baja la temperatura
	setTemperature(getTemperature()*0.91);
	//setTemperature(getInitialTemperature()/1+log(1+iteration));

}

bool SimulatedAnnealing::acceptSolution(SolutionMDP &neighbour){
	//Acepta o no? :D
	double difference =  neighbour.getDistancia()- getCurrentSolution().getDistancia();
	double probability = 0.0f;
	if(difference > 0){
		return true;
	}else{
		probability = 1-1/(1+exp((1.0)*difference/(0.3*getTemperature())));
		double aux = rand()%10;

		if(aux < probability*10 || probability == 1){

			//std::cout<<"Rand = "<<aux<<std::endl;
			return true;
		}else{
			//std::cout<<"NO"<<std::endl;
			return false;
		}
	}

}

void SimulatedAnnealing::runSimulatedAnnealing(){
    SolutionMDP aux = getCurrentSolution();
    NeighOperatorMDP neigh;

    for(int i =0 ;  i<100000 ; i++){
      aux = neigh.getNeighSolutionOut(getCurrentSolution());
      if(acceptSolution(aux)){
		    setCurrentSolution(aux);
	     }

      if(aux.getDistancia() > getBestSolution().getDistancia()){
        setBestSolution(aux);
      }
      if(i%1000 == 0 ){
        freezeTemperature(i);
      }

    }

  }


void SimulatedAnnealing::runSimulatedAnnealingToFile(const std::string &filename){
    SolutionMDP aux = getCurrentSolution();
    NeighOperatorMDP neigh;
    std::ofstream file;
    file.open(filename.c_str());

    for(int i =0 ;  i<100000; i++){
      aux = neigh.getNeighSolutionOut(getCurrentSolution());
      if(acceptSolution(aux)){
				setCurrentSolution(aux);
	  	}

      if(aux.getDistancia() > getBestSolution().getDistancia()){
        setBestSolution(aux);
      }

      file << i << " " << getTemperature() << " " << getBestSolution().getDistancia() << " " << getCurrentSolution().getDistancia() << std::endl;

      if(i%1000 == 0 ){
        freezeTemperature(i);
      }

    }

  }
