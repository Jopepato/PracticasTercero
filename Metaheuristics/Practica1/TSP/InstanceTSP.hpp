#ifndef INSTANCETSP_HPP_
#define INSTANCETSP_HPP_

#include <string>
#include <vector>

//Are they coordenadas? :(


class InstanceTSP{
	private:
		std::string filename_;
		int dimension_;

	public:

		InstanceTSP(){
			filename_ = "berlin52.tsp";
		}

		InstanceTSP(const string &filename){
			setFilename(filename);
		}

		//Get and Set for filename
		void setFilename(const string &filename){
			filename_ = filename;
		}

		string getFilename() const{
			return filename_;
		}

		//Get and set for dimension
		void setDimension(const int &dimension){
			dimension_ = dimension;
		}

		int getDimension()const{
			return dimension_;
		}

		void readFile();

};
#endif