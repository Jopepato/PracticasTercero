#ifndef LOCAL_SEARCH_
#define LOCAL_SEARCH_

#include "SolutionKP.hpp"

class LocalSearchKP{


	private:
		SolutionKP sol_;
		int capacity_;

	public:

		LocalSearchKP(const SolutionKP &sol, const int &cap){
			setSol(sol);
			setCapacity(cap);
		}

		//Getters and setters
		inline SolutionKP getSol() const{
			return sol_;
		};
		inline void setSol(const SolutionKP &sol){
			sol_ = sol;
		};

		inline int getCapacity()const{
			return capacity_;
		};

		inline void setCapacity(const int &capacity){
			capacity_ = capacity;
		};

		//Method that gets the local optimal

		SolutionKP getOptimal();

};
#endif