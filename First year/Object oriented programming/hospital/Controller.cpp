#include "Controller.h"
#include <algorithm>
#include <fstream>
using namespace std;

Controller::Controller() {}

void Controller::addDepartment(HospitalDepartment* d)
{
	elems.push_back(d);
}

vector<HospitalDepartment*> Controller::getAllDepartments()
{
	return elems;
}

vector<HospitalDepartment*> Controller::getAllEfficients()
{
	vector<HospitalDepartment*> r;
	for(const auto d: elems)
	    if(d->isEfficient()) r.push_back(d);
	return r;
}

bool cmpMode(HospitalDepartment* a, HospitalDepartment* b)
{
	return a->getName() < b->getName();
}

void Controller::writeToFile(string filename)
{
	vector<HospitalDepartment*> r = getAllDepartments();
	sort(r.begin(), r.end(), cmpMode);
	ofstream fout(filename);
	string re, t;
	for (const auto d : r)
	{
	    if(d->isEfficient()) re = "is efficient";
		else re = "is not efficient";
		if(d->toString().size() < 13) t = "Unit";
		else t = "Surgery";
		fout << t << " " << d->toString() << " " << re << "\n";
	} 
}