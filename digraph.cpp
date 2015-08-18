#include "digraph.hxx"
#include <stdexcept>
#include <algorithm> 
#include <cstdlib>
#include <ctime>

//Digraph methods implementations

Digraph::Digraph(string name):
    _edges(std::list<Edge>()), _vertices(std::list<Vertex>()), _name(name)
{}

void Digraph::addVertex(Vertex v){
        if(!contains(v)){
            _vertices.push_back(v);
        }
}

bool Digraph::contains(Vertex v){
    Iterator<Vertex> it;
    for(it = _vertices.begin(); it != _vertices.end; it++){
        if((*it).getId() != v.getId()){
            return true;
        }
    }
    return false;
}

void Digraph::connect(Vertex a, Vertex b){
    if(!contains(a) or !contains(b)) throw std::invalid_argument();
    
    Edge e = Edge(a,b);
    a.addEdge(e, Vertex::EMIT);
    b.addEdge(e, Vertex::RECEPT);
    _edges.push_back(e);
}
void Digraph::remVertex(Vertex v){
    if(!contains(v)) throw std::invalid_argument();
}

void Digraph::disconnect(Vertex a, Vertex b){
    if(!contains(a) or !contains(b)) throw std::invalid_argument();
}

std::list<Vertex> Digraph::successor(Vertex v){
    if(!contains(v)) throw std::invalid_argument();
    
    return v.getAll(Vertex::EMIT);
}

std::list<Vertex> Digraph::atecessor(Vertex v){
    if(!contains(v)) throw std::invalid_argument();
    
    return v.getAll(Vertex::RECEPT);
}

int Digraph::degree_of_issuance(Vertex v){
    if(!contains(v)) throw std::invalid_argument();
    
    return v.getAll(Vertex::EMIT).size();
}

int Digraph::degree_of_reception(Vertex v){
    if(!contains(v)) throw std::invalid_argument();
    
    return v.getAll(Vertex::RECEPT).size();
}

Vertex Digraph::aVertex(){
    std::srand ( unsigned ( std::time(0) ) );
    std::random_shuffle(_vertices.begin(), _vertices.end());
    return _vertices.front();
}
