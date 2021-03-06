compileFailo:
	g++ -c ivedimasFailo.cpp
	g++ -c funkcijosFailo.cpp
	g++ -o main funkcijosFailo.o ivedimasFailo.o
compileRankinio:
	g++ -c ivedimasRankinis.cpp
	g++ -c funkcijos.cpp
	g++ -o main funkcijos.o ivedimasRankinis.o
delete:
	del *.o *.exe