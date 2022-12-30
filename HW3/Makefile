CXX = g++
CXXFLAGS = -Wall -std=c++11

OBJECTS = main.o

wordrange: $(OBJECTS)
	    $(CXX) -g $(CXXFLAGS) -o $@ main.o 

main.o: main.cpp BinarySearchTree.h BinarySearchTree.cpp
		$(CXX) -g $(CXXFLAGS) -c main.cpp

clean:
	rm *.o
	rm hello
