#include "tests.h"
#include "repo.h"
#include "service.h"
#include <cassert>
#include <stdexcept>

void test_add()
{
   Repo r;
   Service s(r);
   s.add("Vama", "Vama_Veche", "Ana", 332);
   TElem*e = s.get_all();
   int n = s.get_size();
   bool found = false;
   for (int i = 0; i < n; i++)
   {
	   if (e[i].getName() == "Vama")
	   {
		   found = true;
		   break;
	   }
   }
   assert(found == true);
}

void test_filter()
{
	Repo r;
	Service s(r);
	s.add("Vama", "Vama_Veche", "Ana", 332);
	s.add("Andra", "Vama_Veche", "Ana", 5);
	TElem* e = s.get_all();
	int n = s.get_size();
	bool found = false;
	s.filter();
	for (int i = 0; i < n; i++)
	{
		if (e[i].getName() == "Vama")
		{
			found = true;
			break;
        }
	}
	assert(found == true);
}

void tests::test_all()
{
	test_add();
	test_filter();
}