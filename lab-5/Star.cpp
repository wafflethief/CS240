#include "Star.h"
#include "Planet.h"
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <vector>
#include <queue>
//Star::Star(){std::vector<Planet> s;}
using namespace std;

unsigned long Star::addPlanet(){
	Planet p = Planet(rand()%3001);
	v.push_back(p);
	return (p.getID());
}

bool Star::removePlanet(unsigned long id){
	for(std::vector<Planet>::iterator i = v.begin(); i != v.end(); i++){
		if((*i).getID() == id){
			v.erase(i);
			return true;
		}
	}
	return false;
}

Planet * Star::getPlanet(unsigned long id){
	Planet * p = nullptr;
	for(int i = 0; i < v.size(); i++){
		cout<< v.at(i).getID() << endl;
		if(v.at(i).getID() == id){
			p = &(v.at(i));
		}
	}
	return p;
}

std::vector<Planet>& Star::getPlanets(){
	// return vector containing planets orbiting the star
	return v;
}
