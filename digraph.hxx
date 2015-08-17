#include <list>
#include <string>
#ifndef DIGRAPH
#define DIGRAPH

class Edge {
    Vertex _front;
    Vertex _back;
    int _value;

public:
    Edge(Vertex front, Vertex back, int value = 0);
    Vertex front();
    Vertex back();
    void setFront(Vertex v);
    void setBack(Vertex v);
    virtual ~Edge();
};

class Vertex {
    std::list<Edge> _edgesA; //antecessors
    std::list<Edge> _edgesS; //suceessors
    int _id;

public:

    enum Type {A, E}

    Vertex(int id = 0);
    addEdge(Edge e, Type t);
    std::list<Vertex> getAll(Type t);
    virtual ~Vertex();
};

class Digraph {
    std::list<Edge> _edges;
    std::list<Vertex> _vertices;

public:
    Digraph(string name = NULL);
    virtual ~Digraph();
    void addVertex(Vertex v);
    void connect(Vertex a, Vertex b);
    void remVertex(Vertex v);
    void disconnect(Vertex a, Vertex b);
    std::list<Vertex> successor(Vertex v);
    std::list<Vertex> atecessor(Vertex v);

};

#endif
