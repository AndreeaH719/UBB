#include "service.h"
#include "ui.h"
#include "Controller.h"

int main()
{
	Controller c;
	service s(c);
	s.addentities();
	ui u(s);
	u.run();
	return 0;
}