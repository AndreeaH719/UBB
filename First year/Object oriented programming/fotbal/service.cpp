#include "service.h"


Service::Service(Repo &r): re(r) {}

void Service::add(const std::string& name, const std::string& team, int goals, int age)
{
	this->re.add(name,team,goals,age);
}

void Service::remove(const std::string& name)
{
	this->re.remove(name);
}

void Service::update(const std::string& name, const std::string& new_team, int new_goals, int new_age)
{
	this->re.update(name, new_team, new_goals,new_age);
}

int Service::get_size() const
{
	return this->re.get_size();
}

TElem* Service::get_all() const
{
	return this->re.get_all();
}

std::vector<Player> Service::filter(int g)
{
	return this->re.filter(g);
}

void Service::players()
{
	this->re.add("Ianis Hagi", "FCSB", 3, 28);
	this->re.add("Gavi", "FCB", 23, 21);
	this->re.add("Dennis Man", "nationala", 4, 26);
	this->re.add("Dragusin", "CFR", 45, 30);
	this->re.add("Razvan", "U Cluj", 23, 20);
}