#include "Controller.h"
#include <fstream>
#include <assert.h>
#include <stdexcept>
#include <algorithm>
Controller::Controller() {}

void Controller::add(Building* b)
{
    for(const auto a:elems)
	     if(a == b) throw runtime_error("duplicate");
	elems.push_back(b);
}

bool cmpMode(Building* a, Building* b)
{
	return a->getYear() < b->getYear();
}

vector<Building*> Controller::getAll()
{
    vector<Building*> b = elems;
	sort(b.begin(), b.end(), cmpMode);
	return b;;
}

void Controller::remove(string s)
{
	for (auto it = elems.begin(); it != elems.end(); ++it)
	{
		if((*it)->getAddress().find(s) != string::npos)
		     {elems.erase(it); return;}
		
	}
}

vector<Building*> Controller::getAllRestored()
{
	vector<Building*> r;
	for(const auto b: elems)
	    if(b->mustBeRestored()) r.push_back(b);
	return r;
}

vector<Building*> Controller::getAllDemolished()
{
	vector<Building*> r;
	for (const auto b : elems)
		if (b->canBeDemolished()) r.push_back(b);
	return r;
}

void Controller::writeFile(string filename, vector<Building*> b)
{
	ofstream fout(filename);
	for(const auto a: b)
	      fout << a->toString() << "\n";
	    
}