#include "Hash.h"
#include "Node.h"
#include <iostream>
#include <stdlib.h>
#include <string>
class Node;
using namespace std;

Hash::Hash(unsigned int size){
	this->table = new Node[size]; //The normal array declaration style uses the default constructor
					//for each object in the array (if the class has a default constructor)
	this->max_size = size;
	this->num_elems = 0;
}

Hash::~Hash(){
	delete[] this->table;
	this->table = nullptr;
}

unsigned int Hash::hasher(string key){
	unsigned int a_sum = 0;
	for(int i = 0; key[i] != '\0'; i++){
		a_sum += key[i];
	}
	return a_sum%(max_size);
}

bool Hash::insert(string key, double value){
	if(num_elems == max_size) return false;
	unsigned int index = hasher(key);
	Node n = Node();
	n.key = key;
	n.value = value;
	if(table[index].key == ""){
		table[index] = n;
	}
	else{
		unsigned int lin_ind = index + 1;
		while(table[lin_ind].key != ""){
			lin_ind = (lin_ind+1)%max_size;
		}
		table[lin_ind] = n;

	}
	num_elems++;
	return true;
}

bool Hash::empty(){
	return (num_elems == 0);
}

int Hash::size(){
	return this->max_size;
}

Node * Hash::getTable(){
	return this->table;
}

double Hash::find(string key){
	for(int i = 0; i < max_size; i++){
		if(key.compare(table[i].key) == 0){
			return table[i].value;
		}
	}
	return -1.0;
}

bool Hash::remove(string key){
	for(int i = 0; i < max_size; i++){
		if(key.compare(table[i].key) == 0){
			table[i].key = "";
			table[i].value = -1.0;
			num_elems--;
			return true;
		}
	}
	return false;
}
