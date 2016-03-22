#ifndef SOLUTIONTSP_HPP_
#define SOLUTIONTSP_HPP_

#include <vector>

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
};

#endif