#makefile for vampire bunny project.
CC=g++
CPPFLAGS= -Wall -std=c++11
DEPS= names.hpp bunny.hpp
OBJ= main.o bunny.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CPPFLAGS)
	
bunny: $(OBJ)
	$(CC) -o ./bin/$@ $^ $(CPPFLAGS)
	
clean:
	@echo Deleting unnecessery files...
	@rm -f *.o
