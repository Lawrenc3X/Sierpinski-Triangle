CC = gcc
CXX = g++
CFLAGS = -lncurses
CXXFLAGS = -lncurses

Sierpinski: Sierpinski.cpp
	$(CXX) $(CXXFLAGS) -o Sierpinski Sierpinski.cpp

all: Sierpinksi.cpp 
	$(CXX) $(CXXFLAGS) -o Sierpinski Sierpinski.cpp

clean:
	rm -r Sierpinski Sierpinski.dSYM
