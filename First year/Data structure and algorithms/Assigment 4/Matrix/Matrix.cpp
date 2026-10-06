#include "Matrix.h"
#include <exception>
using namespace std;

int Matrix::hashFunction(int i, int j) const {
	return (i*cols + j) % capacity;
}
//BC=WC=AC=Theta(1);  

void Matrix::resizeAndRehash()
{
	int oldcap = capacity;
	Node** oldtable = table;
	
	capacity = capacity * 2;

	table = new Node * [capacity];

	for (int i = 0; i < capacity; i++)
		table[i] = nullptr;

	size = 0;

	for (int i = 0; i < oldcap; i++)
	{
		Node* current = oldtable[i];

		while (current != nullptr)
		{
			Node* next = current->next;

			int pos = hashFunction(current->line, current->column);

			Node* p = table[pos];
			Node* prev = nullptr;

			while (p != nullptr &&
				(p->line < current->line ||
					(p->line == current->line &&
						p->column < current->column)))
			{
				prev = p;
				p = p->next;
			}

			current->next = p;

			if (prev == nullptr)
				table[pos] = current;
			else
				prev->next = current;

			size++;

			current = next;
		}
	}

	delete[] oldtable;
}
//BC=Theta(size): the old table had only one element in each list
//WC=Theta(size^2): all the elements are on the same position in the table
//AC=O(size^2);

Matrix::Matrix(int nrLines, int nrCols) {  
	if(nrLines <= 0 || nrCols <= 0)
	    throw std::exception();
	lines = nrLines;
	cols = nrCols;
	size = 0;
	capacity=17;
	table = new Node*[capacity];

	for(int i = 0; i < capacity; i++)
	    table[i] = nullptr;
}


int Matrix::nrLines() const {
	return lines;
}
//BC=WC=AC=Theta(1);

int Matrix::nrColumns() const {
	return cols;
}
//BC=WC=AC=Theta(1);

TElem Matrix::element(int i, int j) const {
	if(i < 0 || i >= lines || j < 0 || j >= cols)
	    throw std::exception();
	int pos = hashFunction(i, j);
	Node*current = table[pos];
	while (current != nullptr)
	{
		if(current->line == i && current->column == j)
		    return current->value;
		current = current->next;
	}
	return NULL_TELEM;
}
//BC=Theta(1): the element is found after the first iteration
//WC=Theta(size): the element is not found
//AC=O(size)

TElem Matrix::modify(int i, int j, TElem e) {
	if (i < 0 || i >= lines || j < 0 || j >= cols)
		throw std::exception();

	int pos = hashFunction(i, j);

	Node* current = table[pos];
	Node* prev = nullptr;

	while (current != nullptr &&
		(current->line < i ||
			(current->line == i && current->column < j))) {

		prev = current;
		current = current->next;
	}

	if (current != nullptr &&
		current->line == i &&
		current->column == j) {

		TElem old = current->value;

		if (e == NULL_TELEM) {

			if (prev == nullptr)
				table[pos] = current->next;
			else
				prev->next = current->next;

			delete current;
			size--;
		}
		else {
			current->value = e;
		}

		return old;
	}

	if (e != NULL_TELEM) {

		Node* newNode = new Node;
		newNode->line = i;
		newNode->column = j;
		newNode->value = e;

		newNode->next = current;

		if (prev == nullptr)
			table[pos] = newNode;
		else
			prev->next = newNode;

		size++;

		if ((double)size / capacity > alpha)
			resizeAndRehash();
	}

	return NULL_TELEM;
}
//BC=Theta(1): the element I have to modify is on the first position
//WC=Theta(size): the element is not in the table yet
//AC=O(size);