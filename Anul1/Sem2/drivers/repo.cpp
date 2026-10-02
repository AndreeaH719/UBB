#include "repo.h"
#include <fstream>
#include <assert.h>
#include <stdexcept>

repo::repo(const std::string& filename)
{
	this->filename = filename;
	loadFile();
}

void repo::loadFile()
{
	std::ifstream fin(filename);
	if(!fin.is_open())
	     throw std::runtime_error("error");
	elems.clear();
	Driver d;
	while(fin >> d)
	{
		elems.push_back(d);
	}
}

void repo::saveFile()
{
    std::ofstream fout(filename);
	if(!fout.is_open())
	    throw std::runtime_error("error");
	for(const auto &d:elems)
	    fout << d << "\n";
}

void repo::add(const Driver&d)
{
    for(const auto&driver:elems)
	    if(driver==d)
		    throw std::runtime_error("duplicate");
	this->elems.push_back(d);
	saveFile();
}

void repo::remove(int number)
{
	for (int i = 0; i < elems.size(); i++)
	{
		if (elems[i].getNumber() == number)
		{
			this->elems.erase(elems.begin() + i);
			saveFile();
			return;
		}
	}
	throw std::runtime_error("it does not exist");
}

void repo::update(const std::string& name, int new_number, int new_wins)
{
	for (int i = 0; i < elems.size(); i++)
	{
		if (elems[i].getName() == name)
		{
			elems[i].setNumber(new_number);
			elems[i].setWins(new_wins);
			saveFile();
			return;
		}
	}
	throw std::runtime_error("it does not exist");
}

int repo::getSize() const
{
	return elems.size();
}

std::vector<Driver>& repo::getAll()
{
	return elems;
}