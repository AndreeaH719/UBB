#include "ListIterator.h"
#include "SortedIndexedList.h"
#include <iostream>

using namespace std;

ListIterator::ListIterator(const SortedIndexedList& list) : list(list) {
	current = list.head;
}
//BC=WC=TC=Theta(1)

void ListIterator::first(){
	current = list.head;
}
//BC=WC=TC=Theta(1)

void ListIterator::next(){
	if(!valid())
	   throw std::exception();
	current = current->next;
}
//BC=WC=TC=Theta(1)

bool ListIterator::valid() const{
	return current != nullptr;
}
//BC=WC=TC=Theta(1)

TComp ListIterator::getCurrent() const{
	if(!valid())
	   throw std::exception();
	return current->value;
}
//BC=WC=TC=Theta(1) 


