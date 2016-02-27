#include "InstanceTSP.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>


void InstanceTSP::readFile(){
	
	struct node aux;
	std::vector<node> vectorRead;
	std::ifstream file;
	std::string line;
	int nLines;

	file.open(getFilename().c_str());
	if(file.is_open()){
		//Nice
		getline(file, line, '\n');
		getline(file, line, '\n');
		getline(file, line, '\n');
		getline(file, line, ' ');
		getline(file, line, '\n');
		//Now we have the nLines of the file
		nLines = atoi(line.c_str());
		getline(file, line, '\n');
		getline(file, line, '\n');
		
		//Now we can do a for, catching the elements
		for(int i=0; i<nLines; i++){
			getline(file, line, ' ');
			getline(file, line, ' ');
			aux.x = atof(line.c_str());
			getline(file, line, '\n');
			aux.y = atof(line.c_str());

			//Now we push this data in the vector
			vectorRead.push_back(aux);
		}

		//Everything is in the vector now :D
		file.close();
		setSolutionTSP(vectorRead);
		
	}else{
		std::cout << "An error has ocurred" << std::endl;
		//WASTED
		exit(EXIT_FAILURE);
	}

};