#include "ui.h"
#include "service.h"
#include "Controller.h"

int main()
{
	Controller c;
	service s(c);
	ui u(s);
	u.run();
	return 0;
}