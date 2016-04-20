#ifndef INSTANCETSP_HPP_
#define INSTANCETSP_HPP_

#include <string>
#include <vector>
#include "SolutionTSP.hpp"

//Are they coordenadas? :(


class InstanceTSP{
	private:
		std::string filename_;
		SolutionTSP solution_;

	public:

		InstanceTSP(){
			filename_ = "berlin52.tsp";
		}

		InstanceTSP(const std::string &filename){
			setFilename(filename);
		}

		//Get and Set for filename
		void setFilename(const std::string &filename){
			filename_ = filename;
		}

		std::string getFilename() const{
			return filename_;
		}

		inline void setSolutionTSP(const std::vector<node>& solution){
			solution_.setSolution(solution);
		}

		inline std::vector<node> getSolutionTSP() const{
			return (solution_.getSolution());
		}

		void readFile();

};
#endif