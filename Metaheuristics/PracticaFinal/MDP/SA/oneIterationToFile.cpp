#include "InstanceMDP.hpp"
#include "SolutionMDP.hpp"
#include "SolGeneratorMDP.hpp"
#include <iostream>
#include <ctime>
#include <fstream>
#include "SimulatedAnnealing.hpp"
#include "ClaseTiempo.hpp"
#include "NeighOperatorMDP.hpp"

int main(int argc, char ** argv){

	std::string fileName;
	int option;
	SolutionMDP sol;
	srand(time(NULL));
	std::string nombreFichero;
	if(argc!=2){
		//Numero de argumentos invalido
		std::cout << "'NombrePrograma' 'Fichero'" << std::endl;
		exit(-1);
	}else{
		nombreFichero = argv[1];
	}


	//Ask the user which one we want to read
	std::cout << "File? " << std::endl << "\t1) 50 m5" << std::endl <<"\t2) 50 m15"
	 << std::endl << "\t3) 100 m10 \t4) 125 m12 \t5) 125 m37 \t6) 150 m15 \t7) 150 m45 \t8) 25 m7" << std::endl;
	std::cin >> option;
	switch(option){
		case 1:
			fileName = "GKD-b_13_n50_m5.txt";
			break;
		case 2:
			fileName = "GKD-b_17_n50_m15.txt";
			break;
		case 3:
			fileName = "GKD-b_24_n100_m10.txt";
			break;
		case 4:
			fileName = "GKD-b_31_n125_m12.txt";
			break;
		case 5:
			fileName = "GKD-b_39_n125_m37.txt";
			break;
		case 6:
			fileName = "GKD-b_44_n150_m15.txt";
			break;
		case 7:
			fileName = "GKD-b_46_n150_m45.txt";
			break;
		case 8:
			fileName = "GKD-b_6_n25_m7.txt";
			break;
		default:
			fileName = "GKD-b_6_n25_m7.txt";
			break;
	}


	InstanceMDP instance(fileName);

	instance.readFile();

	SolGeneratorMDP generator(instance);

	double media = 0.0;

	//Calculamos la media de las diferencias
	for(int i=0; i<20; i++){
		SolutionMDP sol1, sol2;
		NeighOperatorMDP neigbour;

		generator.generateSol();

		sol1 = generator.getSolutionMDP();
		sol1.setInstance(instance);
		sol2 = neigbour.getNeighSolutionOut(sol1);

		//Ahora la diferencia
		media = media + abs(sol1.getDistancia() - sol2.getDistancia());

	}
	media = media/20;


	generator.generateSol();

	sol = generator.getSolutionMDP();
	sol.setInstance(instance);

	SimulatedAnnealing simulatedAnn(sol, media);

	simulatedAnn.runSimulatedAnnealingToFile(nombreFichero);
}
