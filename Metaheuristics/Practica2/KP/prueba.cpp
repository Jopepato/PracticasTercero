#include "InstanceKP.hpp"
#include "SolutionKP.hpp"
#include "SolGeneratorKP.hpp"
#include <iostream>
#include <ctime>
#include <fstream>
#include "FINeighExploratorKP.hpp"
#include "BINeighExploratorKP.hpp"
#include "LocalSearchKP.hpp"

int main(int argc, char ** argv){
	std::string fileName;
	int option;
	SolutionKP sol;
	srand(time(NULL));
	int iterations;
	std::string fileNameWrite;
	std::ofstream myfile;

	//We check if the parameters are k :D
	if(argc!=3){
		//The parameters are wrong
		std::cout << "La forma de llamar al programa es:" << std::endl;
		std::cout << "'NombrePrograma' 'NombreFichero' 'NumeroIteraciones'" << std::endl;
		//We exit the program
		exit(-1);
	}else{
		fileNameWrite = argv[1];
		iterations = atoi(argv[2]);
		myfile.open(fileNameWrite.c_str());
		if(!myfile.is_open()){
			std::cout << "Error con el fichero" << std::endl;
			exit(-1);
		}
	}

	//Ask the user which one we want to read
	std::cout << "File? " << std::endl << "\t1) 200 elements" << std::endl <<"\t2) 500 elements"
	 << std::endl << "\t3) 10000 elements" << std::endl;
	std::cin >> option;
	switch(option){
		case 1:
			fileName = "knapPI_1_200_10000.csv";
			break;
		case 2:
			fileName = "knapPI_12_500_1000.csv";
			break;
		case 3:
			fileName = "knapPI_1_10000_1000000.csv";
			break;
		default:
			fileName = "knapPI_1_10000_1000000.csv";
			break;
	}

	InstanceKP instance(fileName);

	instance.readFile();


	//We generate the solutions and pass it to a file
	SolGeneratorKP generator(instance);

	std::cout << "\x1b[32mPasando a fichero...\x1b[0m" << std::endl;

	std::cout << "Las soluciones por diversificación:" << std::endl;
	for(int i=0; i<iterations; i++){

	generator.generateSol(instance);
	sol = generator.getSolutionKP();
	
	FINeighExploratorKP first(sol, instance.getCapacity());
	LocalSearchKP local(sol, instance.getCapacity());
	BINeighExploratorKP best(sol, instance.getCapacity());

	//We are gonna write the file with this format
	//'Iteration' 'priceBase' 'WeightBase' 'priceFI' 'WeightFI' 'priceBI' 'WeightBI' 'PriceLocal' 'WeightLocal'
	myfile << i << " " << sol.getPrice() << " " << sol.getWeight() << " ";
	sol = first.getFirstImprovement();
	myfile << sol.getPrice() << " " << sol.getWeight() << " ";
	sol = best.getBestImprovement();
	myfile << sol.getPrice() << " " << sol.getWeight() << " ";
	sol = local.getOptimal();
	myfile << sol.getPrice() << " " << sol.getWeight() << " " << std::endl;
	}
/*
	std::cout<<std::endl<<"*Primera mejora*"<<std::endl;
	sol = first.getFirstImprovement();
	sol.printSol();

	std::cout<<std::endl<<"*Mejor mejora*"<<std::endl;
	sol = best.getBestImprovement();
	sol.printSol();

	std::cout<<std::endl<<"*Búsqueda local*"<<std::endl;
	sol = local.getOptimal();
	sol.printSol();
*/

	//We close the file
	myfile.close();
	return 1;
}