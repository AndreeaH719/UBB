#include "dynamic.h"

Dynamic::Dynamic(int inital) : size(0), capacity(2)
{
	this->elems = new TElem[this->capacity];
}

Dynamic::~Dynamic()
{
	delete[] this->elems;
}

void Dynamic::_resize()
{
	this->capacity *= 2;
	TElem* new_block = new TElem[this->capacity];
	for(int i = 0; i < this->size; i++)
	    new_block[i] = this->elems[i];
	delete[] this->elems;
	this->elems = new_block;
}

void Dynamic::add(TElem e)
{
	if(this->size == this->capacity)
	     this->_resize();
	this->elems[this->size] = e;
	this->size++;
}

void Dynamic::remove(int poz)
{
	for(int i = poz; i < this->size - 1; i++)
	   this->elems[i] = this->elems[i+1];
	this->size--;
}
