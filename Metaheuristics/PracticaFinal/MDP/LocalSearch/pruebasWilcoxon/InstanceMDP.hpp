#ifndef INSTANCEMDP_HPP_
#define INSTANCEMDP_HPP_

#include <string>
#include <vector>

//Are they coordenadas? :(


class InstanceMDP{
	private:
		std::string filename_;
		std::vector< std::vector<double> > matrizInstancia_;
		int size_;
		int subSize_;
	public:

		InstanceMDP(){

		}

		InstanceMDP(const std::string &filename){
			setFilename(filename);
		}

		//Get and Set for filename
		void setFilename(const std::string &filename){
			filename_ = filename;
		}

		std::string getFilename() const{
			return filename_;
		}

		std::vector< std::vector<double> > getMatriz()const{
			return matrizInstancia_;
		}

		void setMatriz(const std::vector< std::vector<double> > &matriz){
			matrizInstancia_ = matriz;
		}

		int getSubSize()const{
			return subSize_;
		}

		void setSubSize(const int &sub){
			subSize_ = sub;
		}

		int getSize()const{
			return size_;
		}

		void setSize(const int &size){
			size_ = size;
		}

		void readFile();
		void imprimirMatriz();

};

#endif