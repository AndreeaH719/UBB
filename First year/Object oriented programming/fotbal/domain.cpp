#include "domain.h"

Player::Player(const std::string& name, const std::string& team, int goals, int age)
{
	this->name = name;
	this->team= team;
	this->goals=goals;
	this->age=age;
}
