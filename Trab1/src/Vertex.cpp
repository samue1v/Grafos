#include "../headers/Vertex.h"

Vertex::Vertex(int label){
    this->label = label;
    this->visited=false;
    this->done = false;
}
