prueba: prueba.o InstanceKP.o SolGeneratorKP.o SimulatedAnnealing.o *.hpp
	g++ prueba.o InstanceKP.o SolGeneratorKP.o SimulatedAnnealing.o -Wall -o3 -o prueba

prueba.o: prueba.cpp *.hpp
	g++ -Wall -c prueba.cpp

InstanceKP.o: InstanceKP.cpp *.hpp
	g++ -Wall -c InstanceKP.cpp

SolGeneratorKP.o: SolGeneratorKP.cpp *.hpp
	g++ -Wall -c SolGeneratorKP.cpp

SimulatedAnnealing.o: SimulatedAnnealing.cpp *.hpp
	g++ -Wall -c SimulatedAnnealing.cpp

clear:
	rm -f *.o
