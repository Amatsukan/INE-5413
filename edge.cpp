#include "edge.hxx"

//Edge methods implementations

Edge::Edge(Vertex sender, Vertex receiver, int value) :
_front(&sender), _back(&receiver), _value(value) {}

Edge::Edge(const Edge& e):
        _front((e.sender())),
        _back((e.receiver())), 
        _value(e.getValue()){}

Vertex Edge::sender(){
    return *_front;
}

Vertex* Edge::sender() const{
    return _front;
}

Vertex Edge::receiver(){
    return *_back;
}

Vertex* Edge::receiver() const{
    return _back;
}

void Edge::setSender(Vertex v) {
    _front = &v;
}

void Edge::setReceiver(Vertex v) {
    _back = &v;
}

Edge::~Edge(){
    
}

