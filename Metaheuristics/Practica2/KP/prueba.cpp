#include "InstanceKP.hpp"
#include "SolutionKP.hpp"
#include "SolGeneratorKP.hpp"
#include <iostream>

#include "FINeighExploratorKP.hpp"
#include "BINeighExploratorKP.hpp"
#include "LocalSearchKP.hpp"

int main(){
	std::string fileName;
	int option;
	SolutionKP sol;


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

	SolGeneratorKP generator(instance);
	generator.generateSol(instance);
	sol = generator.getSolutionKP();
	
	FINeighExploratorKP fifiu (sol, instance.getCapacity() );
	LocalSearchKP loloko ( sol, instance.getCapacity() );
	BINeighExploratorKP bibifidus (sol, instance.getCapacity());

	sol = fifiu.getFirstImprovement();
	sol.printSol();

	sol = loloko.getOptimal();
	sol.printSol();

	sol = bibifidus.getBestImprovement();
	sol.printSol();
	

	return 1;
}