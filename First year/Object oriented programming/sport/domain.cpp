#include "domain.h"

Session::Session(int start, int end, std::string type, int level, std::string description)
{
	this->start=start;
	this->end=end;
	this->type=type;
	this->level=level;
	this->description=description;
}
