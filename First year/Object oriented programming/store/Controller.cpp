#include "Controller.h"
#include <fstream>
#include <algorithm>

Controller::Controller() {}

void Controller::add(Appliance* a)
{
    for(const auto b: elems)
	    if(b->getId() == a->getId()) throw runtime_error("duplicate");
	elems.push_back(a);
}

bool cmpMode(Appliance* a, Appliance* b)
{
	return a->getWeight() < b->getWeight();

}
vector<Appliance*> Controller::getAll()
{
	vector<Appliance*> r = elems;
	sort(r.begin(), r.end(), cmpMode);
	return r;
}

vector<Appliance*> Controller::getAllWithConsumedElec(double elec)
{
	vector<Appliance*> r;
	for(const auto a:elems)
	    if(a->consumedEnergy() < elec) r.push_back(a);
	return r;
}

void Controller::writeToFile(string filename, double elec)
{
	vector<Appliance*> r = getAllWithConsumedElec(elec);
	ofstream fout(filename);
	for(const auto a: r)
	    fout << a->toString() << "\n";
}