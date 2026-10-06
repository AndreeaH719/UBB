#include "SortedBag.h"
#include "SortedBagIterator.h"

SortedBag::SortedBag(Relation r) {
	this->capacity = 10;
	this->length = 0;
	this->elems = new TComp[this->capacity];
	this->rel = r;
}

void SortedBag::add(TComp e) {
	if (this->length == this->capacity)
	{
		this->capacity *= 2;
		TComp *newElems = new TComp[this->capacity];
		for(int i = 0; i < this->length; i++)
		    newElems[i] = this->elems[i];
		delete [] this->elems;
		this->elems = newElems;
	}
	int pos = 0;
	while(pos < this->length && this->rel(this->elems[pos], e))
	     pos++;
	for(int i = this->length - 1; i >= pos; --i)
	    this->elems[i+1] = this->elems[i];
	this->elems[pos] = e;
	this->length++;
	    
}
//BC: Theta(1) - the element is added at the end
//WC: Theta(length) - the element is added at the beginning
//TC: O(length) 


bool SortedBag::remove(TComp e) {
	int pos = -1;
	for (int i = 0; i < this->length; i++)
	{
		if (this->elems[i] == e)
		{
			pos = i;
			break;
		}
	}
	if(pos == -1)
	    return false;
	for(int i = pos; i < this->length - 1; i++)
	    this->elems[i] = this->elems[i+1];
	this->length--;
	return true;
}
//BC: Theta(length) - the element is the last
//WC: Theta(length) - the element is the first
//TC: Theta(length)


bool SortedBag::search(TComp elem) const {
	for(int i = 0; i < this->length; i++)
	    if(this->elems[i] == elem)
		    return true;
	return false;
}
//BC: Theta(1) - the elem is the first
//WC: Theta(length) - the elem is the last one
//TC: Theta(length)


int SortedBag::nrOccurrences(TComp elem) const {
	int c = 0;
	for(int i = 0; i< this->length; i++)
	    if(this->elems[i] == elem)
		   c++;
	return c;
}
//BC: Theta(length) - the elem does not exist
//WC: Theta(length) - the elem exist but we still need to go through the array
//TC: O(length)



int SortedBag::size() const {
	return this->length;
}
//BC=WC=TC: Theta(1)


bool SortedBag::isEmpty() const {
	return this->length == 0;
}
//BC=WC=TC: Theta(1)


SortedBagIterator SortedBag::iterator() const {
	return SortedBagIterator(*this);
}
//BC=WC=TC: Theta(1)

SortedBag::~SortedBag() {
	delete[] this->elems;
}
//BC=WC=TC: Theta(1)


SortedBag::SortedBag(const SortedBag& other)
{
	this->capacity = other.capacity;
	this->length = other.length;
	this->rel = other.rel;
	this->rel = other.rel;
	this->elems = new TComp[this->capacity];
	for(int i = 0; i < this->length; i++)
	   this->elems[i] = other.elems[i];
}
//BC=WC=TC: Theta(length)

SortedBag& SortedBag::operator=(const SortedBag& other)
{
	if (this != &other)
	{
		delete[] this->elems;

		this->capacity = other.capacity;
		this->length = other.length;
		this->rel = other.rel;
		this->rel = other.rel;
		this->elems = new TComp[this->capacity];
		for (int i = 0; i < this->length; i++)
			this->elems[i] = other.elems[i];

	}
	return *this;
}
//BC=WC=TC: Theta(length)