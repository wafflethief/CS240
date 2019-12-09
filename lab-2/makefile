P= lab2
OBJECTS =
CFLAGS = -Wall -Wextra -DDEBUG -g -std=c++14

all: lab2

lab2: lab2.o Star.o
	g++ $(CFLAGS) lab2.o Star.o -o lab2

lab2.o: lab2.cpp Star.h
	g++ $(CFLAGS) -c lab2.cpp -o lab2.o
	
Star.o: Star.cpp Star.h
	g++ $(CFLAGS) -c Star.cpp -o Star.o

run: all
	./lab2
	
clean:
	rm -rf $(P) *.o