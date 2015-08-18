#include "vertex.hxx"
#include "edge.hxx"

//Vertex methods implementations
unsigned int Vertex::_SERIAL_NUMBER_(0);

Vertex::Vertex(int id) :
    _id(id), _edgesA(std::list<Edge>()), _edgesS(std::list<Edge>()) 
{}


void Vertex::addEdge(Edge e, Type t){
    switch(t){
        case Type::EMIT : _edgesS.push_back(e);
            return;
        case Type::RECEPT: _edgesA.push_back(e);
    }
}

