#include <iostream>
#include <string>
#include "../headers/Graph.h"
void parseInput(Graph*);
int main(int argc, char const *argv[])
{
    Graph *g = new Graph;
    /*
    
    g.addVertex(32);
    g.addVertex(2);
    g.addEdge(g.getVertex(0),g.getVertex(1));
    g.getVertex(0)->label = 3;
    std::cout << g.getVertex(0)->label << " " << "\n";
    std::cout << g.getEdge(0).edge.first->label << " " << "\n";
    std::cout << g.getEdge(0).edge.second->label << " " << "\n";
    return 0;*/
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
    while(std::fgets(in,sizeof(in),stdin)[0]!='\n'){
        std::scanf("%d %d",&v1,&v2);
        g->addEdge(g->getVertex(v1),g->getVertex(v2));
    }
    for(int i=0;i<g->vecEdgeSize();i++){
        std::cout << g->getEdge(i).edge.first->label << " " << g->getEdge(i).edge.second->label << "\n";
    }

}

