#include <iostream>
#include "InstanceMDP.hpp"
#include "SolGeneratorMDP.hpp"
#include "BINeighExploratorMDP.hpp"
#include "FINeighExploratorMDP.hpp"
#include "NeighOperatorMDP.hpp"
#include <fstream>

int main(){
	std::string fileName, saveFile;
	std::ofstream myfile;
	srand(time(NULL));

	
	/*
	//Ask the user which one we want to read
	std::cout << "File? " << std::endl << "\t1) 52 nodes" << std::endl <<"\t2) 150 nodes"
	 << std::endl << "\t3) 2103 nodes" << std::endl;
	std::cin >> option;
	switch(option){
		case 1:
			fileName = "berlin52.tsp";
			break;
		case 2:
			fileName = "ch150.tsp";
			break;
		case 3:
			fileName = "d2103.tsp";
			break;
		default:
			fileName = "berlin52.tsp";
			break;
	}
*/
	fileName = "GKD-a_9_n10_m3.txt";
	saveFile = "output.txt";

	myfile.open(saveFile.c_str());
		if(!myfile.is_open()){
			std::cout << "Fichero no ha podido ser abierto" << std::endl;
			exit(-1);
	}

	InstanceMDP instance(fileName);

	instance.readFile();
	instance.imprimirMatriz();

	SolGeneratorMDP solgen(instance);
	NeighOperatorMDP neighbor;

	solgen.generateSol();

	SolutionMDP sol1, sol2;
	double dist1=0.0, dist2=0.0;

	sol1 = solgen.getSolutionMDP();
	sol2 = sol1;

	int cont1=0, cont2=0;

	for (int i = 0; i < 1000; ++i)
	{
		FINeighExploratorMDP firstImp(sol1);
		BINeighExploratorMDP bestImp(sol2);

		sol1 = firstImp.getFirstImprovement();
		sol2 = bestImp.getBestImprovement();

		if(sol1.getDistancia()>dist1){
			cont1=0;
			sol1.printSol();		
			dist1 = sol1.getDistancia();
			std::cout<<"--->"<<i<<" Iter - First Distancia---> "<< dist1<< std::endl;
		}else{
			cont1++;
			if (cont1>=10)
				for (int i = 0; i < 5; ++i)
					sol1 = neighbor.getNeighSolutionOut(sol1);

		}

		if(sol2.getDistancia()>dist2){
			cont2=0;
			sol2.printSol();
			dist2 = sol2.getDistancia();
			std::cout<<"--->"<<i<<" Iter - Best Distancia---> "<< dist2<< std::endl;
		}else{
			cont2++;
			if (cont2>=10)
				for (int i = 0; i < 5; ++i)
					sol2 = neighbor.getNeighSolutionOut(sol2);

		}
		myfile<<i<<" "<<dist1<<" "<<dist2<<std::endl;
	}
	
	return 1;
}