#include "SolutionKP.hpp"


void SimulatedAnnealing::freezeTemperature(const int &iteration){
	//Baja la temperatura
	setTemperature(getInitialTemperature()/(1+log(1+iteration)));
}

bool SimulatedAnnealing::acceptSolution(const SolutionKP &neighbour){
	//Acepta o no? :D
	double difference = getCurrentSolution().getPrice() - neighbour.getPrice();
	double probability = 0;
	if(difference<0){
		return true;
	}else{
		probability = 1 - (1/1+exp(difference/(0.3*getTemperature())));
		if(rand()%10 <= probability*10){
			return true;
		}else{
			return false;
		}
	}
	
}

void SimulatedAnnealing::runSimulatedAnnealing(){
    SolutionKP aux = getCurrentSolution();
    NeighOperatorKP neigh;

    for(int i =0 ;  i<100000 ; i++){
      aux = neigh.getNeighSolution(getCurrentSolution(), getCapacity());
      if(acceptSolution(aux)){
		setCurrentSolution(aux);
	}

      if(aux.getPrice() > getBestSolution().getPrice()){
        setBestSolution(aux);
      }
      if(i%1000 == 0 ){
        freezeTemperature(i);
      }
    }
    
  }
