#include "service.h"
#include <algorithm>

service::service(repo& r): re(r)
{
}

void service::add(const std::string& name, const std::string& team, int wins, int number)
{
	this->re.add(name, team, wins, number);
}

void service::remove(const std::string& name)
{
	this->re.remove(name);
}

void service::update(const std::string& name, const std::string& new_team, int new_wins, int new_number)
{
	this->re.update(name, new_team, new_wins, new_number);
}

int service::get_size() const
{
	return this->re.get_size();
}

TElem* service::get_all() const
{
	return this->re.get_all();
}


bool cmpMode(const Driver& a, const Driver& b)
{
	return a.getWins() > b.getWins();
}

void service::sort_d()
{
	TElem* e = this->re.get_all();
	int n = this->re.get_size();
	std::sort(e, e+n, cmpMode);
}


std::vector<Driver> service::filter()
{
	TElem* e = this->re.get_all();
	int n = this->re.get_size();
	std::vector<Driver> result;
	for (int i = 0; i < n; i++)
	{
		if(e[i].getNumber() > 20)
		   result.push_back(e[i]);
	}
	return result;
}

void service::grila()
{
	this->re.add("Piastri", "McLaren", 7, 81);
	this->re.add("Verstapen", "RedBull", 50, 3);
	this->re.add("Kimi", "Mercedes", 1, 12);
	this->re.add("Leclerc", "Ferrari", 6, 16);
	this->re.add("Ollie", "Haas", 0, 87);
}