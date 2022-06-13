#include <iostream>
#include <vector>
#include <deque>

class Vertex;
class Heap;
class Graph;

struct Pair{
    Vertex * v;
    float w;
};

class Vertex{
    public:
        Vertex(int);
        bool done;
        bool inq;
        float k;
        float d;
        Vertex * parent;
        int heap_pos;
        int label;
        std::vector<Pair> neighbours;

};
Vertex::Vertex(int label){
    this->label = label;
    this->done = false;
    this->parent = NULL;
    this->inq = false;
    this->d = 0;
    this->k = -1;
    this->heap_pos = -1;
}

class Graph{
    private:
        std::vector<Vertex*> vertexVec;
    public:
        Vertex * getVertex(int);
        void addNeigh(Vertex*,Vertex*,float);

        void addVertex(int);

        int vecVertexSize();

        std::vector<Vertex*>  getVertexVector();

        
};

std::vector<Vertex*>  Graph:: getVertexVector(){
    return this->vertexVec;
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




void Graph::addNeigh(Vertex* v0, Vertex* v1,float w){
    v0->neighbours.push_back(Pair{v1,w});
    //v1->neighbours.push_back(Pair{v0,w});
}


//Heap

class Heap{
    private:
        std::deque<Vertex *> heap;

        void exchangeIndex(Vertex*,Vertex*);
        

    public:
        int l;
        void sobe(int);
        void desce(int);
        Heap();
        void heapAdd(Vertex *);
        Vertex * heapRem();

};

Heap::Heap(){
    this->heap.push_back(new Vertex(-1));
    this->l = 0;
};

void Heap::heapAdd(Vertex* ele){
    this->heap.push_back(ele);
    this->l++;
    ele->inq=true;
    ele->heap_pos = this->l;
    sobe(this->l);
};

Vertex * Heap::heapRem(){
    Vertex* dumb = this->heap.front();
    this->heap.pop_front();
    Vertex * r = this->heap.front();
    this->heap.pop_front();
    r->inq = false;
    this->heap.push_front(dumb);
    this->l--;
    if(this->l>0){
        Vertex * ultimo = this->heap.back();
        this->heap.pop_back();
        this->heap.pop_front();
        this->heap.push_front(ultimo);
        this->heap.push_front(dumb);
        ultimo->heap_pos=1;
        desce(1);
    }
    return r;
};

void Heap::sobe(int pos){
    if(pos/2>0){
        int pai_pos = pos/2;
        Vertex * f = this->heap.at(pai_pos);
        Vertex * s = this->heap.at(pos);
        if(f->k>s->k){
            exchangeIndex(f,s);
            this->heap[pai_pos] = s;
            this->heap[pos] = f;
            sobe(pai_pos);
        }

    }
}

void Heap::desce(int pos){
    int f_son = 2*pos;
    int s_son = 2*pos+1;
    Vertex * aux;
    if(s_son<=this->l){
        if((this->heap[pos])->k > (this->heap[s_son])->k || (this->heap[pos])->k > (this->heap[f_son])->k ){
            if((this->heap[s_son])->k < (this->heap[f_son])->k){
                aux = this->heap[s_son];
                this->heap[s_son] = this->heap[pos];
                this->heap[pos] = aux;
                exchangeIndex(this->heap[s_son],this->heap[pos]);
                desce(s_son);

            }
            else{
                aux = this->heap[f_son];
                this->heap[f_son] = this->heap[pos];
                this->heap[pos] = aux;
                exchangeIndex(this->heap[f_son],this->heap[pos]);
                desce(f_son);
            }
        }
    }
    if(f_son<=this->l){
        if((this->heap[pos])->k > (this->heap[f_son])->k){
            aux = this->heap[f_son];
            this->heap[f_son] = this->heap[pos];
            this->heap[pos] = aux;
            exchangeIndex(this->heap[f_son],this->heap[pos]);
            desce(f_son);

        }
    }
}

void Heap::exchangeIndex(Vertex * v1, Vertex * v2){
    int aux;
    aux = v1->heap_pos;
    v1->heap_pos = v2->heap_pos;
    v2->heap_pos = aux;
}

//Main

void parseInput(Graph*);
void Djiska(Graph * g,Heap* heap);

void parseInput(Graph* g){
    char in[100];
    int n1,v1,v2;
    float w;

    std::fgets(in,sizeof(in),stdin);//dl
    std::fgets(in,sizeof(in),stdin);//edgelist1
    std::fgets(in,sizeof(in),stdin);//n=10\n
    std::sscanf(in,"n=%d\n",&n1);
    for(int i = 1;i<=n1;i++){
        g->addVertex(i);
    }
    std::fgets(in,sizeof(in),stdin);//data:
    while(std::fgets(in,sizeof(in),stdin)!=NULL){
        if(std::sscanf(in,"%d %d %f\n",&v1,&v2,&w)!=3){
            break;
        }
        g->addNeigh(g->getVertex(v1),g->getVertex(v2),w);

        
    }
}


void Djiska(Graph * g,Heap* heap){
    Vertex* vv;
    float vw;
    while(heap->l>0){
        Vertex * u = heap->heapRem();
        u->done = true;
        u->d=u->k;
        std::vector<Pair> n = u->neighbours;
        for (long unsigned int i=0;i<n.size();i++){
            vv = n[i].v;
            vw = n[i].w;
            if(vv->done==false && vv->inq == false){
                vv->k = u->d+vw;
                vv->parent = u;
                heap->heapAdd(vv);
            }
            else if(vv->inq == true){
                if(vv->k>u->d+vw){
                    vv->k = u->d+vw;
                    vv->parent = u;
                    heap->sobe(vv->heap_pos);
                }
            }
        }
    }

}

void mostraRes(Graph * g){
    Vertex* v;
    for(int i=1;i<g->vecVertexSize();i++){
        v = g->getVertex(i);
        if(v->k==-1){
            printf("%d INFINITO\n",v->label);
        }
        else{
            printf("%d %.3f\n",v->label,v->d);
        }
    }
}

int main(int argc, char const *argv[])
{
    Graph *g = new Graph;
    g->addVertex(-1);
    parseInput(g);
    Heap *heap = new Heap();
    Vertex * v0 = g->getVertex(1);
    v0->k=0;
    heap->heapAdd(v0);
    Djiska(g,heap);
    mostraRes(g);
    
}





