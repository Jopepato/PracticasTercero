prueba: prueba.o InstanceTSP.o Och.o SolGeneratorTSP.o *.hpp
	g++ prueba.o InstanceTSP.o Och.o SolGeneratorTSP.o  -Wall -o3 -o prueba

oneIterationToFile: oneIterationToFile.o InstanceTSP.o Och.o SolGeneratorTSP.o  *.hpp
	g++ oneIterationToFile.o InstanceTSP.o Och.o SolGeneratorTSP.o  -Wall -o3 -o oneIterationToFile

prueba.o: prueba.cpp *.hpp
	g++ -Wall -c prueba.cpp

oneIterationToFile.o: oneIterationToFile.cpp *.hpp
	g++ -Wall -c oneIterationToFile.cpp

InstanceTSP.o: InstanceTSP.cpp *.hpp
	g++ -Wall -c InstanceTSP.cpp

SolGeneratorTSP.o: SolGeneratorTSP.cpp *.hpp
	g++ -Wall -c SolGeneratorTSP.cpp

Och.o: Och.cpp *.hpp
	g++ -Wall -c Och.cpp

clear:
	rm -f *.o
