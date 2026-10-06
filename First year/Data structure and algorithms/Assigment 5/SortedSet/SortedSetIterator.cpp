#include "SortedSetIterator.h"
#include <exception>

using namespace std;

SortedSetIterator::SortedSetIterator(const SortedSet& m) : multime(m)
{
	stacksize = multime.size() + 5;
	stack = new int[stacksize];
	stacktop=-1;
	current = multime.root;
	first();
}
//BC=WC=AC=Theta(1)

void SortedSetIterator::first() {
	stacktop = -1;

	int node = multime.root;

	while (node != -1) {
		stack[++stacktop] = node;
		node = multime.nodes[node].left;
	}

	if (stacktop != -1)
		current = stack[stacktop];
	else
		current = -1;
}
//BC=Theta(1):the root does not have a left child
//WC=Theta(size)
//TC=O(size)

void SortedSetIterator::next() {
	if (!valid())
		throw std::exception();

	int node = stack[stacktop--];

	if (multime.nodes[node].right != -1) {
		int t = multime.nodes[node].right;

		while (t != -1) {
			stack[++stacktop] = t;
			t = multime.nodes[t].left;
		}
	}

	if (stacktop != -1)
		current = stack[stacktop];
	else
		current = -1;
}
//BC=Theta(1):the root does not have a rigth child
//WC=Theta(size)
//TC=O(size)

TElem SortedSetIterator::getCurrent()
{
	if (!valid())
		throw std::exception();
	return multime.nodes[current].value;
}
//BC=WC=AC=Theta(1)

bool SortedSetIterator::valid() const {
	return current!=-1;
}
//BC=WC=AC=Theta(1)

