#include "repo.h"
#include "service.h"
#include "ui.h"

int main()
{
	Repo r;
	Service s(r);
	s.players();
	Ui u(s);
	u.run();
	return 0;
}