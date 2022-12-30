CXX = g++
CXXFLAGS = -Wall -std=c++11

OBJECTS = main.o

sixdegrees: $(OBJECTS)
	    $(CXX) -g $(CXXFLAGS) -o $@ main.o 

main.o: main.cpp Graph.h Graph.cpp
		$(CXX) -g $(CXXFLAGS) -c main.cpp

clean:
	rm *.o
