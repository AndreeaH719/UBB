#include "domain.h"


Driver::Driver(const std::string& name, const std::string& team, int wins, int number)
{
	this->name = name;
	this->team = team;
	this->wins = wins;
	this->number = number;
}