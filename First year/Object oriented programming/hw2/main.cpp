#include "repo.h"
#include "service.h"
#include "ui.h"

int main()
{
	repo r;
	service s(r);
	ui u(s);
	u.run();
	return 0;
}