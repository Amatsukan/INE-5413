#!/bin/bash
g++ -O3  edge.cpp edge.hxx vertex.cpp vertex.hxx  mainTest.cpp digraph.hxx digraph.cpp  -std=c++14
rm *.gch 
