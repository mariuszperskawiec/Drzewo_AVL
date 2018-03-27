all: main.o drzewo.o przejscia.o
	g++ main.o drzewo.o przejscia.o -o drzewo_AVL

main.o: main.cpp drzewo.hpp przejscia.hpp
	g++ -c -Wall -pedantic main.cpp 

drzewo.o: drzewo.cpp drzewo.hpp
	g++ -c -Wall -pedantic drzewo.cpp

przejscia.o: przejscia.cpp przejscia.hpp drzewo.hpp
	g++ -c -Wall -pedantic przejscia.cpp

clean:
	rm -f *.o test