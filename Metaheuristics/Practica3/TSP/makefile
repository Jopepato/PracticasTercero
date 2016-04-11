
prueba: prueba.o InstanceTSP.o LocalSearchTSP.o SolGeneratorTSP.o *.hpp
	g++ prueba.o InstanceTSP.o LocalSearchTSP.o SolGeneratorTSP.o -Wall -o3 -o prueba -lm

prueba.o: prueba.cpp *.hpp
	g++ -Wall -c prueba.cpp

InstanceTSP.o: InstanceTSP.cpp *.hpp
	g++ -Wall -c InstanceTSP.cpp -lm

LocalSearchTSP.o: LocalSearchTSP.cpp *.hpp
	g++ -Wall -c LocalSearchTSP.cpp

SolGeneratorTSP.o: SolGeneratorTSP.cpp *.hpp
	g++ -Wall -c SolGeneratorTSP.cpp

clear:
	rm -f *.o
clear2:
	rm -f prueba