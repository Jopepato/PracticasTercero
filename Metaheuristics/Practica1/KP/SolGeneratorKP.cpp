#include "SolGeneratorKP.hpp"

	void SolGeneratorKP::printSol(const vector<knapsack> &v){
		//This prints the vector


	}
	bool SolGeneratorKP::compareSol(const vector<knapsack> &v, const int &weigth){
		return (getWeight(v)<=weight);
	}
	void SolGeneratorKP::generateSol(const vector<knapsack> &v, const int &weight){
		bool exit=false;
		vector<knapsack> aux = v;
		int index;
		srand(time(NULL));

		for (int i = 0; i < 1000; ++i)
		{
			exit=false;
			aux = v;
			while(exit!=true){
				index = rand()%v.size();
				if(aux[index].token==false){
					aux[index].token=true;
				}
				if (compareSol(aux, weight)==false)
				{
					aux[index].token=false;
					exit=true;
				}
			}
		}
	}

	int SolGeneratorKP::getWeight(const vector<knapsack> &v){
		int result;
		for (int i = 0; i < v.size(); ++i)
		{
			if(v[i].token==true)
				result+=v[i].weight;
		}
		return result;
	};
