#ifndef QUEUE_H
#define QUEUE_H
#include <vector>
#include "Vertex.h"
class Stack{
    private:
        std::vector<Vertex*> s;
    public:
        Vertex* sPop();
        void sPush(Vertex*);
        int getSize();
        
};
#endif