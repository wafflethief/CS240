CFLAGS = -Wall -Wextra -DDEBUG -g -std=c++14

all: lab5

lab5: lab5.o Planet.o Star.o Probe.o
	g++ $(CFLAGS) lab5.o Planet.o Star.o Probe.o -o lab5

lab5.o: lab5.cpp Planet.h Star.h Probe.h
	g++ $(CFLAGS) -c lab5.cpp -o lab5.o

Planet.o: Planet.cpp Planet.h
	g++ $(CFLAGS) -c Planet.cpp -o Planet.o

Star.o: Star.cpp Star.h Planet.cpp Planet.h
	g++ $(CFLAGS) -c Star.cpp -o Star.o

Probe.o: Probe.cpp Probe.h Star.cpp Star.h Planet.cpp Planet.h
	g++ $(CFLAGS) -c Probe.cpp -o Probe.o

run: all
	./lab5
memcheck:
	valgrind ./lab5

clean:
	rm -rf ./lab5 *.o
