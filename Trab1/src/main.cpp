#include <iostream>
#include <string>
#include <queue>
#include "../headers/Queue.h"
#include "../headers/Graph.h"
void parseInput(Graph*);
void BFS(Graph*, Vertex*,int);
void showResult(std::vector<Vertex*>*);
int main(int argc, char const *argv[])
{
    Graph *g = new Graph;
    parseInput(g);
    int color = 0;
    for(int i = 0;i<g->vecVertexSize();i++){
        
        Vertex *v = g->getVertex(i);
        if(v->color == 0){    
            BFS(g,v,++color);
        }
    }
    for(int i=0;i<g->vecEdgeSize();i++){
        std::cout 
        << "label:" <<g->getEdge(i).edge.first->label << " color:" << g->getEdge(i).edge.first->color << " " 
        << "label:" <<g->getEdge(i).edge.second->label << " color:"<<g->getEdge(i).edge.second->color<<"\n"    ;
    }
}

void parseInput(Graph* g){
    char in[100];
    int n1,v1,v2;
    g->addVertex(0);
    std::fgets(in,sizeof(in),stdin);//dl
    std::fgets(in,sizeof(in),stdin);//edgelist1
    std::fgets(in,sizeof(in),stdin);//n=10\n
    std::sscanf(in,"n=%d\n",&n1);
    for(int i = 1;i<=n1;i++){
        g->addVertex(i);
    }
    std::fgets(in,sizeof(in),stdin);//data:
    while(std::fgets(in,sizeof(in),stdin)!=NULL){
        if(std::sscanf(in,"%d %d\n",&v1,&v2)!=2){
            std::cout <<"gay\n";
            break;
        }
        g->addEdge(g->getVertex(v1),g->getVertex(v2));

        
    }
    //std::cout <<"gay\n";
        for(int i=0;i<g->vecEdgeSize();i++){
        std::cout 
        << g->getEdge(i).edge.first->label << " " << g->getEdge(i).edge.first->color << " " 
        << g->getEdge(i).edge.second->label << " "<< g->getEdge(i).edge.second->color<<"\n"    ;
    }
}

void BFS(Graph* g,Vertex* v,int color){
    std::queue<Vertex*> q; 
    Vertex *v1;
    q.push(v);
    while(q.size()>0){
        v1 = q.front();
        std::cout << v1->label <<"\n";
        v1->color=color;
        q.pop();
        for(int i=0;i<v1->neighbours.size();i++){
            if(v1->neighbours[i]->color == 0){
                q.push(v1->neighbours[i]);
            }
        }   
    }
}

void showResult(std::vector<Vertex*>* vecVertices){
    
}

