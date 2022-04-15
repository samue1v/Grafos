#include "../headers/Stack.h"

Vertex* Stack::sPop(){
    Vertex* head;
    head = s.back();
    s.pop_back();
    return head;
}

void Stack::sPush(Vertex* v){
    s.push_back(v);
}

int Stack::getSize(){
    return s.size();
}