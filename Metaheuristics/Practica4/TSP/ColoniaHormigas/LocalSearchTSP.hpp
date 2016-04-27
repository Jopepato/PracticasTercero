#ifndef LOCAL_SEARCH_TSP_
#define LOCAL_SEARCH_TSP_

#include "SolutionTSP.hpp"

class LocalSearchTSP{

	private:
		SolutionTSP sol_;

	public:

		LocalSearchTSP(const SolutionTSP &sol){
			setSol(sol);
		}

		//Getters and setters
		inline SolutionTSP getSol() const{
			return sol_;
		};
		inline void setSol(const SolutionTSP &sol){
			sol_ = sol;
		};

		//Method that gets the local optimal

		SolutionTSP getOptimal();

};
#endif