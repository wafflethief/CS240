CFLAGS = -Wall -Wextra -DDEBUG -g -std=c++14

all: lab8

lab8: lab8.o Node.o Hash.o
	g++ $(CFLAGS) lab8.o Node.o Hash.o -o lab8

lab8.o: lab8.cpp Node.o Node.h Hash.o Hash.h
	g++ $(CFLAGS) -c lab8.cpp -o lab8.o

Node.o: Node.cpp Node.h
	g++ $(CFLAGS) -c Node.cpp -o Node.o

Hash.o: Hash.cpp Hash.h
	g++ $(CFLAGS) -c Hash.cpp -o Hash.o

run: all
	./lab8

memcheck:
	valgrind --leak-check=full ./lab8

clean:
	rm -rf ./lab8 *.o
