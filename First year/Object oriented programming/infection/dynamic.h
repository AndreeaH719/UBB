#pragma once
#include "domain.h"

typedef Patient TElem;

class Dynamic
{
private:
	TElem* elems;
	int size_array;
	int capacity;
	//double the size of the array when capacity gets equal to the size
	void _resize();
public:
	//constructor for the array, allocate the memory
	Dynamic(int initial_cap = 2);
	//DynamicArray(const DynamicArray& other);
	//DynamicArray& operator = (const DynamicArray& other);
	//add an element Coat to the array
	void add(TElem element);
	//remove an element from the array
	void remove(int position);
	//get the size of the array at the moment
	int get_size() const { return this->size_array; }
	//get all the elements from the array
	TElem* get_all() const { return this->elems; }
	//destructor, free the memory
	~Dynamic();
};