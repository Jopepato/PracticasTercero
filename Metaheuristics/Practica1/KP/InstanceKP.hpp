#ifndef INSTANCEKP_HPP_
#define INSTANCEKP_HPP_

#include <vector>
#include <string>

struct knapsack{
	int price;
	int weight;
	bool token;
};

class InstanceKP{
	private:
		std::string fileName_;
		int capacity_;
		
	public:

		//Here we would make our methods :D
		InstanceKP(const std::string &fileName){
			setFileName(fileName);
			setCapacity(0);
		}

		InstanceKP(){
			setFileName("KP.txt");
			setCapacity(0);
		}

		//Get and Sets methods

		inline void setFileName(const std::string &fileName){
			fileName_ = fileName;
		};

		inline std::string getFileName() const{
			return fileName_;
		};

		inline void setCapacity(const int &capacity){
			capacity_ = capacity;
		}

		inline int getCapacity() const{
			return capacity_;
		}

		std::vector<knapsack> readFile();

		int getPrice(const std::vector<knapsack> vectorSolution);
};

#endif