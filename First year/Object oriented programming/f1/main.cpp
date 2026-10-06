#include "repo.h"
#include "service.h"
#include "ui.h"
#include "teste.h"

int main()
{
    teste t;
	t.test_all();
	repo r;
	service s(r);
	ui u(s);
	s.grila();
	u.run();
	return 0;
}