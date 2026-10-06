#include "teste.h"
#include "repo.h"
#include "service.h"
#include "ui.h"
#include <assert.h>

void test_add()
{
	repo r;
	service s(r);
	s.add("Russel", "Mercedes", 5, 43);
	TElem* e = s.get_all();
	int n = s.get_size();
	bool found = false;
	for (int i = 0; i < n; i++)
	{
		if (e[i].getName() == "Russel")
		{
			found = true;
			break;
		}
	}
	assert(found == true);
}

void teste::test_all()
{
	std::cout << "All test passed\n";
	test_add();
}