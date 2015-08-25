#include "vertex.hxx"

//Vertex methods implementations
unsigned int Vertex::_SERIAL_NUMBER_(0);

Vertex::Vertex(int id) :
        _id(id),
        _edgesA(std::unordered_map<int, Edge*>()),
        _edgesS(std::unordered_map<int, Edge*>())
{}


void Vertex::addEdge(Edge e, Type t){
    switch(t){
        case Type::EMIT : _edgesA[e.getId()] = &e;
            return;
        case Type::RECEPT: _edgesS[e.getId()] = &e;
    }
}

void Vertex::remEdge(Edge e, Type t){
    switch(t){
        case Type::EMIT : _edgesA.erase(e.getId());
            return;
        case Type::RECEPT: _edgesS.erase(e.getId());
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

