#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>


class Vertex{
    public:
        Vertex(int);
        Vertex *parent;
        bool visited;
        int color;                        //remember to change
        int label;
};


Vertex::Vertex(int label){
    this->label = label;
    this->color=0;
    this->visited=false;
}

class Edge{
    public:
        Edge();
        Edge(Vertex*,Vertex*,int);
        std::pair<Vertex*,Vertex*> edge; 
        int capacity;
        int flow;
        int residualFlow;         
};

Edge::Edge(){this->capacity=0;this->flow=0;this->residualFlow = 0;}
Edge::Edge(Vertex* v1,Vertex* v2,int capacity){
    this->edge.first = v1;
    this->edge.second = v2;
    this->capacity = capacity;
    this->flow = 0;
    this->residualFlow = capacity

}

class Graph{
    private:
        std::vector<Vertex*> vertexVec;
        
    public:
        Graph(int);
        int matrixOrder;
        std::vector<Edge> * matrix;
        std::vector<std::vector<int>> pathVec;
        Vertex * getVertex(int);
        void addVertex(int);
        Edge getFromMatrix(int, int);
        void addEdge(Vertex*,Vertex*,int);
        int vecVertexSize();
};

Graph::Graph(int size){
    this->matrixOrder = size;
    std::vector<Edge> matrix[size*size];
    this->matrix = matrix;
}

Edge Graph::getFromMatrix(int row,int column){
    row--;
    column--;
    return (this->matrix)[row][column];
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


void Graph::addEdge(Vertex* v0,Vertex* v1,int capacity){
    int row = (v0->label)-1;
    int column = (v1->label)-1;
    Edge edge = Edge(v0,v1,capacity);
    (*(this->matrix))[((row)*(this->matrixOrder))+column] = edge;
    (*(this->matrix))[((row)*(this->matrixOrder))+column].residualFlow = capacity; //capacidade residual no inicio é igual a capacidade sobrando
    if((*(this->matrix))[(column)*(this->matrixOrder)+row].capacity==0){ //Essa aresta ainda nao foi vista, terá uma aresta no sentido inverso adicionada como uma aresta residual
        (*(this->matrix))[(column)*(this->matrixOrder)+row] = Edge(edge.edge.second,edge.edge.first,-1);
        
    }
}

Graph * parseInput();
void BFS(Graph*, Vertex*,int);
void showResult(Graph*);


int main(int argc, char const *argv[])
{
    Graph *g = parseInput();
    int color = 0;
    for(int i = 0;i<g->vecVertexSize();i++){
        Vertex *v = g->getVertex(i);
        if(v->color == 0){ 
            v->color=++color;   
            BFS(g,v,color);
        }
    }    
}

Graph * parseInput(){
    char in[100];
    int n1,v1,v2;
    float c;

    std::fgets(in,sizeof(in),stdin);//dl
    std::fgets(in,sizeof(in),stdin);//edgelist1
    std::fgets(in,sizeof(in),stdin);//n=10\n

    std::sscanf(in,"n=%d\n",&n1);
    Graph * g = new Graph(n1);
    
    for(int i = 1;i<=n1;i++){
        g->addVertex(i);
    }
    std::fgets(in,sizeof(in),stdin);//data:
    while(std::fgets(in,sizeof(in),stdin)!=NULL){
        if(std::sscanf(in,"%d %d %f\n",&v1,&v2,&c)!=3){
            break;
        }
        g->addEdge(g->getVertex(v1),g->getVertex(v2),c);

        
    }
    return g;
}

void BFS(Graph* g,Vertex* v,int color){
    std::queue<Vertex*> q; 
    Vertex *v1;
    std::vector<int> path;
    q.push(v);
    v->visited = true;
    path.push_back(v->label);
    while(q.size()>0){
        v1 = q.front();
        v1->color=color;
        q.pop();
        for(long unsigned int i=0;i<v1->neighbours.size();i++){
            if(v1->neighbours[i]->color == 0 && v1->neighbours[i]->visited==false){
                v1->neighbours[i]->visited = true;
                path.push_back(v1->neighbours[i]->label);
                q.push(v1->neighbours[i]);
            }
        }   
    }
    g->pathVec.push_back(path);
}


