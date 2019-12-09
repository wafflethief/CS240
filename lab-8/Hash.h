#ifndef HASH_H
#define HASH_H
#include <string>
#include "Node.h"
class Node;
class Hash{
public:
	Hash(unsigned int size);
	~Hash();
	Node * table;
	int max_size;
	int num_elems;
	unsigned int hasher(std::string key);
	bool insert(std::string key, double value);
	bool empty();
	int size();
	Node * getTable();
	bool remove(std::string key);
	double find(std::string key);
};

#endif
