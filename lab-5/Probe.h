#ifndef PROBE_H
#define PROBE_H
#include <vector>
#include <queue>
class Planet;
class Star;
class Probe{
public:
	std::queue<Planet> queue;
	std::vector<Planet> getHabitable(Star);
	void addToQueue(Planet);
	Planet getNext();
	std::queue<Planet>& getQueue();
	void shuffle();
};
#endif
