#include "vertex.hxx"

//Vertex methods implementations
unsigned int Vertex::_SERIAL_NUMBER_(0);

Vertex::Vertex(int id) :
        _id(id),
        _edgesA(std::unordered_map<int, Edge*>()),
        _edgesS(std::unordered_map<int, Edge*>()),
        EDGE_SERIAL_OUT(0),
        EDGE_SERIAL_IN(0)
{}


void Vertex::addEdge(Edge e, Type t){
    switch(t){
        case Type::EMIT : _edgesS[EDGE_SERIAL_OUT++] = &e;
            return;
        case Type::RECEPT: _edgesS[EDGE_SERIAL_IN++] = &e;
    }
}

Vertex Vertex::get_adjacent_vertex(int internal_id, Type t){
        if (t == Type::EMIT) {
            return (_edgesS[internal_id])->receiver();
        }
        return (_edgesA[internal_id])->sender();
    }

Vertex::~Vertex(){
    
}

