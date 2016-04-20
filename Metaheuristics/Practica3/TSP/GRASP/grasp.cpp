#include "grasp.hpp"
#include <cstdlib>
using namespace std;

void Grasp::getRandomGreedy(){
	//Crea un randomGreedy
	InstanceTSP instancia = getInstancia();
	vector<node> fullVector = getInstancia().getSolutionTSP();
	vector<node> aux;
	double distancia = 0;
	int nodoAQuitar;
	int random = rand()%fullVector.size();
	aux.push_back(fullVector[random]);
	fullVector.erase(fullVector.begin()+random);
	int size = fullVector.size();
	//Ahora vamos metiendo las mejores

	for(int i=0; i<size; i++){

		for(int j=0; j<size/10; j++){
			random = rand()%fullVector.size();
			if(j==0){
				distancia = getDistanciaNodos(aux[i], fullVector[random]);
				nodoAQuitar = random;
			}else if(getDistanciaNodos(aux[i], fullVector[random]) < distancia){
				distancia = getDistanciaNodos(aux[i], fullVector[random]);
				nodoAQuitar = random;		
			}
		}

		//Ya tenemos el vector que vamos a meter
		aux.push_back(fullVector[nodoAQuitar]);
		fullVector.erase(fullVector.begin()+nodoAQuitar);
	}

	SolutionTSP solucion(aux);
	setSolution(solucion);

};

double Grasp::getDistanciaNodos(node n1, node n2){
	return sqrt(pow(n1.x - n2.x, 2) + pow(n1.y - n2.y, 2));
}


void Grasp::runGraspFile(const std::string &fileName){
	//Vamos a hacer 100000 un grasp y una primera mejora y lo guardamos en el ficher

	//Se va quedando con la mejor
	
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
		FINeighExploratorTSP explorador(getSolution());
		SolutionTSP auxLocal = explorador.getFirstImprovement(j);

		//Iteracion PrecioGreed PesoGreed PrecioLocal PesoLocal
		myfile << i << " " << getSolution().getDistance() << " " << auxLocal.getDistance() << std::endl;


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
};


void Grasp::runGrasp(){
	//Vamos a hacer 100000 un grasp y una primera mejora y lo guardamos en el ficher

	//Se va quedando con la mejor
	setBestSolution(getSolution());
	int j=0;

	for(int i=0; i<100000; i++){
		j=i;
		//Pilamos un greedy aleatorio cada vez
		FINeighExploratorTSP explorador(getSolution());
		SolutionTSP auxLocal = explorador.getFirstImprovement(j);
		//Guardamos el mejor de todas las iteraciones

		setSolution(auxLocal);

		if(i+1000 == j){
			//Cambiamos de greedy cada vez que no mejora
			getRandomGreedy();
		}
		i=j;

		if(getBestSolution().getDistance() > getSolution().getDistance()){
			setBestSolution(getSolution());
		}

	}
};