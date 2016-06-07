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

	for (int i = 0; i < iterations; ++i)
	{
		FINeighExploratorMDP firstImp(sol1);
		BINeighExploratorMDP bestImp(sol2);

		sol1 = firstImp.getFirstImprovement();
		sol2 = bestImp.getBestImprovement();

			dist1 = sol1.getDistancia();
			dist2 = sol2.getDistancia();

		myfile<<i<<" "<<dist1<<" "<<dist2<<std::endl;
	}
	
	return 1;
}