#ifndef DIGRAPH_HXX
#define DIGRAPH_HXX

#include <string>
#include <list>
#include "edge.hxx"
#include "vertex.hxx"

class Digraph {
protected:
    std::list<Edge> _edges;
    std::list<Vertex> _vertices;
    std::string _name;

    bool contains(Vertex v);
public:

    Digraph(std::string name = NULL);
    
    void addVertex(Vertex v);
    void remVertex(Vertex v);
    
    void connect(Vertex a, Vertex b);
    void disconnect(Vertex a, Vertex b);
    
    std::list<Vertex> successor(Vertex v);
    std::list<Vertex> atecessor(Vertex v);
    
    int degree_of_issuance(Vertex v);
    int degree_of_reception(Vertex v);

    int order() {
        return _vertices.size();
    }

    std::string getName(){
        return _name;
    }
    
    Vertex aVertex();
    
    virtual ~Digraph();
};

#endif
