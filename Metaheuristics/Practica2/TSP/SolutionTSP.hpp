#ifndef SOLUTIONTSP_HPP_
#define SOLUTIONTSP_HPP_

#include <vector>
#include <iostream>
#include <cmath>

struct node{
	double x;
	double y;
};

class SolutionTSP{

private:
		std::vector<node> vectorNode_;

public:
		SolutionTSP(){
			vectorNode_.clear();
		}

		SolutionTSP(const std::vector<node> &vectorNode){
			setSolution(vectorNode);
		}

		inline std::vector<node> getSolution()const{
			return vectorNode_;
		};

		inline void setSolution(const std::vector<node> &vectorNode){
			vectorNode_=vectorNode;
		};

		inline double getDistance(){
			double result=0.0;
			for (unsigned int i = 0; i < vectorNode_.size()-1; i++)
			{
				result += sqrt( pow( (vectorNode_[i+1].x - vectorNode_[i].x) ,2) + pow( (vectorNode_[i+1].y - vectorNode_[i].y) ,2) );
			}

			result += sqrt( pow( (vectorNode_[0].x - vectorNode_[vectorNode_.size()-1].x) ,2) + pow( (vectorNode_[0].y - vectorNode_[vectorNode_.size()-1].y) ,2) );

			return result;
		};

		inline void printSol(){
			std::cout<<"Distancia -> "<<getDistance()<<std::endl;
		};
};

#endif