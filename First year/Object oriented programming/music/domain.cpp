#include "domain.h"


Artist::Artist(const std::string& name, const std::string& album, const std::string& song, int wins)
{
	this->name = name;
	this->album = album;
	this->song = song;
	this->wins =wins;
}