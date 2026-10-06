#include "repo.h"
#include <assert.h>
#include <stdexcept>

void repo::add(const std::string& name, const std::string& team, int wins, int number)
{
    TElem *e = this->array.get_all();
	int n = this->array.get_size();
	for (int i = 0; i < n; i++)
	{
		if(e[i].getName() == name)
		   throw std::runtime_error("This driver has already a seat in F1");
	}
	Driver d{name,team,wins,number};
	this->array.add(d);
}

void repo::remove(const std::string& name)
{
	TElem* e = this->array.get_all();
	int n = this->array.get_size();
	int poz = -1;
	for (int i = 0; i < n; i++)
	{
		if (e[i].getName() == name)
		{
			poz = i;
			break;
		}
	}
	if(poz == -1)
	   throw std::runtime_error("This driver is not racing in F1 already");
	this->array.remove(poz);
}

void repo::update(const std::string& name, const std::string& new_team, int new_wins, int new_number)
{
	TElem* e = this->array.get_all();
	int n = this->array.get_size();
	bool found = false;
	for (int i = 0; i < n; i++)
	{
		if (e[i].getName() == name)
		{
			found = true;
			e[i].setTeam(new_team);
			e[i].setWins(new_wins);
			e[i].setNumber(new_number);
		}
	}
	if(!found)
	   throw std::runtime_error("This driver is not racing in F1");
}

int repo::get_size() const
{
	return this->array.get_size();
}

TElem* repo::get_all() const
{
	return this->array.get_all();
}
