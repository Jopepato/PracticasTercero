#include "Och.hpp"
#include "SolGeneratorKP.hpp"

using namespace std;

void Och::fillPheromoneVector(const int &length){

	for(int i=0; i<length; i++){
		pheromoneVector_.push_back(getPheromone());
	}
}


void Och::fillHeuristicVector(const std::vector<knapsack> &elementos){

	for(unsigned int i=0; i<elementos.size(); i++){
		heuristicVector_.push_back(elementos[i].price/elementos[i].weight);
	}

}


void Och::refreshPheromoneVector(){

	for(unsigned int i=0; i<pheromoneVector_.size(); i++){
			pheromoneVector_[i] = (1-getVaporizePercentage())*pheromoneVector_[i] + aporteArco(i);
	}


}


double Och::aporteArco(const int &x){
	double aporte=0;
	vector<Ant> auxHormigas = getHormiguitas();
	for(unsigned int i=0; i<auxHormigas.size(); i++){
		for(unsigned int j=0; j<auxHormigas[i].solution.size(); j++){
			if(x==auxHormigas[i].solution[j].index){
				aporte += auxHormigas[i].aportePheromonas;
			}
		}//EndForJ
	}//EndForI

	return aporte;
}

knapsack Och::getNextNode(const std::vector<knapsack> &caminoHormiga){
	double probability=0;
	double sumatorioDivisor = 0;
	double sumatorioProbabilidades = 0;
	vector<double> probabilities;
	vector<int> indexes;
	//CAMBIOS
	for(unsigned int i=0; i<getOriginal().size(); i++){
		if(!isInVector(i+1, caminoHormiga)){
			//Calculamos el sumatorio que va en el divisor
			sumatorioDivisor += pow(pheromoneVector_[i], getAlpha()) * pow(heuristicVector_[i], getBeta());
		}
	}

	for(unsigned int i=0; i<getOriginal().size(); i++){
		if(!isInVector(i+1, caminoHormiga)){
			indexes.push_back(i);
			probability = pow(pheromoneVector_[i], getAlpha()) * pow(heuristicVector_[i], getBeta());
			probability = probability/sumatorioDivisor;
			probabilities.push_back(probability*1000);
		}
	}

	//Esto estaba aqui para mostrar los indices

	for(unsigned int i=0; i<probabilities.size(); i++){
		sumatorioProbabilidades += probabilities[i];
	}
	//double random = (double)rand()%sumatorioProbabilidades;
	double random = (double)rand() / RAND_MAX;
    random = random * (sumatorioProbabilidades);
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

	knapsack vuelta = original_[indexes[index]];
	vuelta.token=true;
	return vuelta;

}

//Uuuuuh :D
bool Och::isInVector(const int &x, const std::vector<knapsack> &caminoHormiga){
	for(unsigned int i=0; i<caminoHormiga.size(); i++){
		if(caminoHormiga[i].index == x){
			return true;
		}
	}
	return false;
}

void muestraCamino(vector<knapsack> camino){
	for(unsigned int i=0; i<camino.size(); i++){
		std::cout << camino[i].index << " ";
	}
	std::cout << std::endl;
}

bool cmp(double a, double b){
	if(a<b)
		return true;
	else
		return false;
}

//TODO
void Och::runAnts(int &iterations, std::string ficheroSolucionesHormigas){
	//bucle para lanzar 5 hormigas
	SolGeneratorKP generator;
	fstream myfile;
	myfile.open(ficheroSolucionesHormigas.c_str(), std::fstream::app | std::fstream::out);
	std::vector<double> vectorPriceAux;
	//CAMBIOS
	hormiguitas_.clear();
	knapsack aux;
	myfile << iterations <<  " ";
	for(int i=0;i<getNumAnt();i++){
		std::vector<knapsack> auxSolution;
		int inicio = rand()%getOriginal().size();
		aux = original_[inicio];
		aux.token = true;
		auxSolution.push_back(aux);

		while(true){
			//Empezamos en 1 porque ya tenemos un nodo metido :D
			//CAMBIOS
			aux = getNextNode(auxSolution);
			if((generator.getWeight(auxSolution) + aux.weight) < getCapacity()){
				auxSolution.push_back(aux);
			}else{	
				break;

			}
		}

		Ant auxAnt;
		auxAnt.solution=auxSolution;
		auxAnt.aportePheromonas=(generator.getPrice(auxSolution));
		vectorPriceAux.push_back(auxAnt.aportePheromonas);
		hormiguitas_.push_back(auxAnt);
		auxSolution.clear();
	}
	sort(vectorPriceAux.begin(), vectorPriceAux.end(), cmp);
	if(getNumAnt()%2==0)
		myfile << (vectorPriceAux[getNumAnt()/2]+vectorPriceAux[(getNumAnt()/2)+1] )/2;
	else
		myfile << vectorPriceAux[getNumAnt()/2];


	myfile << std::endl;
	myfile.close();
	iterations += 5;
	getBestAntSolution();
	refreshPheromoneVector();
}

void Och::getBestAntSolution(){
	double bestAporte=0;
	int bestAnt=0;
	SolGeneratorKP aux;

	for(int i=0;i<getNumAnt();i++){
		if(bestAporte < hormiguitas_[i].aportePheromonas){
			bestAporte = hormiguitas_[i].aportePheromonas;
			bestAnt=i;
		}
	}
	//CAMBIOS
	
	if(aux.getPrice(hormiguitas_[bestAnt].solution) > aux.getPrice(getBestSolution().getSolution())){
		setBestSolution(hormiguitas_[bestAnt].solution);
		muestraCamino(hormiguitas_[bestAnt].solution);
	}

}
