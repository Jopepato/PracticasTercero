#include <iostream>
#include <fstream>
#include "InstanceMDP.hpp"
#include "SolGeneratorMDP.hpp"

int main(int argc, char ** argv){
	std::string fileName;
	srand(time(NULL));
	std::string fileNameWrite;
	int iterations;
	std::ofstream myfile;
	int option;

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


	InstanceMDP instance(fileName);

	instance.readFile();
	SolGeneratorMDP solgen(instance);
	myfile.open(fileNameWrite.c_str());
	solgen.generateSol();
	SolutionMDP sol(solgen.getSolutionMDPVector(), instance);
	SolutionMDP solBest(solgen.getSolutionMDPVector(), instance);

	std::cout << "Pasando a fichero" << std::endl;
	
	for(int i=0; i<iterations; i++){
	
		if(sol.getDistancia() > solBest.getDistancia()){
			solBest.setSolution(sol.getSolution());
		}
	
		myfile << i << " " << sol.getDistancia() << " " << solBest.getDistancia() << std::endl;
		solgen.generateSol();
		sol.setSolution(solgen.getSolutionMDPVector());
	}

	return 1;
}