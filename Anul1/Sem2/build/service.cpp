#include "service.h"

service::service(Controller &c): con(c) {}

void service::add(Building* b)
{
	con.add(b);
}

vector<Building*> service::getAll()
{
	return con.getAll();
}

vector<Building*> service::getAllRestored()
{
	return con.getAllRestored();
}

vector<Building*> service::getAllDemolished()
{
	return con.getAllDemolished();
}

void service::writeFile(string filename, vector<Building*> b)
{
	con.writeFile(filename, b);

}

void service::remove(string s)
{
	con.remove(s);
}