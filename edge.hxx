#ifndef EDGE_HXX
#define	EDGE_HXX

#include "vertex.hxx"

class Vertex;

class Edge {
    Vertex * _front;
    Vertex * _back;
    int _value;
    unsigned int _id;
    
    static unsigned int _SERIAL_NUMBER_;

public:
    Edge(int id = _SERIAL_NUMBER_++) : _id(id){};
    Edge(Vertex front, Vertex back, int value = 0,int id =_SERIAL_NUMBER_++);
    Edge(const Edge& e);
    Vertex sender();
    Vertex* sender() const;
    Vertex receiver();
    Vertex* receiver() const;
    int getValue() const{
        return _value;
    }
    int getId() const{
        return _id;
    }
    void setSender(Vertex v);
    void setReceiver(Vertex v);
    virtual ~Edge();
};

#endif

