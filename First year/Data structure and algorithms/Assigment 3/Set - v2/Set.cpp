#include "Set.h"
#include "SetIterator.h"

Set::Set() {
	cap = 100000;
	elems = new TElem[cap];
	next = new int[cap];

	for (int i = 0; i < cap - 1; i++)
		next[i] = i + 1;

	next[cap - 1] = -1;

	head = -1;
	firstEmpty = 0;
}

bool Set::add(TElem elem) {
	if (firstEmpty == -1)
		return false;
	if (search(elem))
		return false;

	int newPos = firstEmpty;
	firstEmpty = next[newPos];

	elems[newPos] = elem;

	next[newPos] = head;
	head = newPos;

	return true;
}
//from search function
//BC=Theta(1) - the element we want to find is the first one
//WC = Theta(n) - the element is not in the list
//AC = O(n)

bool Set::remove(TElem elem) {
	int current = head;
	int previous = -1;

	while (current != -1 && elems[current] != elem)
	{
		previous = current;
		current = next[current];
	}

	if(current == -1) return false;

	if(previous == -1)
	     head = next[current];
	else
	     next[previous] = next[current];

	next[current] = firstEmpty;
	firstEmpty = current;
	return true;
}
//BC=Theta(1) - the element we want to remove is the first one
//WC = Theta(n) - the element is not in the list
//AC = O(n)

bool Set::search(TElem elem) const {
	int current = head;
	while (current != -1)
	{
		if(elems[current] == elem) return true;
		current = next[current];
	}
	return false;
}
//BC=Theta(1) - the element we want to find is the first one
//WC = Theta(n) - the element is not in the list
//AC = O(n)


int Set::size() const {
	int count = 0;
	int current = head;

	while (current != -1)
	{
		count++;
		current = next[current];
	}
	return count;
}
//BC=WC=AC=Theta(count)


bool Set::isEmpty() const {
	return head == -1;
}
//BC=WC=AC=Theta(1)


Set::~Set() {
	delete [] elems;
	delete[] next;
}


SetIterator Set::iterator() const {
	return SetIterator(*this);
}


