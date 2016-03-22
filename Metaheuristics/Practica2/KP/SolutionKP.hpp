#ifndef SOLUTIONKP_HPP_
#define SOLUTIONKP_HPP_

#include <vector>

struct knapsack{
	int price;
	int weight;
	bool token;
};

class SolutionKP{

private:
		std::vector<knapsack> vectorKnapsack_;

public:
		SolutionKP(){
			vectorKnapsack_.clear();
		}

		SolutionKP(const std::vector<knapsack> &vectorKnapsack){
			setSolution(vectorKnapsack);
		}

		inline std::vector<knapsack> getSolution()const{
			return vectorKnapsack_;
		};

		inline void setSolution(const std::vector<knapsack> &vectorKnapsack){
			vectorKnapsack_=vectorKnapsack;
		};

		inline int getWeight(){
			int result=0;
			for (unsigned int i = 0; i < vectorKnapsack_.size(); i++)
			{
			if(vectorKnapsack_[i].token==true)
				result+=vectorKnapsack_[i].weight;
			}
			return result;
		};

		inline int getPrice(){
			//Here we calculate the price of the kanpsack
			int price=0;
			for(unsigned int i=0; i<vectorKnapsack_.size(); i++){
				if(vectorKnapsack_[i].token == true){
					//This element is in the pack
					price += vectorKnapsack_[i].price; 
				}
			}

			return price;
		};
};

#endif