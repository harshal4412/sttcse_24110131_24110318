CXX = g++
CXXFLAGS = -Wall -std=c++17

all: randfuncs

randfuncs: main.o randfuncs.o
	$(CXX) $(CXXFLAGS) -o randfuncs main.o randfuncs.o

main.o: main.cpp randfuncs.h
	$(CXX) $(CXXFLAGS) -c main.cpp

randfuncs.o: randfuncs.cpp randfuncs.h
	$(CXX) $(CXXFLAGS) -c randfuncs.cpp

clean:
	rm -f *.o randfuncs