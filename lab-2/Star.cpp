#include "Star.h"
#include <cstdlib>
#include <iostream>
#include <stdio.h>

class Planet;
Planet::Planet(int distance, int id){
	this->id = id;
	this->distance = distance;
	this->pos = 0;
}

int Planet::getID() {
	return this->id;
}

int Planet::orbit(){
	this->pos = (this->pos + 1)%360;
	return this->pos;
}
int Planet::getDistance() {
	return this->distance;
}

int Planet::getPos() {
	return this->pos;
}

Star::Star(int max_planets){
	this->max_planets = max_planets;
	this->current_planets = 0;
	this->next_id = 0;
}
bool Star::addPlanet(){
	if(current_planets < max_planets){
		Planet * toAdd = new Planet(rand()%3001, this->next_id);
		this->planets[this->next_id] = *toAdd;
		this->next_id++;
		this->current_planets++;
		delete toAdd;
		toAdd = NULL;
		return true;
	}
	return false;
}
Planet Star::getFurthest(){
	Planet furthest = planets[0];
	for(int i = 1; i < this->max_planets; i++){
		if(planets[i].getDistance() > furthest.getDistance())
			furthest = planets[i];
	}
	return furthest;
}
void Star::orbit(){
	for(int i = 0; i < this->max_planets; i++)
		planets[i].orbit();
}
void Star::printStarInfo(){
	std::cout << "The star currently has %d planets.\n" << std::endl;
	for(int i = 0; i < this->max_planets; i++){
		printf("Planet %d is %d miles away at position %d around the star.",
		i, planets[i].getDistance(), planets[i].getPos());
	}
}
int Star::getCurrentNumPlanets(){
	return this->current_planets;
}

int Star::getMaxPlanets(){
	return this->max_planets;
}