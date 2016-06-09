#include "InstanceMDP.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

void InstanceMDP::readFile(){
	
	std::ifstream file;
	std::string line;
	double auxNumber;
	vector< vector <double> > auxMatriz;
	int a,b;
	file.open(getFilename().c_str());
	if(file.is_open()){
		//Nice
		getline(file, line, ' ');
		setSize(atoi(line.c_str()));

		auxMatriz.resize(getSize());
		for(int i=0; i<getSize(); i++){
			auxMatriz[i].resize(getSize());
		}

		getline(file, line, '\n');
		setSubSize(atoi(line.c_str()));

		//Now we can do a for, catching the elements
		for(int i=0; i<getSize(); i++){

			for(int j=1+i; j<getSize(); j++){

				getline(file, line, '\n');
				sscanf(line.c_str(), "%i %i %lf", &a, &b, &auxNumber);
				auxMatriz[i][j] = auxNumber;
				auxMatriz[j][i] = auxNumber;

			}
			auxMatriz[i][i] = 0.0;
		}
		//Everything is in the vector now :D
		file.close();
		setMatriz(auxMatriz);

	}else{
		std::cout << "An error has ocurred" << std::endl;
		exit(EXIT_FAILURE);
	}

};

void InstanceMDP::imprimirMatriz(){
	for(int i=0; i<getSize(); i++){
		for(int j=0; j<getSize(); j++){
			cout << matrizInstancia_[i][j] << " ";
		}
		cout << endl;
	}
}