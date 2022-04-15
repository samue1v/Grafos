#include <iostream>
#include <string>
#include <queue>
#include <vector>

class Vertex{
    public:
        Vertex(int);
        bool done;
        int color;
        int label;
        std::vector<Vertex*> neighbours;

};

class Graph{
    private:
        std::vector<Vertex*> vertexVec;
    public:
        Vertex * getVertex(int);
        void addNeigh(Vertex*,Vertex*);

        void addVertex(int);

        int vecVertexSize();

        
};

Vertex::Vertex(int label){
    this->label = label;
    this->done = false;
}

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


void Graph::addNeigh(Vertex* v0, Vertex* v1){
    v0->neighbours.push_back(v1);
    v1->neighbours.push_back(v0);
}

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
        //g->addEdge(g->getVertex(v1-1),g->getVertex(v2-1));
        g->addNeigh(g->getVertex(v1-1),g->getVertex(v2-1));

        
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
        for(int i=0;i<(int)(v1->neighbours.size());i++){
            if(v1->neighbours[i]->color == 0){
                q.push(v1->neighbours[i]);
            }
        }   
    }
}


void showResult(Graph *g){
    int color,cont,size;
    Vertex *v;
    Vertex *v1;
    size = g->vecVertexSize();
    for(int i = 0;i<(int)(size);i++){
        cont = 0;
        v = g->getVertex(i);
        if(v->done == false){
            color = v->color;
            for(int j = 0;j<(int)(size);j++){
                v1 = g->getVertex(j);
                if(v1->done == false && v1->color == color){
                    if(cont!=0){std::cout<<" ";}
                    std::cout << v1 ->label;  
                    v1->done = true;
                    cont++;
                }
            }
            std::cout << "\n"; 
        }
    }
}

