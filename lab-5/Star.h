#ifndef S_H
#define S_H
#include <vector>
class Planet;
class Star{
public:
	std::vector<Planet> v;
	unsigned long addPlanet();
	bool removePlanet(unsigned long);
	Planet * getPlanet(unsigned long);
	std::vector<Planet>& getPlanets();
};
#endif
