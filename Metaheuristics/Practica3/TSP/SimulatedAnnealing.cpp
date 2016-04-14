#include "SolutionTSP.hpp"
#include "SimulatedAnnealing.hpp"
#include "NeighOperatorKP.hpp"
#include <cstdlib>

void SimulatedAnnealing::freezeTemperature(const int &iteration){
	//Baja la temperatura
	setTemperature(getTemperature()*0.91);
	//setTemperature(getInitialTemperature()/1+log(1+iteration));

}

bool SimulatedAnnealing::acceptSolution(SolutionTSP &neighbour){
	//Acepta o no? :D
	double difference = getCurrentSolution().getDistance() - neighbour.getDistance();
	double probability = 0;
	if(difference > 0){
		return true;
	}else{
		probability = 1-1/(1+exp((-1.0)*difference/(0.3*getTemperature())));
		//std::cout<<"P = "<<probability*10<<std::endl;
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
    SolutionTSP aux = getCurrentSolution();
    NeighOperatorKP neigh;

    for(int i =0 ;  i<100000 ; i++){
      aux = neigh.getNeighSolution(getCurrentSolution());
      if(acceptSolution(aux)){
		setCurrentSolution(aux);
	  }

      if(aux.getDistance() < getBestSolution().getDistance()){
        setBestSolution(aux);
      }
      if(i%1000 == 0 ){
        freezeTemperature(i);
      }

    }
    
  }


void SimulatedAnnealing::runSimulatedAnnealingToFile(const std::string &filename){
    SolutionTSP aux = getCurrentSolution();
    NeighOperatorKP neigh;
    std::ofstream file;
    file.open(filename.c_str());

    for(int i =0 ;  i<100000 ; i++){
      aux = neigh.getNeighSolution(getCurrentSolution());
      if(acceptSolution(aux)){
		setCurrentSolution(aux);
	  }

      if(aux.getDistance() < getBestSolution().getDistance()){
        setBestSolution(aux);
      }

      file<<i<<" "<<getTemperature()<<" "<< getBestSolution().getDistance()<< " " <<getCurrentSolution().getDistance()<<std::endl;

      if(i%1000 == 0 ){
        freezeTemperature(i);
      }

    }
    
  }
