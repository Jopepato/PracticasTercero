
prueba: prueba.o InstanceMDP.o SimulatedAnnealing.o SolGeneratorMDP.o *.hpp
	g++ prueba.o InstanceMDP.o SimulatedAnnealing.o SolGeneratorMDP.o -Wall -o3 -o prueba -lm

oneIterationToFile: oneIterationToFile.o InstanceMDP.o SolGeneratorMDP.o SimulatedAnnealing.o *.hpp
	g++ oneIterationToFile.o InstanceMDP.o SolGeneratorMDP.o SimulatedAnnealing.o -Wall -o3 -o oneIterationToFile

prueba.o: prueba.cpp *.hpp
	g++ -Wall -c prueba.cpp

InstanceMDP.o: InstanceMDP.cpp *.hpp
	g++ -Wall -c InstanceMDP.cpp -lm

SolGeneratorMDP.o: SolGeneratorMDP.cpp *.hpp
	g++ -Wall -c SolGeneratorMDP.cpp

SimulatedAnnealing.o: SimulatedAnnealing.cpp *.hpp
	g++ -Wall -c SimulatedAnnealing.cpp

clear:
	rm -f *.o

clear2:
	rm -f prueba
