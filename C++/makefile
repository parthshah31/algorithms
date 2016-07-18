CC=gcc
CFLAGS=-I -std=c++11 -stdlib=libc++ -Wno-c++11-extensions
DEPS = dict.hpp structures.hpp
OBJ = dict.o structures.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

c++: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)