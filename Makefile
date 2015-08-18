GXX=g++
flags= -pipe -O1 -O2 -Ofast -O3  -fomit-frame-pointer 
deps=

%.o: %.cpp %.hxx 
	$(GXX) -c -o $@ $< $(flags)

all: test.o graph.o digraph.o vertex.o edge.o
	$(GXX) test.o -o Test $(libs)

clean: 
	rm -f *.o Test
