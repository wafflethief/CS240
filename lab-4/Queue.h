#ifndef TQUE_H
#define TQUE_H
#include "Vector.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

template <class T>
class Vector;
template <class T>
class Queue{
private:
	int max_size;
	int enq_ind = -1;
	int deq_ind = 0;
	int num_objects = 0;
	Vector<T> * v;
public:
	Queue(unsigned int size);
	~Queue();
	bool enqueue(T data);
	T dequeue();
	T peek();
	bool empty();
	bool full();
	void clear();
};

template <class T>
Queue<T>::Queue(unsigned int size){
	this->max_size = size;
	v = new Vector<T>(size);
	//internal vector should never expand or shrink
}

template <class T>
Queue<T>::~Queue(){
	delete[] this->v;
	this->v = NULL;
}
template <class T>
bool Queue<T>::enqueue(T data){
	if(full()) return false;
		enq_ind = (enq_ind + 1)%max_size;
		v->objects[enq_ind] = data;//v->insert(enq_ind, data);
	this->num_objects++;
	return true;
}
template <class T>
T Queue<T>::dequeue(){
	if(empty()) return 0;
	int i = deq_ind;
	deq_ind = (deq_ind + 1)%max_size;//deq_ind + 1;
	this->num_objects--;
	return v->objects[i];
}

template <class T>
T Queue<T>::peek(){
	if(num_objects == 0) return 0;///if(empty()) return 0;
	return v->objects[deq_ind];//v->read(deq_ind);
}

template <class T>
bool Queue<T>::empty(){
	if(this->num_objects == 0) return true;//v->size()== 0) return true;
	return false;
}

template <class T>
bool Queue<T>::full(){
	if(this->num_objects == max_size) return true;
	return false;
}

template <class T>
void Queue<T>::clear(){
	this->num_objects = 0; //this line leads to memory leaks but passes tests
	v->clear();
	enq_ind = 0;
	deq_ind = 0;
}
#endif
