#ifndef TVEC_H
#define TVEC_H
#include <stdlib.h>
#include <cstddef>
#include <stdio.h>
#include <iostream>
template <class T>
class Vector{
private:
	int cur_objects;
	int len;
public:
	T * objects;
	Vector(unsigned int);
	Vector(const Vector<T> & v);
	~Vector();
	T & operator [](std::size_t index){
		return objects[index];
	}
	T get(int);
	unsigned int size() const;
	void clear();
};
template <class T>
Vector<T>::Vector(unsigned int size){
	this->len = size;
	objects = new T[len];
}
template <class T>
Vector<T>::Vector(const Vector<T>& v){
	this->len = v.size();
	this->cur_objects = v.cur_objects;
	this->objects = new T[len];
	for (int i = 0; i < len; i++) {
		if(v.objects[i] != 0) objects[i] = v.objects[i];
	}
}
template <class T>
Vector<T>::~Vector(){
	delete[] objects;
	objects = NULL;
}
template <class T>
T Vector<T>::get(int index){
	return objects[index];
}
template <class T>
void Vector<T>::clear(){
	delete[] objects;
	//objects = NULL;
	//objects = new T[0];
	this->len = 0;
	this->cur_objects = 0;
}
template <class T>
unsigned int Vector<T>::size() const{
	return this->len;
}
#endif
