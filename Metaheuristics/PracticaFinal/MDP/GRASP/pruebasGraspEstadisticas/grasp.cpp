#include <cstdlib>
#include <algorithm>
#include <numeric>
#include "grasp.hpp"
using namespace std;


vector<int> fillVector(const int &size){
	vector<int> aux;
	for(int i=0; i<size; i++){
		aux.push_back(i);
	}
	return aux;
}

void Grasp::getRandomGreedy(){
	//Crea un randomGreedy
	InstanceMDP instancia = getInstancia();
	vector<int> fullVector = fillVector(getInstancia().getSize());
	vector<int> aux;
	int nodoAQuitar;
	double distancia = 0.0;
	int random = rand()%fullVector.size();
	aux.push_back(fullVector[random]);
	fullVector.erase(fullVector.begin()+random);
	//Ahora vamos metiendo las mejores

	for(int i=0; i<getInstancia().getSubSize(); i++){

		for(int j=0; j<getInstancia().getSize()/10; j++){
			random = rand()%fullVector.size();
			if(getInstancia().getMatriz()[aux[i]][random] > distancia){
				distancia = getInstancia().getMatriz()[aux[i]][random];
				nodoAQuitar = random;		
			}
		}
		//Ya tenemos el vector que vamos a meter
		aux.push_back(fullVector[nodoAQuitar]);
		//cout << nodoAQuitar << endl;
		distancia= 0;
		fflush(stdout);
		fullVector.erase(fullVector.begin()+(nodoAQuitar-1));
	}

	fullVector.clear();
	fullVector.clear();
	SolutionMDP solucion(aux, getInstancia());
	setSolution(solucion);

};


void Grasp::runGraspFile(const std::string &fileName, int iterations){
	//Vamos a hacer 100000 un grasp y una primera mejora y lo guardamos en el ficher

	//Se va quedando con la mejor
	
	ofstream myfile;
	myfile.open(fileName.c_str());
	if(!myfile.is_open()){
		std::cout << "Error con el fichero" << std::endl;
		exit(-1);
	}
	int j=0;

	for(int i=0; i<iterations; i++){
		//Pilamos un greedy aleatorio cada vez
		j=i;
		FINeighExploratorMDP explorador(getSolution());
		SolutionMDP auxLocal = explorador.getFirstImprovement();

		//Iteracion PrecioGreed PesoGreed PrecioLocal PesoLocal
		myfile << i << " " << getSolution().getDistancia() << std::endl;


		//Guardamos el mejor de todas las iteraciones

		setSolution(auxLocal);
		/*if(i+1000 == j){
			//Cambiamos de greedy cada vez que no mejora
			getRandomGreedy();
		}*/
		i=j;

	}
	myfile.close();
	//Devolvemos la mejor solucion encontrada
};


void Grasp::runGrasp(){
	//Vamos a hacer 100000 un grasp y una primera mejora y lo guardamos en el ficher

	//Se va quedando con la mejor
	setBestSolution(getSolution());
	int j=0;

	for(int i=0; i<100000; i++){
		j=i;
		//Pilamos un greedy aleatorio cada vez
		FINeighExploratorMDP explorador(getSolution());
		SolutionMDP auxLocal = explorador.getFirstImprovement();
		//Guardamos el mejor de todas las iteraciones

		setSolution(auxLocal);

		if(i+1000 == j){
			//Cambiamos de greedy cada vez que no mejora
			getRandomGreedy();
		}
		i=j;

		if(getBestSolution().getDistancia() > getSolution().getDistancia()){
			setBestSolution(getSolution());
		}

	}
};

