#include "Och.hpp"
#include "SolGeneratorTSP.hpp"

using namespace std;

void Och::fillMatrix(const int &length){
	vector<double> aux;

	for(int i=0; i<length; i++){
		for(int j=0; j<length; j++){
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


void Och::fillDistanceAndHeuristicMatrix(const std::vector<node> &nodes){
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
					if(auxHormigas[i].solution[j].index == x && (auxHormigas[i].solution[auxHormigas[i].solution.size()-1].index == y || auxHormigas[i].solution[j+1].index == y)){
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
	double sumatorioDivisor = 0.1;
	double sumatorioProbabilidades = 0;
	vector<double> probabilities;
	vector<int> indexes;
	//CAMBIOS
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

/*
	double lower_bound = 0;
	double upper_bound = sumatorioProbabilidades;
	std::uniform_real_distribution<double> unif(lower_bound,upper_bound);
	std::default_random_engine re;
	double random = unif(re);
*/
	
	double random = (double)rand() / RAND_MAX;
    random = random * (sumatorioProbabilidades);

	//std::cout<<"random ="<<random<<std::endl;
	//std::cout<<"sumatorioProbabilidades= "<<sumatorioProbabilidades<<std::endl;

	double suma=0;
	int index=0;
	
	//Vamos a hacer la ruleta
		for(unsigned int i=0; i<probabilities.size(); i++){
			suma += probabilities[i];
			if(suma >= random){
				break;
			}else{
				index++;
			}
		}


	return original_[indexes[index]];

}

bool Och::isInVector(const int &x, const std::vector<node> &caminoHormiga){
	for(unsigned int i=0; i<caminoHormiga.size(); i++){
		if(caminoHormiga[i].index == x){
			return true;
		}
	}
	return false;
}


void Och::imprimeCamino(const std::vector<node> &primero, const std::vector<node> &segundo, std::string nombreFicheroCaminos){

	ofstream myfile;
	myfile.open(nombreFicheroCaminos.c_str());
	//Muestra el camino de la hormiga
	for(unsigned int i=0; i<primero.size(); i++){
		myfile << primero[i].x << " " << primero[i].y << " " << segundo[i].x << " " << segundo[i].y << std::endl;
	}
}

//TODO
void Och::runAnts(int &iterations, std::string ficheroSolucionesHormigas){
	//bucle para lanzar 5 hormigas
	SolGeneratorTSP generator;
	fstream myfile;
	myfile.open(ficheroSolucionesHormigas.c_str(), std::fstream::app | std::fstream::out);
	//CAMBIOS
	hormiguitas_.clear();
	myfile << iterations;
	for(int i=0;i<getNumAnt();i++){
		std::vector<node> auxSolution;
		int inicio = rand()%getOriginal().size();
		auxSolution.push_back(original_[inicio]);
		for(unsigned int j=1; j < getOriginal().size() ;j++){
			//Empezamos en 1 porque ya tenemos un nodo metido :D
			//CAMBIOS
			auxSolution.push_back(getNextNode(auxSolution.back().index,auxSolution));
		}
		Ant auxAnt;
		auxAnt.solution=auxSolution;
		auxAnt.aportePheromonas=1000000/(generator.getDistance(auxSolution));
		auxAnt.distancia=generator.getDistance(auxSolution);
		myfile << " " << auxAnt.distancia;
		hormiguitas_.push_back(auxAnt);
		auxSolution.clear();
	}
	myfile << std::endl;
	iterations += 5;
	getBestAntSolution();
	refreshPheromoneMatrix();
}

void Och::getBestAntSolution(){
	double bestAporte=0;
	int bestAnt=0;
	SolGeneratorTSP aux;

	for(int i=0;i<getNumAnt();i++){
		if(bestAporte<hormiguitas_[i].aportePheromonas){
			bestAporte=hormiguitas_[i].aportePheromonas;
			bestAnt=i;
		}
	}
	//CAMBIOS
	if(aux.getDistance(hormiguitas_[bestAnt].solution) < aux.getDistance(getBestSolution().getSolution()) ){
		setBestSolution(hormiguitas_[bestAnt].solution);
	}
}
