//#include <gtest/gtest.h>
#include <iostream>
#include "edge.hxx"
#include "vertex.hxx"
#include "digraph.hxx"

using namespace std;

int main(int argc, char** argv) {
    Vertex v = Vertex(999);
    Digraph d = Digraph("test");
    d.addVertex(v);
    d.addVertex(50);
    cout<<d.contains(50)<<endl;
    cout<<d.contains(v)<<endl;
    d.connect(v,50);
    cout<<d.degree_of_issuance(50)<<endl;
    cout<<d.degree_of_reception(50)<<endl;
}
