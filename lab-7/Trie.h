#ifndef TR_H
#define TR_H
#include <utility>
#include <string>
class Node;
class Trie{
public:
	Trie();
	~Trie();
	void deleteRecursive(Node * n);
	Node * root;
	bool add(std::pair<std::string, double> );
	unsigned int leaves;
	unsigned int n_nodes;
	unsigned int numLeaves();
	unsigned int numNodes();
	void printHelper(Node * &n);
	void printTrie();
	double search(std::string);
};
#endif
