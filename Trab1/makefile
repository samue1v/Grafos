all: main

main: main.o graph.o vertex.o queue.o
	g++ -o main main.o graph.o vertex.o queue.o

main.o: src/main.cpp headers/Graph.h
	g++ -c src/main.cpp

vertex.o: src/Vertex.cpp headers/Vertex.h
	g++ -o vertex.o -c src/Vertex.cpp

graph.o: src/Graph.cpp headers/Graph.h
	g++ -o graph.o -c src/Graph.cpp

queue.o: src/Queue.cpp headers/Queue.h
	g++ -o queue.o -c src/Queue.cpp
clean:
	rm -rf *.o *~ main
