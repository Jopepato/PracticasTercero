#include "grasp.hpp"

using namespace std;

void Grasp::getRandomGreedy(const InstanceKP &instancia){
	//Crea un randomGreedy
	vector<knapsack> fullVector = instancia.getSolutionKP();
	vector<int> aux;
	double capacity = instancia.getCapacity();
	int percentage = fullVector.size()/10;
	double fitness = 0;
	SolGeneratorKP auxSolGen;
	int auxK;


	while(true){
		//Cogemos las soluciones random
		aux.clear();
		for(int i=0; i<percentage; i++){

			int random = rand()%fullVector.size();
			if(fullVector[random].token==false){
				aux.push_back(random);
			}else{
				i--;
			}
		}
		fitness = fullVector[aux[0]].price/fullVector[aux[0]].weight;
		//Ahora cogemos el mejor de ese vector
		for(unsigned int i=0; i<aux.size(); i++){
			if(fitness < fullVector[aux[i]].price/fullVector[aux[i]].weight){
				fitness = fullVector[aux[i]].price/fullVector[aux[i]].weight;
				auxK = i;
			}
		}

		//Comprobamos si no nos pasamos con el peso
		int weightAux = auxSolGen.getWeight(fullVector);
		if((weightAux + fullVector[aux[auxK]].weight) > capacity){
			break;
		}else{
			fullVector[aux[auxK]].token = true;
		}

	}

	SolutionKP solutionFinal(fullVector);

	setSolution(solutionFinal);
};


void Grasp::muestraElementosGrasp(){
	//Muestra los elementos de la solucion inicial por pantalla
	vector<knapsack> auxV = getSolution().getSolution();

	for(unsigned int i=0; i<auxV.size(); i++){
		if(auxV[i].token==true){
			//Imprimimos sus caracteristicas
			std::cout << "Elemento: " << i << std::endl;
			std::cout << "Precio: " << auxV[i].price << "\t" << "Peso: " << auxV[i].weight << std::endl;
		}
	}
}
