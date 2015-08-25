#include "edge.hxx"

//Edge methods implementations

unsigned int Edge::_SERIAL_NUMBER_(0);

Edge::Edge(Vertex sender, Vertex receiver, int id, int value) :
_front(&sender), _back(&receiver), _value(value), _id(id) {}

Edge::Edge(const Edge& e):
        _front((e.sender())),
        _back((e.receiver())), 
        _value(e.getValue()),
        _id(e.getId()){}

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

