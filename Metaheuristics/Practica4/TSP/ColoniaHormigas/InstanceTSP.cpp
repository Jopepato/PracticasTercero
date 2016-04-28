#include "InstanceTSP.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cmath>


void InstanceTSP::readFile(){
	
	struct node aux;
	std::vector<node> vectorRead;
	std::ifstream file;
	std::string line;
	std::size_t found;
	std::size_t length;
	float auxNumber;
	char buffer[20];
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
			aux.index = atoi(line.c_str()) -1;
			getline(file, line, ' ');
			//We check for an e
			found = line.find('e');
			if(found != std::string::npos){
				//We have found an e
				length = line.copy(buffer, found-1, 0);
				buffer[length] = '\0';
				auxNumber = atof(buffer);
				length = line.copy(buffer, found+1, line.length());
				buffer[length] = '\0';
				pow(auxNumber, atoi(buffer));
				aux.x = auxNumber;

			}else{
				//We haven't found and 'e' so we continue as usual
				aux.x = atof(line.c_str());
			}

			//Now we hcve to do it for the component y
			getline(file, line, '\n');
			found = line.find("e");
			if(found != std::string::npos){
				//We have found an e
				length = line.copy(buffer, found-1, 0);
				buffer[length] = '\0';
				auxNumber = atof(buffer);
				length = line.copy(buffer, found+1, line.length());
				buffer[length] = '\0';
				pow(auxNumber, atoi(buffer));
				aux.y = auxNumber;
				
			}else{
				//We haven't found and 'e' so we continue as usual
				aux.y = atof(line.c_str());
			}

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