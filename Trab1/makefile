all: main

main: main.o graph.o
	g++ -o main main.o graph.o

main.o: src/main.cpp headers/Graph.h
	g++ -c src/main.cpp

graph.o: src/Graph.cpp headers/Graph.h
	g++ -o graph.o -c src/Graph.cpp

clean:
	rm -rf *.o *~ main
