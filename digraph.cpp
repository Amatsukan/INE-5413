#include "digraph.hxx"
#include <stdexcept>
#include <algorithm> 
#include <cstdlib>
#include <ctime>

//Digraph methods implementations

Digraph::Digraph(std::string name):
        _edges(),
        _vertices(),
        _name(name)
{}

void Digraph::addVertex(Vertex v){
        if(!contains(v)){
            _vertices[v.getId()] = v;
        }
}

void Digraph::addVertex(int v){
        if(!contains(v)){
            _vertices[v] = Vertex(v);
        }
}

bool Digraph::contains(Vertex v) {
    try {
        if (_vertices.at(v.getId()).getId() == v.getId()) {
            return true;
        }
    } catch (std::out_of_range e) {
        return false;
    }
    return true;
}

bool Digraph::contains(int v) {
    try {
        if (_vertices.at(v).getId() == v) {
            return true;
        }
    } catch (std::out_of_range e) {
        return false;
    }
    return true;
}

void Digraph::connect(Vertex a, Vertex b){
    if(!contains(a) or !contains(b)) throw std::invalid_argument("Leastwise one of these vertices are not part of the domain graph (Digraph::connect(Vertex, Vertex))");
    
    Edge e = Edge(a,b);
    a.addEdge(e, Vertex::EMIT);
    b.addEdge(e, Vertex::RECEPT);
    _edges[_edges.size()] = e;
}

void Digraph::connect(int id_a, int id_b){
    if(!contains(id_a) or !contains(id_b)) throw std::invalid_argument("Leastwise one of these vertices are not part of the domain graph (Digraph::connect(int,int))");
    
    Edge e = Edge(_vertices[id_a],_vertices[id_b]);
    _vertices[id_a].addEdge(e, Vertex::EMIT);
    _vertices[id_b].addEdge(e, Vertex::RECEPT);
    _edges[_edges.size()] = e;
}

void Digraph::remVertex(Vertex v){
    if(!contains(v)) throw std::invalid_argument("This vertex is not part of the domain graph (Digraph::remVertex(Vertex)");
}

void Digraph::disconnect(Vertex a, Vertex b){
    if(!contains(a) or !contains(b)) throw std::invalid_argument("Leastwise one of these vertices are not part of the domain graph (Digraph::connect(int,int))");
}

std::unordered_map<int, Vertex> Digraph::successor(int v){
    if(!contains(v)) throw std::invalid_argument("This vertex is not part of the domain graph (Digraph::sucessor(Vertex))");
    
    std::unordered_map<int, Vertex> next_vertices;
    std::unordered_map<int, Edge*> edges = _vertices[v].getAll(Vertex::EMIT);
    int i = 0;
    
    for(auto it = edges.begin(); it != edges.end(); it++,i++){
        next_vertices[i] = (it->second)->receiver();
    }
    
    return next_vertices;
}

std::unordered_map<int, Vertex> Digraph::successor(Vertex v){
    return successor(v.getId());
}


std::unordered_map<int, Vertex> Digraph::antecessor(int v){
    if(!contains(v)) throw std::invalid_argument("This vertex is not part of the domain graph (Digraph::antecessor(Vertex))");
    
    std::unordered_map<int, Vertex> prev_vertices;
    std::unordered_map<int, Edge*> edges = _vertices[v].getAll(Vertex::RECEPT);
    int i =0;
    
    for(auto it = edges.begin(); it != edges.end(); it++,i++){
        prev_vertices[i] = (it->second)->sender();
    }
    
    return prev_vertices;
}

std::unordered_map<int, Vertex> Digraph::antecessor(Vertex v){
    return antecessor(v.getId());
}

int Digraph::degree_of_issuance(int v){
    if(!contains(v)) throw std::invalid_argument("This vertex is not part of the domain graph (Digraph::degree_of_issuance(Vertex))");
    
    return _vertices[v].getAll(Vertex::EMIT).size();
}

int Digraph::degree_of_reception(int v){
    if(!contains(v)) throw std::invalid_argument("This vertex is not part of the domain graph (Digraph::degree_of_reception(Vertex))");
    
    return _vertices[v].getAll(Vertex::RECEPT).size();
}

int Digraph::degree_of_issuance(Vertex v){    
    return degree_of_issuance(v.getId());
}

int Digraph::degree_of_reception(Vertex v){
    return degree_of_reception(v.getId());
}

Vertex Digraph::getById(int id){
    return _vertices[id];
}

Vertex Digraph::aVertex(){
    return _vertices.end()->second;
}
