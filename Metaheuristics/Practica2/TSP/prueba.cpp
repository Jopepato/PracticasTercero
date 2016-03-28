#include "InstanceTSP.hpp"
#include "SolutionTSP.hpp"
#include "SolGeneratorTSP.hpp"
#include "FINeighExploratorTSP.hpp"
#include "BINeighExploratorTSP.hpp"
#include "LocalSearchTSP.hpp"
#include "ClaseTiempo.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char ** argv){
	std::string fileName;
	int option;
	//double optimalDistance;
	srand(time(NULL));
	int iterations;
	std::string fileNameWrite;
	std::ofstream myfile;
	Clock reloj, reloj2;

	if(argc!=3){
		std::cout << "Forma de llamar al programa incorrecta" << std::endl;
		std::cout << "'NombrePrograma' 'NombreFicheroAEscribir' 'Iteraciones'" << std::endl;
		exit(-1);
	}else{
		//The user has entered the information correctly
		fileNameWrite = argv[1];
		iterations = atoi(argv[2]);

		myfile.open(fileNameWrite.c_str());
		if(!myfile.is_open()){
			std::cout << "Fichero no ha podido ser abierto" << std::endl;
			exit(-1);
		}
		
	}
	
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

	InstanceTSP instance(fileName);

	instance.readFile();



	SolGeneratorTSP generator(instance);
	//cout the optimal distance
	//optimalDistance = generator.getDistance(instance.getSolutionTSP());
	//std::cout << "Optimal distance inside: " << optimalDistance << std::endl << std::endl;

	//We generate the solutions for the differents instances
	
	reloj2.start();
	for(int i=0; i<iterations; i++){
		generator.generateSol(instance);
		SolutionTSP sol = generator.getSolutionTSP();

		//std::cout<<std::endl<<"*Solucion Aleatoria*"<<std::endl;
		//sol.printSol();

		//Print the base solution
		//It will print the file like this
		//'Iteration' 'BaseDistance' 'DistanceFI' 'time' 'DistanceBI' 'time' 'OptimalDistance' 'time'
		myfile << i << " " << sol.getDistance() << " ";


		FINeighExploratorTSP first(sol);
		BINeighExploratorTSP best(sol);
		LocalSearchTSP local(sol);

		reloj.start();
		sol = first.getFirstImprovement();
		reloj.stop();
		myfile << sol.getDistance() << " " << reloj.elapsed() << " ";
		//std::cout << "Primera mejora" << std::endl;

		reloj.start();
		sol = best.getBestImprovement();
		reloj.stop();
		myfile << sol.getDistance() << " " << reloj.elapsed() << " ";
		//std::cout << "Mejor mejora" << std::endl;

		myfile << std::endl;

		//reloj.start();
		//sol = local.getOptimal();
		//reloj.stop();
		//myfile << sol.getDistance() << " " << reloj.elapsed() << std::endl;

		//Now we print it in the file

	}
	reloj2.stop();

	std::cout << reloj2.elapsed()/1000000 << " segundos ha tardado esto" << std::endl;


	//For printing it on the console
 
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

	return 1;
}