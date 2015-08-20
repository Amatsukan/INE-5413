#ifndef VERTEX_HXX
#define	VERTEX_HXX

#include <unordered_map>

#include "edge.hxx"

class Edge;

class Vertex {
    std::unordered_map<int, Edge*> _edgesA; //antecessors
    std::unordered_map<int, Edge*> _edgesS; //suceessors
    unsigned int _id;
    
    unsigned int EDGE_SERIAL_IN;
    unsigned int EDGE_SERIAL_OUT;
    
    static unsigned int _SERIAL_NUMBER_;
public:
    Vertex(int id = _SERIAL_NUMBER_++);

    enum Type {
        EMIT, RECEPT
    };

    unsigned int getId() const{
        return _id;
    }

    /**
     * if type is EMIT, the edge out of the vertex
     * otherwise, the edge comes to the vertex
     */

    void addEdge(Edge e, Type t);
    
    Vertex get_adjacent_vertex(int internal_id, Type t);

    std::unordered_map<int, Edge*> getAll(Type t) {
        if (t == Type::EMIT) {
            return _edgesS;
        }
        return _edgesA;
    }

    virtual ~Vertex();
};

#endif

