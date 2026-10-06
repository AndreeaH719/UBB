#include "Controller.h"
#include "service.h"
#include "ui.h"

int main()
{
	Controller c;
	service s(c);
	ui u(s);
	u.run();
	return 0;
}