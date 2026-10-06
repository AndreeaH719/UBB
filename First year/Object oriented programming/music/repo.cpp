#include "repo.h"
#include <assert.h>
#include <stdexcept>


void Repo::add(const std::string& name, const std::string& album, const std::string& song, int wins)
{
   Artist a{name, album, song, wins};
	this->array.add(a);
}

void Repo::remove(const std::string& name)
{
	TElem*e = this->array.get_all();
	int n = this->array.get_size();
	int poz = 1;
	for (int i = 0; i < n; i++)
	{
		if (e[i].getName() == name)
		{
			poz = i;
			break;
		}
	}
	if(poz == -1)
	   throw std::runtime_error("No artsit found");
	this->array.remove(poz);
}


void Repo::update(const std::string& name, const std::string& new_album, const std::string& new_song, int new_wins)
{
	TElem* e = this->array.get_all();
	int n = this->array.get_size();
	bool found = false;
	for (int i = 0; i < n; i++)
	{
		if (e[i].getName() == name)
		{
			e[i].setAlbum(new_album);
			e[i].setSong(new_song);
			e[i].setWins(new_wins);
			found = true;
		}
	}
	if(!found)
	    throw std::runtime_error("No artist found");
}

int Repo::get_size() const
{
	return this->array.get_size();
}

TElem* Repo::get_all() const
{
	return this->array.get_all();
}