P= lab3
OBJECTS =
CFLAGS = -Wall -Wextra -DDEBUG -g -std=c++14

all: lab3

lab3: lab3.o Star.o Planet.o
	g++ $(CFLAGS) lab3.o Star.o Planet.o -o lab3

lab3.o: lab3.cpp Star.h Planet.h
	g++ $(CFLAGS) -c lab3.cpp -o lab3.o
	
Star.o: Star.cpp Star.h Planet.h
	g++ $(CFLAGS) -c Star.cpp -o Star.o

Planet.o: Planet.cpp Star.h Planet.h
	g++ $(CFLAGS) -c Planet.cpp -o Planet.o

run: all
	./lab3
	
clean:
	rm -rf $(P) *.o
