
#ifndef GRAFO_H
#define GRAFO_H
#include <vector>
#include "Edge.h"
#include "Vertex.h"
class Graph{
    private:
        std::vector<Vertex*> vertexVec;
        std::vector<Edge> edgeVec;
    public:
        Vertex * getVertex(int);
        Edge getEdge(int);
        void addVertex(int);
        void addEdge(Vertex*,Vertex*);
        int vecVertexSize();
        int vecEdgeSize();
        
};

#endif