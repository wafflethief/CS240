#include "Planet.h"
#include "Star.h"
#include <cstdlib>
#include <iostream>
#include <stdio.h>
Star::Star(){
	this->current_planets = 0;
	this->next_id = 0;
	this->planets = NULL; // array of planet pointers
}

Star::~Star(){
	for(int i = 0; i < this->current_planets; i++){
		delete planets[i];
	}
	delete[] this->planets;
}

int Star::addPlanet(){
	// https://stackoverflow.com/questions/33170802/c-does-freeing-an-array-of-pointers-also-free-what-theyre-pointing-to
	// https://www.cs.fsu.edu/~myers/c++/notes/pointers1.html
	Planet ** newArr = new Planet*[this->current_planets + 1];
	for(int i = 0; i < current_planets; i++){
		newArr[i] = planets[i];
	}
	Planet * p = new Planet(rand()%3001, current_planets); // new planet object
	newArr[this->current_planets] = p; //put planet pointer in new array
	delete[] planets; // free the old array;
	this->planets = newArr;
	this->current_planets++; // update current num of planets
	return (*p).getID();
}

bool Star::removePlanet(int id){
	if(getPlanet(id) == NULL) return false;
	Planet ** newArr = new Planet*[this->current_planets - 1];
	int index = 0;
	for(int i = 0; i < current_planets; i++){
		if((*planets[i]).getID() != id){
			newArr[index] = planets[i];
			index++;
		}
		if((*planets[i]).getID() == id){
		       	delete planets[i];
			planets[i] = NULL;
		}
	}
	this->current_planets--;
	delete[] planets;
	this->planets = newArr;
	return true;
}

Planet * Star::getPlanet(int id){
	for(int i = 0; i < current_planets; i++){
		if((*planets[i]).getID() == id)
			return planets[i];
	}
	return NULL;
}

Planet Star::getFurthest(){
	Planet furthest = *planets[0];
	for(int i = 1; i < this->current_planets; i++){
		if((*planets[i]).getDistance() > furthest.getDistance())
			furthest = *planets[i];
	}
	return furthest;
}
void Star::orbit(){
	for(int i = 0; i < this->current_planets; i++)
		(*planets[i]).orbit();
}
void Star::printStarInfo(){
	std::cout << "The star currently has %d planets.\n" << std::endl;
	for(int i = 0; i < this->current_planets; i++){
		printf("Planet %c%d is %d miles away at position %d around the star.\n",
		(*planets[i]).getType(), (*planets[i]).getDistance(), (*planets[i]).getPos());
	}
}
