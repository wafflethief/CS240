#ifndef BST_H
#define BST_H
#include <cstddef>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
class Node;
template <class T>
class BSTree{
private:
       class Node{ // can only access node class w/in BSTree if Node class is priv
               public:
                       Node(T);
                       T data;
                       Node * left;
                       Node * right;
                       Node * parent;
       };
public:
       BSTree();
       BSTree(const BSTree<T> &);
       ~BSTree();
       bool empty();
       void removeLeaf(Node *);
       void shortCircuit(Node *);
       void promotion(Node *);
       bool insert(T val);
       bool insertHelper(Node * , T val);//Node * insertHelper(Node *, T val);
       Node * findRightMin(Node * );
       bool find(T val);
       Node * findHelper(Node * , T val);
       bool remove(T val);
       std::vector<T>  sortedArrayHelper(Node *, std::vector<T> &list);// void??
       void sortedArray(std::vector<T> &list);
       void preOrder(Node *);
       void postOrder(Node *);
       Node * getHelper(Node *, T );
       Node * get(T);
       void balance();
       void balanceHelper(std::vector<T> &list, int, int);
       int height();
       int findHeight(Node *);

       Node * root;
};

template <class T>
BSTree<T>::BSTree(){
       root = NULL;
}

template <class T>
BSTree<T>::BSTree(const BSTree<T> &old_tree){
       root = NULL;
       preOrder(old_tree.root);
}

template <class T>
void BSTree<T>::preOrder(Node * n){
       if(n){
               this->insert(n->data);
               if(n->left) preOrder(n->left);
               if(n->right) preOrder(n->right);
       }
}

template <class T>
void BSTree<T>::postOrder(Node * n){
       if(n != NULL){
               if(n->left != NULL) postOrder(n->left);
               if(n->right != NULL) postOrder(n->right);
               remove(n->data);
       }
}

template <class T>
BSTree<T>::~BSTree(){
       postOrder(this->root);
}

template <class T> BSTree<T>::Node::Node(T val){
       this->data = val;
       this->parent = NULL;
       this->left = NULL;
       this->right = NULL;
}
template <class T>
bool BSTree<T>::empty(){
       if(root == NULL) return true;//if(numElems == 0) return true;
       return false;
}

template <class T>
bool BSTree<T>::insertHelper(Node * r, T val){
       if(r->data == val) return false;
       else if (r->data < val) {
               if (!r->right) {
                       r->right = new Node(val);
                       r->right->parent = r;
                       return true;
               } else {
                       insertHelper(r->right, val);
               }
       }
       else {
               if (!r->left) {
                       r->left = new Node(val);
                       r->left->parent = r;
                       return true;
               } else {
                       insertHelper(r->left, val);
               }
       }
       return false;
}

template <class T>
bool BSTree<T>::insert(T val){
       if(!this->root){
               this->root = new Node(val);
               return true;
       }
       return insertHelper(root, val);
}
// return typename(outside::nested)
template <class T>
typename BSTree<T>::Node * BSTree<T>::findHelper(Node * n, T val){
       if(n == NULL) return NULL;
       if(n != NULL){
               if(n->data == val) return n;
               if(val < n->data){
                       return findHelper(n->left, val);
               }
               if(val > n->data){
                       return findHelper(n->right, val);
               }
       }
       return NULL;
}

template <class T>
bool BSTree<T>::find(T val){
       if(findHelper(root, val) == NULL) return false;
       return true;
}

template <class T>
typename BSTree<T>::Node * BSTree<T>::findRightMin(Node * n){
       if(n->left == NULL) return n;
       return findRightMin(n->left);
}
template <class T> // case for no children
void BSTree<T>::removeLeaf(Node * leaf){
       if(leaf->parent == NULL){
               this->root = NULL;
               delete leaf;
               leaf = NULL;
       }

       else if(leaf == leaf->parent->right){
               leaf->parent->right = NULL;
               delete leaf;
               leaf = NULL;
       }
       else{
               leaf->parent->left = NULL;
               delete leaf;
               leaf = NULL;
       }
}

template <class T> // case for 1 child
void BSTree<T>::shortCircuit(Node * r){
       if(r->parent == NULL){
               if(r->right == NULL){
                       Node * temp = r->left;
                       delete r;
                       r = NULL;
                       temp->parent = NULL;
                       this->root = temp;
               }else {
                       Node * temp = r->right;
                       delete r;
                       r = NULL;
                       temp->parent = NULL;//temp->right->parent = NULL;
                       this->root = temp;
               }
       }
       else if(r == r->parent->left){
               if(r->right == NULL){
                       r->parent->left = r->left;
                       r->left->parent = r->parent;
               } else {
                       r->parent->left = r->right;
                       r->right->parent = r->parent;
               }
               delete r;
               r = NULL;
       }
       else if(r == r->parent->right) {
               if(r->left == NULL){
                       r->parent->right = r->right;
                       r->right->parent = r->parent;
               } else {
                       r->parent->right = r->left;
                       r->left->parent = r->parent;
               }
               delete r;
               r = NULL;
       }
}
template <class T> // case for two children
void BSTree<T>::promotion(Node * r){
       Node * rightMin = findRightMin(r->right);
       r->data = rightMin->data;
       if(rightMin->left == NULL && rightMin->right == NULL) removeLeaf(rightMin);//if(rightMin->right == NULL) removeLeaf(r);
       else shortCircuit(rightMin);
}

template <class T>
bool BSTree<T>::remove(T val){
       Node * r = findHelper(root, val);
       if(r != NULL){
               if(r->left == NULL && r->right == NULL) removeLeaf(r);
               else if(r->left == NULL || r->right == NULL) shortCircuit(r);
               else promotion(r);
               return true;
       }
       return false;
}

template <class T>
std::vector<T> BSTree<T>::sortedArrayHelper(Node* n, std::vector<T> & list){
       if(n == NULL) return list;
               sortedArrayHelper(n->left, list);
       list.push_back(n->data);
               sortedArrayHelper(n->right, list);
       return list;
}

template <class T>
void BSTree<T>::sortedArray(std::vector<T> &list){
       //inorder traversal: left, add root, right
       sortedArrayHelper(this->root, list);
}

template <class T>
void BSTree<T>::balance(){
       std::vector<T> list;
       sortedArray(list);//sortedArrayHelper(this->root, list);
       postOrder(this->root);
       delete this->root;
       this->root = NULL;
       balanceHelper(list, 0, list.size() -1);
}
template <class T>
void BSTree<T>::balanceHelper(std::vector<T> & list, int start, int end){
       if(start > end) return ;
       int mid = (start + end)/2;
       T leftMid = (start + mid)/2;
       T rightMid = (start + end)/2;
       if(insert(leftMid) == true) balanceHelper(list, start, mid);
       if(insert(rightMid) == true) balanceHelper(list, mid, end);
}

template <class T>
int BSTree<T>::height(){
       return findHeight(this->root);
}

template <class T>
int BSTree<T>::findHeight(Node * n){
       if(n == NULL) return -1;
       int lh = findHeight(n->left);
       int rh = findHeight(n->right);
       int max = (lh >= rh) ? lh : rh;
       return 1 + max;
}
#endif

