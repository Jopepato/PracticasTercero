#include "grasp.hpp"
#include <cstdlib>
using namespace std;

void Grasp::getRandomGreedy(){
	//Crea un randomGreedy
	InstanceKP instancia = getInstancia();
	vector<knapsack> fullVector = instancia.getSolutionKP();
	vector<int> aux;
	double capacity = instancia.getCapacity();
	int percentage = fullVector.size()/10;
	double fitness = 0;
	SolGeneratorKP auxSolGen;
	int auxK = 0;
	double sumatorioAux = 0;
	double weightAux = 0;
	int random = 0;

	while(true){
		//Cogemos las soluciones random
		aux.clear();

		for(int i=0; i<percentage; i++){

			random = rand()%fullVector.size();
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
				auxK = aux[i];
			}
		}

		//Comprobamos si no nos pasamos con el peso
		weightAux = auxSolGen.getWeight(fullVector);
		sumatorioAux = weightAux + fullVector[auxK].weight;
		if( sumatorioAux > capacity){
			break;
		}else{
			fullVector[auxK].token = true;
		}

		
	}

	aux.clear();
	SolutionKP solutionFinal(fullVector);
	fullVector.clear();
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
};


SolutionKP Grasp::runGraspFile(const std::string &fileName){
	//Vamos a hacer 100000 un grasp y una primera mejora y lo guardamos en el ficher

	//Se va quedando con la mejor
	SolutionKP aux = getSolution();
	
	ofstream myfile;
	myfile.open(fileName.c_str());
	if(!myfile.is_open()){
		std::cout << "Error con el fichero" << std::endl;
		exit(-1);
	}
	int j=0;

	for(int i=0; i<100000; i++){
		//Pilamos un greedy aleatorio cada vez
		j=i;
		FINeighExploratorKP explorador(getSolution(), getInstancia().getCapacity());
		SolutionKP auxLocal = explorador.getFirstImprovement(j);

		//Iteracion PrecioGreed PesoGreed PrecioLocal PesoLocal
		myfile << i << " " << getSolution().getPrice() << " " << getSolution().getWeight() << " " << auxLocal.getPrice() << " " << auxLocal.getWeight() << std::endl;


		//Guardamos el mejor de todas las iteraciones

		setSolution(auxLocal);
		if(i+1000 == j){
			//Cambiamos de greedy cada vez que no mejora
			getRandomGreedy();
		}
		i=j;

	}
	myfile.close();
	//Devolvemos la mejor solucion encontrada
	return aux;
};


void Grasp::runGrasp(){
	//Vamos a hacer 100000 un grasp y una primera mejora y lo guardamos en el ficher

	//Se va quedando con la mejor
	setBestSolution(getSolution());
	int j=0;

	for(int i=0; i<100000; i++){
		j=i;
		//Pilamos un greedy aleatorio cada vez
		FINeighExploratorKP explorador(getSolution(), getInstancia().getCapacity());
		SolutionKP auxLocal = explorador.getFirstImprovement(j);
		//Guardamos el mejor de todas las iteraciones

		setSolution(auxLocal);

		if(i+1000 == j){
			//Cambiamos de greedy cada vez que no mejora
			getRandomGreedy();
		}
		i=j;

		if(getBestSolution().getPrice() < getSolution().getPrice()){
			setBestSolution(getSolution());
		}

	}
};