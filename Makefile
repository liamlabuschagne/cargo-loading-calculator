CXX = g++
CXXFLAGS = -g -Wall -std=c++20 # debugging symbols, all warnings and c++20
objects = main.o
out = clc

.PHONY: all clean

all: $(out)

$(out): $(objects)
	$(CXX) $(CXXFLAGS) $(objects) -o clc

%.o:
	$(CXX) $(CXXFLAGS) -c *.cpp

clean:
	rm *.o $(out)
