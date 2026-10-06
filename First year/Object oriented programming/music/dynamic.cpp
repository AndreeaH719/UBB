#include "dynamic.h"

void DynamicArray::_resize()
{
	this->capacity *= 2;
	TElem* newBlock = new TElem[this->capacity];
	for (int i = 0; i < this->size_array; i++)
	{
		newBlock[i] = this->elems[i];
	}
	delete[] this->elems;
	this->elems = newBlock;
}

DynamicArray::DynamicArray(int initial_cap) : size_array(0), capacity(initial_cap)
{
	this->elems = new TElem[this->capacity];
}

void DynamicArray::add(TElem element)
{
	if (this->size_array == this->capacity)
		this->_resize();
	this->elems[this->size_array] = element;
	this->size_array++;
}

void DynamicArray::remove(int position)
{
	for (int i = position; i < this->size_array - 1; i++)
		this->elems[i] = this->elems[i + 1];
	this->size_array--;
}

DynamicArray::~DynamicArray()
{
	delete[] this->elems;
}