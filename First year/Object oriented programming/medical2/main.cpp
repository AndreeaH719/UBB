#include "ui.h"
#include "service.h"
#include "Person.h"

int main()
{
	Person p;
	service s(p);
	s.entities();
	ui u(s);
	u.run();
	return 0;
}