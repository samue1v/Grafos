#include "../headers/Graph.h"

Vertex * Graph::getVertex(int index){
    return vertexVec.at(index);   
}

void Graph::addVertex(int label){
    Vertex *v = new Vertex(label);
    vertexVec.push_back(v);
}

int Graph::vecVertexSize(){
    return vertexVec.size();
}

int Graph::vecEdgeSize(){
    return edgeVec.size();
}

void Graph::addEdge(Vertex* v0,Vertex* v1){
    Edge e;
    e.edge.first = v0;
    e.edge.second = v1;
    edgeVec.push_back(e);
}

Edge Graph::getEdge(int index){
    return edgeVec.at(index);
}