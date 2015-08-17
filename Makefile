GXX=g++
libs= -lreadline
flags= -pipe -O1 -O2 -Ofast -O3  -fomit-frame-pointer 
deps=

%.o: %.c $(libs)
	$(GXX) -c -o $@ $< $(flags)

all: main.o
	$(GXX) main.o -o Graph $(libs)

clean: 
	rm -f *.o Graph
