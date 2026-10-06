#include "repo.h"
#include <vector>

void Repo::add(const std::string& name, int age, const std::string& infect, int room)
{
	Patient p{name,age,infect,room};
	this->array.add(p);
}


std::vector<Patient> Repo::update(int a)
{
   TElem *e = this->array.get_all();
   int n = this->array.get_size();
   std::vector<Patient> infected;
   for (int i = 0; i < n; i++)
   {
	   if (e[i].getInfect() == "true")
	   {
		   int r = e[i].getRoom();
		   if (std::find(infected.begin(), infected.end(), e[i]) == infected.end())
			   infected.push_back(e[i]);
		   for (int j = 0; j < n; j++)
		   {
			   if (e[j].getRoom() == r && e[j].getInfect() == "false" && e[j].getAge() > a)
			   {
					e[j].setInfect("true");
					if (std::find(infected.begin(), infected.end(), e[j]) == infected.end())
						infected.push_back(e[j]);
			   } 
		   }
	   }
   }
   return infected;

}


int Repo::get_size() const
{
	return this->array.get_size();
}

TElem* Repo::get_all() const
{
	return this->array.get_all();
}