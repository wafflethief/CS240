#ifndef NODE_H
#define NODE_H
#include <string>

class Node{
public:
	Node();//Node(char, double *);
	~Node();
	Node * children[128]; // total # of child nodes is 26
			     // list contains 26 links to 26 other child nodes
	char key;
	double data;//double data;
	// number of children is the # letters coming after in the string
	bool isLeaf;
};
#endif
