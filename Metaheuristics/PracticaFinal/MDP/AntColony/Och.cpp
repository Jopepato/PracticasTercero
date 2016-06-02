#include "Och.hpp"
#include "SolGeneratorMDP.hpp"

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
		for(unsigned int j=0; j<auxHormigas[i].solution.size()-1; j++){
			if( (auxHormigas[i].solution[j]== x && auxHormigas[i].solution[j+1] == y) || (auxHormigas[i].solution[j+1] == x && auxHormigas[i].solution[j] == y) ){		
				aporte += auxHormigas[i].aportePheromonas;
			}
		}//EndForJ
	}//EndForI

	return aporte;
}

int Och::getNextNode(const int &x, const std::vector<int> &caminoHormiga){
	double probability=0;
	double sumatorioDivisor = 0.1;
	double sumatorioProbabilidades = 0;
	vector<double> probabilities;
	vector<int> indexes;
	//CAMBIOS
	for(int i=0; i<getInstance().getSize(); i++){
		if(!isInVector(i, caminoHormiga)){
			//Calculamos el sumatorio que va en el divisor
			sumatorioDivisor += pow(pheromoneMatrix_[x][i], getAlpha()) * pow(getInstance().getMatriz()[x][i], getBeta());
		}
	}
	for(int i=0; i<getInstance().getSize(); i++){
		if(!isInVector(i, caminoHormiga)){
			indexes.push_back(i);
			probability = pow(pheromoneMatrix_[x][i], getAlpha()) * pow(getInstance().getMatriz()[x][i], getBeta());
			probability = probability/sumatorioDivisor;
			probabilities.push_back(probability);
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


	return indexes[index];

}

bool Och::isInVector(const int &x, const std::vector<int> &caminoHormiga){
	for(unsigned int i=0; i<caminoHormiga.size(); i++){
		if(caminoHormiga[i] == x){
			return true;
		}
	}
	return false;
}


void Och::imprimeCamino(const std::vector<int> &primero, const std::vector<int> &segundo, std::string nombreFicheroCaminos){

	fstream myfile;
	myfile.open(nombreFicheroCaminos.c_str(), std::fstream::out);
	//Muestra el camino de la hormiga
	for(unsigned int i=0; i<primero.size(); i++){
		myfile << primero[i] << " " << segundo[i]<< std::endl;
	}

	myfile.close();
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
	fstream myfile;
	myfile.open(ficheroSolucionesHormigas.c_str(), std::fstream::app | std::fstream::out);
	std::vector<double> distAux;
	//CAMBIOS
	hormiguitas_.clear();
	myfile << iterations<< " ";

	for(int i=0;i<getNumAnt();i++){
		std::vector<int> auxSolution;
		int inicio = rand()%getInstance().getSize();
		auxSolution.push_back(inicio);
		for(int j=1; j < getInstance().getSubSize() ;j++){
			//Empezamos en 1 porque ya tenemos un nodo metido :D
			//CAMBIOS
			auxSolution.push_back(getNextNode(auxSolution.back() ,auxSolution));
		}
		Ant auxAnt;
		SolutionMDP sol(auxSolution, getInstance());
		auxAnt.solution=auxSolution;
		auxAnt.aportePheromonas=sol.getDistancia();
		auxAnt.distancia=sol.getDistancia();
		distAux.push_back(auxAnt.distancia);
		hormiguitas_.push_back(auxAnt);
		auxSolution.clear();
	}
	sort(distAux.begin(), distAux.end(), cmp);
	if(getNumAnt()%2==0)
		myfile << (distAux[getNumAnt()/2]+distAux[(getNumAnt()/2)+1] )/2<<std::endl;
	else
		myfile << distAux[getNumAnt()/2]<<std::endl;
	iterations += getNumAnt();
	getBestAntSolution();
	refreshPheromoneMatrix();
}

void Och::getBestAntSolution(){
	double bestAporte=0;
	int bestAnt=0;

	for(int i=0;i<getNumAnt();i++){
		if(bestAporte<hormiguitas_[i].aportePheromonas){
			bestAporte=hormiguitas_[i].aportePheromonas;
			bestAnt=i;
		}
	}
	//CAMBIOS
	if(getBestSolution().getSolution().empty()){
		setBestSolution(hormiguitas_[bestAnt].solution);
	}else{
		SolutionMDP sol(hormiguitas_[bestAnt].solution, getInstance());
		if(sol.getDistancia() > getBestSolution().getDistancia() ){
			setBestSolution(hormiguitas_[bestAnt].solution);
		}
	}
}
