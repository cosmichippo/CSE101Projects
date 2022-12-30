CXX = g++
CXXFLAGS = -Wall -std=c++11

OBJECTS = main.o

nqueens: $(OBJECTS)
	    $(CXX) -g $(CXXFLAGS) -o $@ main.o 

main.o: main.cpp 
		$(CXX) -g $(CXXFLAGS) -c main.cpp

clean:
	rm *.o
	

