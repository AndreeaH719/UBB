#include "repo.h"
#include "service.h"
#include "ui.h"
#include "tests.h"
#include <iostream>

int main()
{
    tests t;
	t.test_all();
	std::cout << "ALL TESTS PASSED\n";
	Repo r;
	Service s(r);
	Ui u(s);
	u.run();
	return 0;
}