//#include <gtest/gtest.h>
#include <iostream>
#include "edge.hxx"
#include "vertex.hxx"
#include "digraph.hxx"

using namespace std;

int main(int argc, char** argv) {

    Digraph d = Digraph("test");
    for(int i = 0; i<100; i++){
        d.addVertex(i);
    }
    d.connect(0,50);
    cout<<d.order()<<endl;
    
}
