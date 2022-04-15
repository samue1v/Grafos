#include <iostream>
#include <string>
#include <queue>
#include "../headers/Graph.h"
void parseInput(Graph*);
void BFS(Graph*, Vertex*,int);
void showResult(Graph*);
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
    showResult(g);
    
}

void parseInput(Graph* g){
    char in[100];
    int n1,v1,v2;
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
            break;
        }
        g->addEdge(g->getVertex(v1-1),g->getVertex(v2-1));

        
    }
}

void BFS(Graph* g,Vertex* v,int color){
    std::queue<Vertex*> q; 
    Vertex *v1;
    q.push(v);
    while(q.size()>0){
        v1 = q.front();
        v1->color=color;
        q.pop();
        for(int i=0;i<v1->neighbours.size();i++){
            if(v1->neighbours[i]->color == 0){
                q.push(v1->neighbours[i]);
            }
        }   
    }
}


void showResult(Graph *g){
    for(int i = 0;i<g->vecVertexSize();i++){
        int cont = 0;
        if(g->getVertex(i)->done == false){
            int color = g->getVertex(i)->color;
            for(int j = 0;j<g->vecVertexSize();j++){
                if(g->getVertex(j)->done == false && g->getVertex(j)->color == color){
                    if(cont!=0){std::cout<<" ";}
                    std::cout << g->getVertex(j)->label;  
                    g->getVertex(j)->done = true;
                    cont++;
                }
            }
            std::cout << "\n"; 
        }
    }
}

