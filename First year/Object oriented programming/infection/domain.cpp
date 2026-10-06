#include "domain.h" 

Patient::Patient(const std::string& name, int age, const std::string& infect, int room)
{
	this->name = name;
	this->age =age;
	this->infect=infect;
	this->room=room;
}
