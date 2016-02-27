#include "SolGeneratorTSP.hpp"
#include <iostream>
#include <math.h>


	void SolGeneratorTSP::generateSol(InstanceTSP instancia){
		
		bool exit=false;
		std::vector<node> aux = instancia.getSolutionTSP();
		std::vector<node> path;
		struct node nodeBegin, nodeEnd, nodeAux;
		int index, elem;

		nodeBegin = aux[0];
		nodeEnd = aux[aux.size()-1];
		for (int i = 0; i < 1000; ++i)
		{
			exit=false;
			aux = instancia.getSolutionTSP();
			aux.erase(aux.begin());
			aux.erase(aux.end()-1);
			path.clear();
			path.push_back(nodeBegin);
			while(exit!=true){
				elem = aux.size();
				index = rand()%elem;
				nodeAux = aux[index];
				aux.erase(aux.begin()+index);
				path.push_back(nodeAux);
				if (aux.empty())
				{
					exit=true;
				}
			}
			path.push_back(nodeEnd);
			if(getDistance(path)<getDistance()){
				std::cout << std::endl << "Iteration " << i;
				setSolutionTSP(path);
				setDistance(getDistance(path));
				std::cout << std::endl << "Total distance: " << getDistance() << std::endl;
			}
		}
	}

	double SolGeneratorTSP::getDistance(const std::vector<node> &v){
		double result=0.0;
		for (unsigned int i = 0; i < v.size()-1; i++)
		{
			result += sqrt( pow( (v[i+1].x - v[i].x) ,2) + pow( (v[i+1].y - v[i].y) ,2) );
		}

		result += sqrt( pow( (v[0].x - v[v.size()-1].x) ,2) + pow( (v[0].y - v[v.size()-1].y) ,2) );

		return result;
	};