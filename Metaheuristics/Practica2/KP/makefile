prueba: prueba.o InstanceKP.o LocalSearchKP.o SolGeneratorKP.o *.hpp
	g++ prueba.o InstanceKP.o LocalSearchKP.o SolGeneratorKP.o -Wall -o3 -o prueba

prueba.o: prueba.cpp *.hpp
	g++ -Wall -c prueba.cpp

InstanceKP.o: InstanceKP.cpp *.hpp
	g++ -Wall -c InstanceKP.cpp

LocalSearchKP.o: LocalSearchKP.cpp *.hpp
	g++ -Wall -c LocalSearchKP.cpp

SolGeneratorKP.o: SolGeneratorKP.cpp *.hpp
	g++ -Wall -c SolGeneratorKP.cpp

clear:
	rm -f *.o