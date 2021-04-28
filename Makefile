# Anderson Proescholdbell

CXX = clang++
CXXFLAGS = -g -Wall
OBJECTS = main.o Turing.o

a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o a.out
	@echo "Compiled!"

main.o: main.cpp Turing.h
DFA.o: Turing.cpp Turing.h


.PHONY: clean
clean:
	-rm -f *.o *~ a.out
