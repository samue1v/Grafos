#ifndef VERTEX_H
#define VERTEX_H
#include <vector>
class Vertex{
    public:
        Vertex(int label);
        bool viewed;
        int label;
        std::vector<Vertex*> neighbours;



};
#endif