#include "repo.h"
#include <fstream>
#include <algorithm>
repo::repo(std::string filename)
{
	this->filename=filename;
	loadData();
}

void repo::add(const Session& s)
{
	elems.push_back(s);
	writeData();
}

void repo::loadData()
{
	std::ifstream fin(filename);
	Session s;
	while(fin >> s)
	    elems.push_back(s);
}

void repo::writeData()
{
	std::ofstream fout(filename);
	for(const auto&s:elems)
	    fout << s << "\n";
}

bool cmpMode(const Session& a, const Session& b)
{
	return a.getStart() < b.getStart();
}

std::vector<Session> repo::getAll()
{
	std::vector<Session> v = elems;
	sort(v.begin(), v.end(), cmpMode);
	return v;
}
