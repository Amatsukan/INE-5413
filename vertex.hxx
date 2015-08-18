#include <list>

#ifndef VERTEX_HXX
#define	VERTEX_HXX

#include "edge.hxx"

class Edge;

class Vertex {
    std::list<Edge*> _edgesA; //antecessors
    std::list<Edge*> _edgesS; //suceessors
    unsigned int _id;
    static unsigned int _SERIAL_NUMBER_;
public:
    Vertex(int id = _SERIAL_NUMBER_++);

    enum Type {
        EMIT, RECEPT
    };

    unsigned int getId() {
        return _id;
    }

    /**
     * if type is EMIT, the edge out of the vertex
     * otherwise, the edge comes to the vertex
     */

    void addEdge(Edge e, Type t);

    std::list<Edge*> getAll(Type t) {
        if (t == Type::EMIT) {
            return _edgesS;
        }
        return _edgesA;
    }

    virtual ~Vertex();
};

#endif

