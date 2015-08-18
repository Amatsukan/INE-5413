#include "edge.hxx"

//Edge methods implementations

Edge::Edge(Vertex front, Vertex back, int value) :
_front(&front), _back(&back), _value(value) {}

Vertex Edge::front() {
    return *_front;
}

Vertex Edge::back() {
    return *_back;
}

void Edge::setFront(Vertex v) {
    _front = &v;
}

void Edge::setBack(Vertex v) {
    _back = &v;
}

Edge::~Edge(){
    
}

