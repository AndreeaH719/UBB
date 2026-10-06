#include "repo.h"
#include <algorithm>

void Repo::add(const std::string& name, const std::string& team, int goals, int age)
{
	if(age < 0 || goals < 0)
	   throw std::runtime_error("must be > 0");
	TElem * e =this->array.get_all();
	int n = this->array.get_size();
	bool found = false;
	for (int i = 0; i < n; i++)
	{
		if (e[i].getName() == name)
		{
			found =  true;
			break;
		}
	}
	if(found)
	   throw std::runtime_error("already exisits");
	Player p{name, team, goals, age};
	this->array.add(p);
}

void Repo::remove(const std::string& name)
{
	TElem* e = this->array.get_all();
	int n = this->array.get_size();
	bool found = false;
	int poz = -1;
	for (int i = 0; i < n; i++)
	{
		if (e[i].getName() == name)
		{
			poz = i;
			break;
		}
	}
	if (poz == -1)
		throw std::runtime_error("doesn t exisits");
	this->array.remove(poz);
}

void Repo::update(const std::string& name, const std::string& new_team, int new_goals, int new_age)
{
	TElem* e = this->array.get_all();
	int n = this->array.get_size();
	bool found = false;
	for (int i = 0; i < n; i++)
	{
		if (e[i].getName() == name)
		{
		    e[i].setTeam(new_team);
			e[i].setGoals(new_goals);
			e[i].setAge(new_age);
			found = true;
			break;
		}
	}
	if (!found)
		throw std::runtime_error("already exisits");
}

bool cmpMode(const Player& a, const Player& b)
{
	return a.getGoals() > b.getGoals();
}

std::vector<Player> Repo::filter(int g)
{
	TElem* e = this->array.get_all();
	int n = this->array.get_size();
	std::sort(e, e+n, cmpMode);
	std::vector<Player> r;
	for (int i = 0;i < n; i++)
	{
		if (e[i].getAge() > g)
		{
			r.push_back(e[i]);
		}
	}
	return r;
}

int Repo::get_size() const
{
	return this->array.get_size();
}

TElem* Repo::get_all() const
{
	return this->array.get_all();
}