#include "../headers/Queue.h"

std::vector<Vertex*>::iterator Queue::unq(){
    std::vector<Vertex*>::iterator front = getBegin();
    q.erase(front);
    return front;
}

void Queue::inq(Vertex* v){
    q.push_back(v);
}

int Queue::getSize(){
    return q.size();
}

std::vector<Vertex*>::iterator Queue::getBegin(){
    return q.begin();
}