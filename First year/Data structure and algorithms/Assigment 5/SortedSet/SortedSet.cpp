#include "SortedSet.h"
#include "SortedSetIterator.h"

SortedSet::SortedSet(Relation r) {
	this->rel = r;
	this->capacity=10;
	this->nodes = new Node[this->capacity];
	for (int i = 0;i < capacity; i++)
	{
		nodes[i].left=-1;
		nodes[i].right=-1;
	}
	this->root=-1;
	this->firstEmpty=0;
	this->length=0;
}
//BC=WC=AC=Theta(cap)

void SortedSet::resize() {
	int newCapacity = capacity * 2;
	Node* newNodes = new Node[newCapacity];

	for (int i = 0; i < capacity; i++) {
		newNodes[i] = nodes[i];
	}

	for (int i = capacity; i < newCapacity; i++) {
		newNodes[i].left = -1;
		newNodes[i].right = -1;
	}

	delete[] nodes;
	nodes = newNodes;

	firstEmpty = capacity;

	capacity = newCapacity;
}
//BC=WC=AC=Theta(cap)

bool SortedSet::add(TComp elem) {
	if (root == -1)
	{
		if(firstEmpty==capacity)
		    resize();
		root = firstEmpty;
		nodes[root].value=elem;
		nodes[root].left = nodes[root].right = -1;
		firstEmpty++;
		length++;
		return true;
	}

	int current = root;
	int parent = -1;

	while (current != -1)
	{
		if(nodes[current].value==elem)
		    return false;
		parent=current;
		if(rel(elem, nodes[current].value))
		   current = nodes[current].left;
		else
		   current=nodes[current].right;
	}
	if(firstEmpty==capacity)
	    resize();
	int newNode = firstEmpty;
	firstEmpty++;
	nodes[newNode].value=elem;
	nodes[newNode].left=nodes[newNode].right = -1;

	if(rel(elem, nodes[parent].value))
	   nodes[parent].left=newNode;
	else nodes[parent].right=newNode;
	length++;

	return true;
}
//BC=Theta(1):element we wnat to find is the root
//WC=Theta(size):element we want to find does not exist
//TC=O(size)

bool SortedSet::remove(TComp elem) {
	int current = root;
	int parent = -1;

	while (current != -1 && nodes[current].value != elem) {
		parent = current;
		if (rel(elem, nodes[current].value))
			current = nodes[current].left;
		else
			current = nodes[current].right;
	}

	if (current == -1)
		return false;

	if (nodes[current].left == -1 && nodes[current].right == -1)
	{
		if(current == root)
		   root = -1;
		else
		   if(nodes[parent].left == current)
		        nodes[parent].left=-1;
		   else nodes[parent].right=-1;
	
	}
	else if (nodes[current].left == -1 || nodes[current].right == -1) {
		int child;
		if (nodes[current].left != -1) {
			child = nodes[current].left;
		}
		else {
			child = nodes[current].right;
		}
		if (current == root) {
			root = child;
		}
		else {
			if (nodes[parent].left == current)
				nodes[parent].left = child;
			else
				nodes[parent].right = child;
		}
	}
	else {
		int successorParent = current;
		int successor = nodes[current].right;

		while (nodes[successor].left != -1) {
			successorParent = successor;
			successor = nodes[successor].left;
		}

		nodes[current].value = nodes[successor].value;

		if (nodes[successor].right != -1) {
			if (nodes[successorParent].left == successor)
				nodes[successorParent].left = nodes[successor].right;
			else
				nodes[successorParent].right = nodes[successor].right;
		}
		else {
			if (nodes[successorParent].left == successor)
				nodes[successorParent].left = -1;
			else
				nodes[successorParent].right = -1;
		}
		length--;
		return true;
	}
	length--;
	return true;
}
//BC=Theta(1):element we wnat to find is the root
//WC=Theta(size):element we want to find does not exist
//TC=O(size)


bool SortedSet::search(TComp elem) const {
	int current = root;

	while (current != -1) {
		if (nodes[current].value == elem)
			return true;

		if (rel(elem, nodes[current].value))
			current = nodes[current].left;
		else
			current = nodes[current].right;
	}

	return false;
}
//BC=Theta(1):element we wnat to find is the root
//WC=Theta(size):element we want to find does not exist
//TC=O(size)


int SortedSet::size() const {
	return length;
}
//BC=WC=AC=Theta(1)


bool SortedSet::isEmpty() const {
	return length==0;
}
//BC=WC=AC=Theta(1)

SortedSetIterator SortedSet::iterator() const {
	return SortedSetIterator(*this);
}


SortedSet::~SortedSet() {
	delete[] nodes;
}
//BC=WC=AC=Theta(1)


