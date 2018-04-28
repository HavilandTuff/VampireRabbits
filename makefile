#makefile for vampire bunny project.
CC=g++
CPPFLAGS= -Wall -std=c++11 -lncurses
DEPS= names.hpp bunny.hpp bunny_herd.hpp game_field.hpp
OBJ= main.o bunny.o bunny_herd.o game_field.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CPPFLAGS)
	
bunny: $(OBJ)
	$(CC) -o ./bin/$@ $^ $(CPPFLAGS)
	
clean:
	@echo Deleting unnecessery files...
	@rm -f *.o
