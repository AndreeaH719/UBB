#include "repo.h"
#include <fstream>
#include <algorithm>
repo::repo(std::string filename)
{
	this->filename=filename;
	loadData();
}

void repo::loadData()
{
	std::ifstream fin(filename);
	List l;
	while(fin >> l)
	    elems.push_back(l);
}

void repo::writeData()
{
	std::ofstream fout(filename);
	for(const auto&l:elems)
	     fout << l << "\n";
}

void repo::add(const List& l)
{
	elems.push_back(l);
	writeData();
}



bool cmpMode(const List& a, const List& b)
{
	return a.getName() < b.getName();
}

std::vector<List> repo::getAll()
{
	std::vector<List> v= elems;
	sort(v.begin(), v.end(), cmpMode);
	return v;
}

void repo::remove(std::string name)
{
	for(auto it = elems.begin(); it != elems.end(); ++it)
	    if(it->getName() == name)
		    { elems.erase(it); break;}
	writeData();
}