#ifndef QUEUE_H
#define QUEUE_H
#include <vector>
#include "Vertex.h"
class Queue{
    private:
        std::vector<Vertex*> q;
    public:
        std::vector<Vertex*>::iterator unq();
        void inq(Vertex*);
        int getSize();
        std::vector<Vertex*>::iterator getBegin();
};
#endif