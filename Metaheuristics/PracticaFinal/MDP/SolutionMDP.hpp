#ifndef SOLUTIONTSP_HPP_
#define SOLUTIONTSP_HPP_

#include <vector>

class SolutionTSP{

private:
		std::vector<int> vectorSol_;
		std::vector< std::vector<double> > matrizDistancias_;
public:
		SolutionTSP(){
			vectorSol_.clear();
		}

		SolutionTSP(const std::vector<int> &vectorSol, std::vector< std::vector<double> > matrizDistancias_){
			setSolution(vectorSol);
			setMatrizDistancias(matrizDistancias_);
		}

		inline std::vector<int> getSolution()const{
			return vectorSol_;
		};

		inline void setSolution(const std::vector<int> &vectorSol){
			vectorSol_=vectorSol;
		};

		std::vector< std::vector<double> > getMatrizDistancias()const{
			return matrizDistancias_;
		}

		void setMatrizDistancias(const std::vector< std::vector<double> > &matriz){
			matrizDistancias_ = matriz;
		}

		double getDistanciaSolucion(){
			//Devuelve la distancia que es la suma de las distancias Ü :D
			double distancia = 0.0;
			for(unsigned int i=0; i<vectorSol_.getSize()-1; i++){
				distancia = distancia + matrizDistancias_[vectorSol_[i]][vectorSol_[i+1]];
			}

			return distancia;
		}
};

#endif