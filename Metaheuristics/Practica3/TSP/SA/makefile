
prueba: prueba.o InstanceTSP.o SimulatedAnnealing.o SolGeneratorTSP.o *.hpp
	g++ prueba.o InstanceTSP.o SimulatedAnnealing.o SolGeneratorTSP.o -Wall -o3 -o prueba -lm

oneIterationToFile: oneIterationToFile.o InstanceTSP.o SolGeneratorTSP.o SimulatedAnnealing.o *.hpp
	g++ oneIterationToFile.o InstanceTSP.o SolGeneratorTSP.o SimulatedAnnealing.o -Wall -o3 -o oneIterationToFile

prueba.o: prueba.cpp *.hpp
	g++ -Wall -c prueba.cpp

InstanceTSP.o: InstanceTSP.cpp *.hpp
	g++ -Wall -c InstanceTSP.cpp -lm

SolGeneratorTSP.o: SolGeneratorTSP.cpp *.hpp
	g++ -Wall -c SolGeneratorTSP.cpp

SimulatedAnnealing.o: SimulatedAnnealing.cpp *.hpp
	g++ -Wall -c SimulatedAnnealing.cpp

clear:
	rm -f *.o

clear2:
	rm -f prueba