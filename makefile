compile:
	g++ -c paleidimas.cpp funkcijos.cpp ivedimasFailo.cpp ivedimasRankinis.cpp strukturos.cpp sukurimasFailo.cpp
	g++ -o main paleidimas.o funkcijos.o ivedimasFailo.o ivedimasRankinis.o strukturos.o sukurimasFailo.o
clean:
	del *.o *.exe
