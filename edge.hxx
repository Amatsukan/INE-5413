#include <list>

#ifndef EDGE_HXX
#define	EDGE_HXX

class Vertex;

class Edge {
    Vertex * _front;
    Vertex * _back;
    int _value;

public:
    Edge(Vertex front, Vertex back, int value = 0);
    Vertex front();
    Vertex back();
    void setFront(Vertex v);
    void setBack(Vertex v);
    virtual ~Edge();
};

#endif

