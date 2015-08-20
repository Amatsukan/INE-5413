#ifndef EDGE_HXX
#define	EDGE_HXX

#include "vertex.hxx"

class Vertex;

class Edge {
    Vertex * _front;
    Vertex * _back;
    int _value;

public:
    Edge(){};
    Edge(Vertex front, Vertex back, int value = 0);
    Edge(const Edge& e);
    Vertex sender();
    Vertex* sender() const;
    Vertex receiver();
    Vertex* receiver() const;
    int getValue() const{
        return _value;
    }
    void setSender(Vertex v);
    void setReceiver(Vertex v);
    virtual ~Edge();
};

#endif

