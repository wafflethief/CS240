#include "Planet.h"
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <vector>
#include <queue>
unsigned long Planet::s_id = 0;

Planet::Planet(){}

Planet::Planet(int dist){
	this->distance = dist;
	char typeArr[] = {'h', 'r', 'g'};
	this->type = typeArr[rand()%3];
	this->id = (unsigned long)s_id++;
}

unsigned long Planet::getID(){
	return this->id;
}

unsigned int Planet::getDistance(){
	return (unsigned int)(this->distance);
}

char Planet::getType(){
	return this->type;
}
