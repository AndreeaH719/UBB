#include "test.h"
#include "repo.h"
#include "service.h"
#include <cassert>
#include <stdexcept>

void test_add()
{
   Repo r;
   Service s(r);
   s.add("Adriana", 23, "false", 81);
   TElem* e = s.get_all();
   int n = s.get_size();
   bool found = false;
   for (int i = 0; i < n; i++)
   {
	   if (e[i].getName() == "Adriana")
	   {
		   found = true;
		   break;
	   }
   }
   assert(found == true);
}

void test_update()
{
	Repo r;
	Service s(r);
	s.add("Adriana", 23, "false", 81);
	s.add("Alex", 25, "true", 81);
	int a = 20;
	TElem* e = s.get_all();
	int n = s.get_size();
	bool found = false;
	s.update(a);
	for (int i = 0; i < n; i++)
	{
		if(e[i].getName() == "Adriana")
		   if(e[i].getInfect() == "true")
		      found = true;
	}
	assert(found == true);
}

void test::test_all()
{
	test_add();
	test_update();
}