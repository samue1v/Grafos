#include <iostream>
#include <string>
#include "../headers/Graph.h"
void parseInput(Graph*);
void algorithm(Graph*,std::vector<std::vector<Vertex*>>*);
int main(int argc, char const *argv[])
{
    Graph *g = new Graph;
    std::vector<std::vector<Vertex*>> *paths;
    parseInput(g);
}

void parseInput(Graph* g){
    char in[20];

    int n,v1,v2;
    std::fgets(in,sizeof(in),stdin);
    std::fgets(in,sizeof(in),stdin);
    std::scanf("n=%d\n",&n);
    for(int i = 0;i<n;i++){
        g->addVertex(i);
    }
    while(std::fgets(in,sizeof(in),stdin)!=NULL){
        if(std::sscanf(in,"%d %d",&v1,&v2)!=2){
            break;
        }
        g->addEdge(g->getVertex(v1),g->getVertex(v2));
        
    }
    for(int i=0;i<g->vecEdgeSize();i++){
        std::cout << g->getEdge(i).edge.first->label << " " << g->getEdge(i).edge.second->label << "\n";
    }

}

void algorithm(Graph* g,std::vector<std::vector<Vertex*>>* paths){
    //lembra de pensar sobre a possibilidade de mais metodos para por na classe Graph
}

