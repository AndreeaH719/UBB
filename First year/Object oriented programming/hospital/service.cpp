#include "service.h"
#include "Surgery.h"
#include "Unit.h"
service::service(Controller& c): con(c) {}

void service::addDepartment(HospitalDepartment* d)
{
	con.addDepartment(d);
}

vector<HospitalDepartment*> service::getAllDepartments()
{
	return con.getAllDepartments();
}

vector<HospitalDepartment*> service::getAllEfficients()
{
	return con.getAllEfficients();
}

void service::writeToFile(string filename)
{
	con.writeToFile(filename);
}

void service::addentities()
{
	HospitalDepartment* a = new Unit("sac", 23, 12, 4, 2);
	HospitalDepartment* b = new Surgery("aaff", 4, 2);
	con.addDepartment(a);
	con.addDepartment(b);
}

