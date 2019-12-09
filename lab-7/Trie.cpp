#include "Trie.h"
#include "Node.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <utility>
using namespace std;
class Node;
Trie::Trie(){
	Node * n = new Node();
	n->data = -1.0;
	n->key = ' ';
	//this->root->data = 0;//this->root = nullptr;
	this->root = n;
	this->n_nodes = 0;
	this->leaves = 0;
	root->isLeaf = false;
}

Trie::~Trie(){
	//should there be a Node destructor for the children array?
	/*for(int i = 0; i < 128; i++){
		if(this->root->children[i] != nullptr){
			delete this->root->children[i];
			this->root->children[i] = nullptr;
		}
	}*/
//	deleteRecursive(this->root);
	delete this->root;
	this->root = nullptr;
}

bool Trie::add(std::pair<string, double> p){
	//if(search(key) != -1) return false;
	Node * temp = this->root;
	unsigned int i = 0;
	n_nodes++;
	while(i < p.first.length()){
		if(temp->children[(int)p.first[i] - (int)'a'] == 0){
			Node * n = new Node();
			n->key = p.first[i];
			n->data = -1.0;
			temp->children[(int)p.first[i] - (int)'a'] = n;
			//temp->children[(int)p.first[i] - (int)'a']->key = p.first[i];
			if(i == p.first.length() - 1)
				{n->data = p.second;}
	
			this->n_nodes++;
		}
		temp = temp->children[(int)p.first[i] - (int)'a'];
		i++;
	}
	++this->leaves;
//	temp->children[(int)p.first[i-1] - (int)'a']->data = p.second;
	return true;
}

unsigned int Trie::numLeaves(){
	return this->leaves;
}

unsigned int Trie::numNodes(){
	return this->n_nodes;
}

double Trie::search(string key){
	//if(this->root == nullptr) return -1.0;
	// if above line is not here, the ret -1 in the loop must be first
	Node * temp = this->root;
	double retVal;
	unsigned int i = 0;
	while(i < key.length()){
		/*
		if(temp->children[(int)key[i] - (int)'a'] == nullptr){
			return -1.0;
		}
		*/
		if(((int)key[i] - (int)'a') >= 128 ) return -1.0;
		if(temp == nullptr) return -1.0;
		temp = temp->children[(int)key[i] - (int)'a'];
		i++;
	}
	retVal = temp->children[(int)key[i-1] - (int)'a']->data;
	cout << retVal <<endl;
	return 1.0;//return retVal;
}

void Trie::printHelper(Node * &n){
	if(n->key == '\0') return;
	cout << "Parent: (key) " << n->key << " : (value) " << n->data << endl;
		for(int i = 0; i < 128; i++){
		if(n->children[i] != nullptr){
			cout << "   -----> Child: (key) " << n->children[i]->key
			<< " : (value) " << n->children[i]->data <<endl;
		}
	}
	for(int i = 0; i < 26; i++){
		if(n->children[i] != nullptr) printHelper(n->children[i]);
	}
}

void Trie::printTrie(){
// prints each node in the trie and its children
	printHelper(this->root);
}
