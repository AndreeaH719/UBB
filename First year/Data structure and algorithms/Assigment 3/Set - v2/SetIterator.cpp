#include "SetIterator.h"
#include "Set.h"
#include <stdexcept>

SetIterator::SetIterator(const Set& m) : set(m)
{
	current = set.head;
}
//BC=WC=AC=Theta(1)

void SetIterator::first() {
	current = set.head;
}
//BC=WC=AC=Theta(1)

void SetIterator::next() {
	if(!valid()) throw std::exception();
	current = set.next[current];
}
//BC=WC=AC=Theta(1)

TElem SetIterator::getCurrent()
{
	if(!valid()) throw std::exception();
	return set.elems[current];
}
//BC=WC=AC=Theta(1)

bool SetIterator::valid() const {
	return current != -1;
}
//BC=WC=AC=Theta(1)



