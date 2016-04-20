prueba: prueba.o InstanceTSP.o grasp.o *.hpp
	g++ prueba.o InstanceTSP.o grasp.o -Wall -o3 -o prueba

oneIterationToFile: oneIterationToFile.o InstanceTSP.o grasp.o *.hpp
	g++ oneIterationToFile.o InstanceTSP.o grasp.o -Wall -o3 -o oneIterationToFile

prueba.o: prueba.cpp *.hpp
	g++ -Wall -c prueba.cpp

oneIterationToFile.o: oneIterationToFile.cpp *.hpp
	g++ -Wall -c oneIterationToFile.cpp

InstanceTSP.o: InstanceTSP.cpp *.hpp
	g++ -Wall -c InstanceTSP.cpp

grasp.o: grasp.cpp *.hpp
	g++ -Wall -c grasp.cpp

clear:
	rm -f *.o
