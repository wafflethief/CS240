CFLAGS = -Wall -Wextra -DDEBUG -g -std=c++14

all: lab7

lab7: lab7.o Trie.o Node.o
	g++ $(CFLAGS) Trie.o Node.o lab7.o -o lab7

lab7.o: lab7.cpp
	g++ $(CFLAGS) -c lab7.cpp -o lab7.o

Trie.o: Trie.cpp Trie.h
	g++ $(CFLAGS) -c Trie.cpp -o Trie.o

Node.o: Node.cpp Node.h
	g++ $(CFLAGS) -c Node.cpp -o Node.o

run: all
	./lab7

clean:
	rm -rf ./program2 *.o

memcheck: all
	valgrind ./lab7
