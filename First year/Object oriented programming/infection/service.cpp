#include "service.h"
#include <cassert>
#include <stdexcept>

Service::Service(Repo &r): re(r) {}

void Service::add(const std::string& name, int age, const std::string& infect, int room)
{
	TElem*e = this->re.get_all();
	int n = this->re.get_size();
	bool found = false;
	for (int i = 0; i < n; i++)
	{
		if (e[i].getName() == name)
		{
			found = true;
			break;
		}
	}
	if(found)
	    throw std::runtime_error("Already exists");
	this->re.add(name,age,infect,room);
}

std::vector<Patient> Service::update(int a)
{
	if(a < 0)
	   throw std::runtime_error("Must be > 0");
	return this->re.update(a);
}

int Service::get_size() const
{
	return this->re.get_size();
}

TElem* Service::get_all() const
{
	return this->re.get_all();
}

void Service::pacients()
{
	this->re.add("Ana", 25, "true", 3);
	this->re.add("Victoria", 34, "false", 3);
	this->re.add("Adi", 14, "false", 3);
	this->re.add("Andi", 27, "false", 2);
	this->re.add("Stefan", 38, "true", 2);

}