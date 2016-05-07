prueba: prueba.o InstanceTSP.o Och.o SolGeneratorTSP.o *.hpp
	g++ -std=c++11 prueba.o InstanceTSP.o Och.o SolGeneratorTSP.o  -Wall -o3 -o prueba

oneIterationToFile: oneIterationToFile.o InstanceTSP.o Och.o SolGeneratorTSP.o  *.hpp
	g++ -std=c++11 oneIterationToFile.o InstanceTSP.o Och.o SolGeneratorTSP.o  -Wall -o3 -o oneIterationToFile

prueba.o: prueba.cpp *.hpp
	g++ -std=c++11 -Wall -c prueba.cpp

oneIterationToFile.o: oneIterationToFile.cpp *.hpp
	g++ -std=c++11 -Wall -c oneIterationToFile.cpp

InstanceTSP.o: InstanceTSP.cpp *.hpp
	g++ -std=c++11 -Wall -c InstanceTSP.cpp

SolGeneratorTSP.o: SolGeneratorTSP.cpp *.hpp
	g++ -std=c++11 -Wall -c SolGeneratorTSP.cpp

Och.o: Och.cpp *.hpp
	g++ -std=c++11 -Wall -c Och.cpp

clear:
	rm -f *.o
