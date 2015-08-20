#ifndef DIGRAPH_HXX
#define DIGRAPH_HXX

#include <string>
#include <unordered_map>
#include "edge.hxx"
#include "vertex.hxx"

class Digraph {
protected:
    std::unordered_map<int, Edge> _edges;
    std::unordered_map<int, Vertex> _vertices;
    std::string _name;

    bool contains(Vertex v);
    bool contains(int v);
public:

    Digraph(std::string name);
    
    void addVertex(Vertex v);
    void addVertex(int v);
    
    void remVertex(Vertex v);
    
    void connect(Vertex a, Vertex b);
    void connect(int id_a, int id_b);
    void disconnect(Vertex a, Vertex b);
    
    std::unordered_map<int, Vertex> successor(Vertex v);
    std::unordered_map<int, Vertex> antecessor(Vertex v);
    
    int degree_of_issuance(Vertex v);
    int degree_of_reception(Vertex v);

    int order() {
        return _vertices.size();
    }

    Vertex getById(int id);
    
    std::string getName(){
        return _name;
    }
    
    Vertex aVertex();
    
    virtual ~Digraph(){};
};

#endif
