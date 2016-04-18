#include "InstanceKP.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>
//A function that read a file
void InstanceKP::readFile(){

	struct knapsack aux;
	std::vector<knapsack> vectorRead;
	std::ifstream file;
	std::string line;
	int nLines;

	file.open(getFileName().c_str());
	if(file.is_open()){
		//Nice
		getline(file, line, '\n');
		getline(file, line, ' ');
		getline(file, line, '\n');
		//Now we have the nLines of the file
		nLines = atoi(line.c_str());
		getline(file, line, ' ');
		getline(file, line, '\n');
		setCapacity(atoi(line.c_str()));
		for(int i=0; i<2; i++){
			getline(file, line, '\n');
		}

		//Now we can do a for, catching the elements
		for(int i=0; i<nLines; i++){
			getline(file, line, ',');
			getline(file, line, ',');
			aux.price = atoi(line.c_str());
			getline(file, line, ',');
			aux.weight = atoi(line.c_str());
			getline(file, line, '\n');

			//Now we push this data in the vector
			aux.token=false;
			vectorRead.push_back(aux);
		}

		//Everything is in the vector now :D
		file.close();
		setSolutionKP(vectorRead);
		
	}else{
		std::cout << "An error has ocurred" << std::endl;
		//WASTED
		exit(EXIT_FAILURE);
	}

};


int InstanceKP::getPrice(const std::vector<knapsack> vectorSolution){
	//Here we calculate the price of the kanpsack
	int price=0;
	for(unsigned int i=0; i<vectorSolution.size(); i++){
		if(vectorSolution[i].token == true){
			//This element is in the pack
			price += vectorSolution[i].price; 
		}
	}

	return price;
};