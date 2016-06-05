#include <iostream>
#include "InstanceMDP.hpp"
#include "SolGeneratorMDP.hpp"
#include "BINeighExploratorMDP.hpp"
#include "FINeighExploratorMDP.hpp"
#include "NeighOperatorMDP.hpp"
#include <fstream>

int main(int argc, char ** argv){
	std::string fileName;
	std::ofstream myfile;
	int iterations;
	std::string fileNameWrite;
	int option;
	srand(time(NULL));

	//Metemos por comandos el numero de iteraciones y el fichero de los datos
	if(argc!=3){
		std::cout << "Comandos mal" << std::endl;
		std::cout << "Programa iteraciones ficheroSalida" << std::endl;
		exit(-1);
	}else{
		iterations = atoi(argv[1]);
		fileNameWrite = argv[2];
	}
	

	//Ask the user which one we want to read
	std::cout << "File? " << std::endl << "\t1) 50 " << std::endl <<"\t2) 100 "
	 << std::endl << "\t3) 150 " << std::endl;
	std::cin >> option;
	switch(option){
		case 1:
			fileName = "GKD-b_19_n50_m15.txt";
			break;
		case 2:
			fileName = "GKD-b_30_n100_m30.txt";
			break;
		case 3:
			fileName = "GKD-b_46_n150_m45.txt";
			break;
		default:
			fileName = "GKD-b_30_n100_m30.txt";
			break;
	}

	myfile.open(fileNameWrite.c_str());
		if(!myfile.is_open()){
			std::cout << "Fichero no ha podido ser abierto" << std::endl;
			exit(-1);
	}

	InstanceMDP instance(fileName);

	instance.readFile();

	SolGeneratorMDP solgen(instance);
	NeighOperatorMDP neighbor;

	solgen.generateSol();

	SolutionMDP sol1, sol2;
	double dist1=0.0, dist2=0.0;

	sol1 = solgen.getSolutionMDP();
	sol2 = sol1;

	int cont1=0, cont2=0;

	for (int i = 0; i < iterations; ++i)
	{
		FINeighExploratorMDP firstImp(sol1);
		BINeighExploratorMDP bestImp(sol2);

		sol1 = firstImp.getFirstImprovement();
		sol2 = bestImp.getBestImprovement();

		//if(sol1.getDistancia()>dist1){
			cont1=0;
			//sol1.printSol();		
			dist1 = sol1.getDistancia();
		/*}else{
			cont1++;
			if (cont1>=10)
				for (int i = 0; i < 5; ++i)
					sol1 = neighbor.getNeighSolutionOut(sol1);

		}*/

		//if(sol2.getDistancia()>dist2){
			cont2=0;
			//sol2.printSol();
			dist2 = sol2.getDistancia();
		/*}else{
			cont2++;
			if (cont2>=10)
				for (int i = 0; i < 5; ++i)
					sol2 = neighbor.getNeighSolutionOut(sol2);

		}*/
		myfile<<i<<" "<<dist1<<" "<<dist2<<std::endl;
	}
	
	return 1;
}