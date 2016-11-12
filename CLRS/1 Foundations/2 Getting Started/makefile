CC=gcc
CFLAGS=-I -std=c++11 -stdlib=libc++ -Wno-c++11-extensions
DEPS = insertionsort.hpp mergesort.hpp
OBJ = insertionsort.o mergesort.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

c++: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)