#include "service.h"


service::service(repo& r):re(r) {}

void service::add(std::string category, std::string name, int quantity)
{
	List l{category, name, quantity};
	re.add(l);
}

std::vector<List> service::getAll()
{
	return re.getAll();
}

void service::remove(std::string name)
{
	re.remove(name);
}

void service::addentities()
{
	List a{"Drink", "juice", 4};
	List b{"Drink", "water", 3};
	List c{"Dairy", "milk", 1};
	List d{"dfsv", "sdv", 2};
	re.add(a);
	re.add(b);
	re.add(c);
	re.add(d);
}