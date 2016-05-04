prueba: prueba.o InstanceKP.o Och.o SolGeneratorKP.o *.hpp
	g++ prueba.o InstanceKP.o Och.o SolGeneratorKP.o  -Wall -o3 -o prueba

oneIterationToFile: oneIterationToFile.o InstanceKP.o Och.o SolGeneratorKP.o  *.hpp
	g++ oneIterationToFile.o InstanceKP.o Och.o SolGeneratorKP.o  -Wall -o3 -o oneIterationToFile

prueba.o: prueba.cpp *.hpp
	g++ -Wall -c prueba.cpp

oneIterationToFile.o: oneIterationToFile.cpp *.hpp
	g++ -Wall -c oneIterationToFile.cpp

InstanceKP.o: InstanceKP.cpp *.hpp
	g++ -Wall -c InstanceKP.cpp

SolGeneratorKP.o: SolGeneratorKP.cpp *.hpp
	g++ -Wall -c SolGeneratorKP.cpp

Och.o: Och.cpp *.hpp
	g++ -Wall -c Och.cpp

clear:
	rm -f *.o
