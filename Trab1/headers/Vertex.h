#ifndef VERTEX_H
#define VERTEX_H
#include <vector>
class Vertex{
    public:
        Vertex(int);
        bool visited;
        bool done;
        int color;
        int label;
        std::vector<Vertex*> neighbours;

};
#endif