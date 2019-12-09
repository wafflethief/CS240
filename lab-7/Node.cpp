#include "Node.h"
#include <iostream>
#include <stdlib.h>
Node::Node(){//char c, double dat){
	//this->next = nullptr;
	//this->child = nullptr;
	//this->letter = c;
	//this->data = dat;
	//this->children =
	for(int i = 0; i < 128; i++){
		this->children[i] = nullptr;
	} 
	this->key = 0;
	this->data = 0;
}

Node::~Node(){
	for(int i = 0; i < 128; i++){
		if(children[i] != nullptr){
		delete children[i];
		children[i] = nullptr;
		}	
	}
}

