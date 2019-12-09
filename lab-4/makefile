CFLAGS = -Wall -Wextra -DDEBUG -g -std=c++14

all: lab4

lab4: lab4.o Vector.h Queue.h
	g++ $(CFLAGS) lab4.o -o lab4

lab4.o: lab4.cpp Vector.h Queue.h
	g++ $(CFLAGS) -c lab4.cpp -o lab4.o

run: all
	./lab4

memcheck:
	valgrind ./lab4

clean:
	rm -rf lab4 *.o
