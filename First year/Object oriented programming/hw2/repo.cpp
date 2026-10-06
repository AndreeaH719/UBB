#include "repo.h"
#include "fstream"

repo::repo() {}

void repo::add(aircraft* a)
{
	elems.push_back(a);
}

vector<aircraft*> repo::display()
{
	return elems;
}

vector<aircraft*> repo::display1(string filename, string activity)
{
	vector<aircraft*> r;
	for (const auto a : elems)
	{
		if(a->isSuitable(activity)) 
		    r.push_back(a);
	}
	ofstream fout(filename);
	for(const auto a: r)
	    fout << a->toString() << "\n";
	return r;
}

vector<aircraft*> repo::display2(int altitude)
{
	vector<aircraft*> r;
	for(const auto a:elems)
	    if(a->maxAltitude() >= altitude)
		      r.push_back(a);
	return r;
}