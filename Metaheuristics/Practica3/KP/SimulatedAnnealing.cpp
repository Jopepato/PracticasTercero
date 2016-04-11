#include "SolutionKP.hpp"


void SimulatedAnnealing::freezeTemperature(const int &iteration){
	//Baja la temperatura
	setTemperature(getInitialTemperature()/(1+log(1+iteration)));
}

void SimulatedAnnealing::runSimulatedAnnealing(){
    SolutionKP aux = getCurrentSolution();
    NeighOperatorKP neigh;

    for(int i =0 ;  i<100000 ; i++){
      aux = neigh.getNeighSolution(getCurrentSolution(), getCapacity());
      if( aux.getPrice() > getCurrentSolution().getPrice()){
        setCurrentSolution(aux);

      }else{
        if( acceptSolution(aux) ){
          setCurrentSolution(aux);
        }
      }

      if(aux.getPrice() > getBestSolution().getPrice()){
        setBestSolution(aux);
      }
      if(i%1000 == 0 ){
        freezeTemperature(i);
      }
    }
    
  }
