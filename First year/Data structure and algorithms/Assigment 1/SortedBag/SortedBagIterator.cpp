#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>

using namespace std;

SortedBagIterator::SortedBagIterator(const SortedBag& b) : bag(b) {
	this->current  = 0;
}
//BC=WC=TC: Theta(1)

TComp SortedBagIterator::getCurrent() {
	if (!valid()) {
		throw std::exception(); 
	}
	return this->bag.elems[this->current];
}
//BC=WC=TC: Theta(1)

bool SortedBagIterator::valid() {
	return this->current >= 0 && this->current < this->bag.length;
}
//BC=WC=TC: Theta(1)

void SortedBagIterator::next() {
	if (!valid()) {
		throw std::exception(); 
	}
	this->current++;
}
//BC=WC=TC: Theta(1)

void SortedBagIterator::first() {
	this->current = 0;
}
//BC=WC=TC: Theta(1)
