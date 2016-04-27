#include "Och.hpp"

void Och::fillMatrix(const int &length){
	vector<double> aux;

	for(unsigned int i=0; i<length; i++){
		for(unsigned int j=0; j<length; j++){
			if(i==j){
				aux.push_back(0);
			}else{
				aux.push_back(getPheromone());
			}
		}
		pheromoneMatrix_.push_back(aux);
		aux.clear();
	}
}


void Och::fillDistanceMatrix(const std::vector<node> &nodes){
	std::vector<double> distanceVector;
	double distance;
	std::vector<double> heuristicVector;
	for(unsigned int i=0; i<nodes.size(); i++){
		for(unsigned int j=0; j<nodes.size(); j++){

			if(i==j){
				distanceVector.push_back(std::numeric_limits<double>::infinity());
			}else{
				//Calculamos la distancias
				distance = sqrt( pow( (nodes[i].x - nodes[j].x) ,2) + pow( (nodes[i].y - nodes[j].y) ,2));
				distanceVector.push_back(distance);
				heuristicVector.push_back(1/distance);
			}
		}
		//Metemos los vectores en la matriz :D
		distanceMatrix_.push_back(distanceVector);
		distanceVector.clear();
		heuristicMatrix_.push_back(heuristicVector);
		heuristicVector.clear();
	}

}


void Och::refreshPheromoneMatrix(){

	for(unsigned int i=0; i<pheromoneMatrix_.size(); i++){
		for(unsigned int j=0; j<pheromoneMatrix_[i].size(); j++){
			if(i!=j){
				pheromoneMatrix_[i][j] = (1-getVaporizePercentage())*pheromoneMatrix_[i][j] + aporteArco(i,j);
			}
		}
	}


}


double Och::aporteArco(const int &x, const int &y){
	double aporte=0;
	vector<Ant> auxHormigas = getHormiguitas();
	for(unsigned int i=0; i<auxHormigas.size(); i++){

		for(unsigned int j=0; j<auxHormigas[i].solution.size(); j++){
			if(j==auxHormigas[i].solution.size()-1){
				if(auxHormigas[i].solution[j].index== x && (auxHormigas[i].solution[j-1].index == y || auxHormigas[i].solution[0].index == y) ){
					aporte += auxHormigas[i].aportePheromonas;
				}

			}else{
				if(j==0){
					if(auxHormigas[i].solution[j].index== x && (auxHormigas[i].solution[auxHormigas[i].solution.size()-1].index == y || auxHormigas[i].solution[j+1].index == y)){
						aporte +=auxHormigas[i].aportePheromonas;
					}
				}else{
					if(auxHormigas[i].solution[j].index== x && (auxHormigas[i].solution[j-1].index == y || auxHormigas[i].solution[j+1].index == y) ){
						aporte += auxHormigas[i].aportePheromonas;
					}
				}
			}
			
		}//EndForJ
	}//EndForI

	return aporte;
}

node Och::getNextNode(const int &x, const std::vector<node> &caminoHormiga){
	double probability=0;
	double sumatorioDivisor = 0;
	double sumatorioProbabilidades = 0;
	vector<double> probabilities;
	vector<int> indexes;


	for(unsigned int i=0; i<getOriginal().size(); i++){
		if(!isInVector(i, caminoHormiga)){
			//Calculamos el sumatorio que va en el divisor
			sumatorioDivisor += pow(pheromoneMatrix_[x][i], getAlpha()) * pow(heuristicMatrix_[x][i], getBeta());
		}
	}

	for(unsigned int i=0; i<getOriginal().size(); i++){
		if(!isInVector(i, caminoHormiga)){
			indexes.push_back(i);
			probability = pow(pheromoneMatrix_[x][i], getAlpha()) * pow(heuristicMatrix_[x][i], getBeta());
			probability = probability/sumatorioDivisor;
			probabilities.push_back(probability*1000);
		}
	}

	for(unsigned int i=0; i<probabilities.size(); i++){
		sumatorioProbabilidades += probabilities[i];
	}

	double random = rand()%sumatorioProbabilidades;
	double suma=0;
	int index=0;
	do{
		//TO DO
		suma += probabilities[index];
		index++;
		//WARNING!
	}while(suma<random);

	return original_[index];

}

bool isInVector(const int &x, const std::vector<node> &caminoHormiga){
	for(unsigned int i=0; i<caminoHormiga.size(); i++){
		if(caminoHormiga[i].index==x){
			return true;
		}
	}
	return false;
}


//TODO
void Och::runAnts(){



}