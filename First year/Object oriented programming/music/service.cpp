#include "service.h"
#include <vector>
#include <algorithm>
Service::Service(Repo &r): re(r) {}

void Service::add(const std::string& name, const std::string& album, const std::string& song, int wins)
{
	if(wins < 0)
	   throw std::runtime_error("The number must be positive");
	this->re.add(name,album, song, wins);
}

void Service::remove(const std::string& name)
{
	this->re.remove(name);
}

void Service::update(const std::string& name, const std::string& new_album, const std::string& new_song, int new_wins)
{
	if(new_wins < 0)
		throw std::runtime_error("The number must be positive");
	this->re.update(name, new_album, new_song, new_wins);
}

int Service::get_size() const
{
	return this->re.get_size();
}

TElem* Service::get_all() const
{
	return this->re.get_all();
}

bool cmpM(const Artist &a, const Artist &b)
{
   return a.getWins() > b.getWins();
	
}

std::vector<Artist> Service::filter()
{
	TElem * e = this->re.get_all();
	int n = this->re.get_size();
	std::sort(e, e+n, cmpM);
	std::vector<Artist> r;
	for (int i = 0; i < n; i++)
	{
		if(e[i].getWins() > 10)
		   r.push_back(e[i]);
	}
	return r;
}