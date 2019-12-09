#include "Probe.h"
#include "Planet.h"
#include "Star.h"
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
vector<Planet> Probe::getHabitable(Star s){
	vector<Planet> habitable;
	Planet * p = nullptr;
	for(int i = 0; i < s.getPlanets().size(); i++){
		p = &(s.getPlanets()).at(i);
		if(p->getType() == 'h' && p->getDistance() >= 60 && p->getDistance() <= 140){	
			habitable.push_back(*p);
		
		}
	return habitable;
	}
}

void Probe::addToQueue(Planet p){
	queue.push(p);
}

Planet Probe::getNext(){
	Planet front = queue.front();
	queue.pop();
	return front;
	// dequeues next planet on queue and returns it
}

void Probe::shuffle(){
/*	Planet * arr[queue.size()];
	int index_choices[queue.size()];
	for(int j = 0; j < queue.size(); j++){
		index_choices[j] = j;// {0, 1, 2, 3, 4, ...queue.size() - 1}
	}
	int rand1;
	int rand2;
	int rand;
	for(int i = 0; i < queue.size(); i++){
		rand1 = rand()%index_choices.size();// random index in index_choices
		rand2 = index_choices[rand1]; // random index to store ptr to Planet
		arr[rand2] = queue.front();
		queue.pop();
		remove(begin(index_choices), end(index_choices), rand1);
	}
	for(int k = 0; k < queue.size(); k++){
		queue.push(*arr[k]);
	}
*/
	vector<Planet> shuffled;
	while(queue.empty() == false){//for(int i = 0; i < queue.size(); i++){
		shuffled.push_back(getNext());
	}
	random_shuffle(shuffled.begin(), shuffled.end());
	for(int j = 0; j < shuffled.size(); j++) addToQueue(shuffled.at(j));
}

queue<Planet>& Probe::getQueue(){
	return this->queue;
}
