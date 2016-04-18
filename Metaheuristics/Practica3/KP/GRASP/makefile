prueba: prueba.o InstanceKP.o SolGeneratorKP.o SimulatedAnnealing.o *.hpp
	g++ prueba.o InstanceKP.o SolGeneratorKP.o SimulatedAnnealing.o -Wall -o3 -o prueba

oneIterationToFile: oneIterationToFile.o InstanceKP.o SolGeneratorKP.o SimulatedAnnealing.o *.hpp
	g++ oneIterationToFile.o InstanceKP.o SolGeneratorKP.o SimulatedAnnealing.o -Wall -o3 -o oneIterationToFile

probandoGrasp: probandoGrasp.o grasp.o InstanceKP.o SolGeneratorKP.o *.hpp
	g++ probandoGrasp.o grasp.o InstanceKP.o  SolGeneratorKP.o -Wall -o3 -o probandoGrasp

prueba.o: prueba.cpp *.hpp
	g++ -Wall -c prueba.cpp

oneIterationToFile.o: oneIterationToFile.cpp *.hpp
	g++ -Wall -c oneIterationToFile.cpp

InstanceKP.o: InstanceKP.cpp *.hpp
	g++ -Wall -c InstanceKP.cpp

SolGeneratorKP.o: SolGeneratorKP.cpp *.hpp
	g++ -Wall -c SolGeneratorKP.cpp

SimulatedAnnealing.o: SimulatedAnnealing.cpp *.hpp
	g++ -Wall -c SimulatedAnnealing.cpp

grasp.o: grasp.cpp *.hpp
	g++ -Wall -c grasp.cpp

clear:
	rm -f *.o
