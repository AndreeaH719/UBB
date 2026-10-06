#include "service.h"

service::service(repo &r): re(r) {}

vector<aircraft*> service::display1(string filename, string activity)
{
	return re.display1(filename, activity);
}

vector<aircraft*> service::display2(int altitude)
{
	return re.display2(altitude);
}

vector<aircraft*> service::display()
{
	return re.display();
}

void service::add(aircraft* a)
{
	re.add(a);
}


