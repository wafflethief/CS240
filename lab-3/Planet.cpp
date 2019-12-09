#include "Planet.h"
#include "Star.h"
#include <cstdlib>
#include <iostream>
#include <stdio.h>
Planet::Planet(int distance, int id){
	this->id = id;
	this->distance = distance;
	this->pos = rand()%360;
	char typeArr[] = {'h', 'r', 'g'};
	this->type = typeArr[rand()%3];
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

char Planet::getType(){
	return this->type;
}
