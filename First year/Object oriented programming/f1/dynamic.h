#pragma once
#include "domain.h"

typedef Driver TElem;

class DynamicArray
{
private:
	TElem* elems;
	int size_array;
	int capacity;
	void _resize();
public:
	DynamicArray(int initial_cap = 2);
	void add(TElem element);
	void remove(int position);
	int get_size() const { return this->size_array; }
	TElem* get_all() const { return this->elems; }
	~DynamicArray();
};