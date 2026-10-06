#include "ListIterator.h"
#include "SortedIndexedList.h"
#include <iostream>
using namespace std;
#include <exception>

SortedIndexedList::SortedIndexedList(Relation r) {
	this->head = nullptr;
	this->tail = nullptr;
	this->nr_el = 0;
	this->rel = r;
}

int SortedIndexedList::size() const {
	return nr_el;
}
//BC=WC=TC=Theta(1)

bool SortedIndexedList::isEmpty() const {
	return nr_el == 0;
}
//BC=WC=TC=Theta(1)

TComp SortedIndexedList::getElement(int i) const{
	if(i < 0 || i >= nr_el)
	    throw std::exception();
	Node *current = head;
	int pos = 0;
	while (pos < i)
	{
		current = current->next;
		pos++;
	}
	return current->value;
}
//BC=Theta(1) - the element is on the first position
//WC=Theta(nr_el) - the elements is on the last position
//TC=O(nr_el)

TComp SortedIndexedList::remove(int i) {
	if(i < 0 || i >= nr_el)
	    throw std::exception();
	Node * current = head;
	int pos = 0;
	while (pos < i) {
		current = current->next;
		pos++;
	}
	TComp r_value = current->value;

	if (head == tail)
	{
		head = nullptr;
		tail = nullptr;
	}
	else if (current == head)
	{
		head = head->next;
	    head->prev = nullptr;
	}
	else if (current == tail)
	{
		tail = tail->prev;
	    tail->next = nullptr;
	}
	else
	{
		current->prev->next = current->next;
		current->next->prev = current->prev;
	}
	delete current;
	nr_el--;
	return r_value;
}
//BC=Theta(1) - the element is on the first position
//WC=Theta(nr_el) - the elements is on the last position
//TC=O(nr_el)

int SortedIndexedList::search(TComp e) const {
	Node * current = head;
	int pos = 0;
	while (current != nullptr)
	{
		if(current->value == e)
		    return pos;
		current = current->next;
		pos++;
	}
	return -1;
}
//BC=Theta(1) - the element is on the first position
//WC=Theta(nr_el) - the elements is on the last position
//TC=O(nr_el)

void SortedIndexedList::add(TComp e) {
	Node *newNode = new Node;
	newNode->value = e;
	newNode->next = nullptr;
	newNode->prev = nullptr;

	if (head == nullptr)
	{
		head = newNode;
		tail = newNode;
		nr_el++;
		return;
	}

	Node *current = head;
	while (current != nullptr && rel(current->value, e))
	{
		current = current->next;
	}

	if (current == nullptr)
	{
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}
	else if (current == head)
	{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	else
	{
		newNode->next = current;
		newNode->prev = current->prev;
		current->prev->next = newNode;
		current->prev = newNode;
	}
	nr_el++;
}
//BC=Theta(1) - the element is added on the first position
//WC=Theta(nr_el) - the element is added on the last position
//TC=O(nr_el)

ListIterator SortedIndexedList::iterator(){
	return ListIterator(*this);
}

//destructor
SortedIndexedList::~SortedIndexedList() {
	Node *current = head;
	while (current != nullptr)
	{
		Node *nextNode = current->next;
		delete current;
		current = nextNode;
	}
	head = nullptr;
	tail = nullptr;
	nr_el = 0;
}
//BC=WC=TC=Theta(nr_el)
