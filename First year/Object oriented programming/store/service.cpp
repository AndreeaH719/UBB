#include "service.h"


service::service(Controller &c): con(c) {}

void service::add(Appliance* a)
{
	con.add(a);
}

vector<Appliance*> service::getAll()
{
	return con.getAll();
}

vector<Appliance*> service::getAllWithConsumedElec(double elec)
{
	return con.getAllWithConsumedElec(elec);
}

void service::writeToFile(string filename, double elec)
{
	con.writeToFile(filename, elec);
}