prueba: prueba.o InstanceMDP.o Och.o SolGeneratorMDP.o *.hpp
	g++ prueba.o InstanceMDP.o Och.o SolGeneratorMDP.o  -Wall -o3 -o prueba

#oneIterationToFile: oneIterationToFile.o InstanceMDP.o Och.o SolGeneratorMDP.o  *.hpp
#	g++ oneIterationToFile.o InstanceMDP.o Och.o SolGeneratorMDP.o  -Wall -o3 -o oneIterationToFile

prueba.o: prueba.cpp *.hpp
	g++ -Wall -c prueba.cpp

#oneIterationToFile.o: oneIterationToFile.cpp *.hpp
#	g++ -Wall -c oneIterationToFile.cpp

InstanceMDP.o: InstanceMDP.cpp *.hpp
	g++ -Wall -c InstanceMDP.cpp

SolGeneratorMDP.o: SolGeneratorMDP.cpp *.hpp
	g++ -Wall -c SolGeneratorMDP.cpp

Och.o: Och.cpp *.hpp
	g++ -Wall -c Och.cpp

clear:
	rm -f *.o
