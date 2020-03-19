CC = gcc
CXX = g++
CFLAGS = -g -lncurses
CXXFLAGS = -g -lncurses

Sierpinski: Sierpinski.cpp
	$(CXX) $(CXXFLAGS) -o Sierpinski Sierpinski.cpp

all: Sierpinksi.cpp 
	$(CXX) $(CXXFLAGS) -o Sierpinski Sierpinski.cpp

clean:
	rm -r Sierpinski Sierpinski.dSYM
