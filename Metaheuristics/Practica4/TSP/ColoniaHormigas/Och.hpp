#include <vector>
#include <limits>
#include "InstanceTSP.hpp"
#include "SolutionTSP.hpp"

struct Ant{
	std::vector <node> solution;
	double aportePheronomonas;
};


class Och{

	private:
		double pheromone_;
		double alpha_;
		double beta_;
		SolutionTSP bestSolution_;
		double vaporizePercentage_;
		std::vector< std::vector <double> > pheromoneMatrix_;
		std::vector< std::vector <double> > distanceMatrix_;
		std::vector< std::vector <double> > heuristicMatix_;
		std::vector<node> original_;
		std::vector<Ant> hotmiguitas_;

	public:


		Och(const InstanceTSP &instance){
			setPheromone(10);
			setVaporizePercentage(0.1);
			setBeta(2);
			setAlpha(1);
			setOriginal(instance.getSolutionTSP());
			fillMatrix(instance.getSolutionTSP().size());
			fillDistanceAndHeuristicMatrix(instance.getSolutionTSP());
		}

		void setPheromone(const double &pherom){
			pheromone_ = pherom;
		}

		double getPheromone() const{
			return pheromone_;
		}

		void setAlpha(const double &alpha){
			alpha_ = alpha;
		}

		double getAlpha() const{
			return alpha_;
		}

		void setAlpha(const double &beta){
			beta_ = beta;
		}

		double getBeta() const{
			return beta_;
		}

		void setVaporizePercentage(const double &perc){
			vaporizePercentage_ = perc;
		}

		double getVaporizePercentage() const{
			return vaporizePercentage_;
		}

		void setHormiguitas(const vector<Ant> &hormi){
			hormiguitas_ = hormi;
		};

		vector<Ant> getHormiguitas() const{
			return hormiguitas_;
		}

		vector<node> getOriginal() const{
			return original_;
		}

		void setOriginal(const vector<node> &orig){
			original_ = orig;
		}

		//Funciones para la construncción y uso de las hormigüitas

		void fillMatrix(const int &length);

		void fillDistanceAndHeuristicMatrix(std::vector<node> &nodes);

		double getProbability();

		void runAnts();

		void refreshPheromoneMatrix();

		node Och::getNextNode(const int &x, const std::vector<node> &caminoHormiga);

		~Och(){
			pheromoneMatrix_.clear();
		}


};