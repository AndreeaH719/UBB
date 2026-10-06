#include "service.h"
#include "BMI.h"
#include "BP.h"

service::service(Person &p): per(p) {}

void service::addAnalysis(MedicalAnalysis* a)
{
	per.addAnalysis(a);
}

vector<MedicalAnalysis*> service::getAllAnalysis()
{
	return per.getAllAnalysis();
}

vector<MedicalAnalysis*> service::getAnalyses1(int month)
{
	return per.getAnalyses1(month);
}

bool service::isIll(int month)
{
	return per.isIll(month);
}

vector<MedicalAnalysis*> service::getAnalyses2(string date1, string date2)
{
	return per.getAnalyses2(date1, date2);
}

void service::writeFile(string filename, string date1, string date2)
{
	per.writeFile(filename, date1, date2);
}

void service::entities()
{
	MedicalAnalysis* a = new BMI("2024.12.12", 2);
	MedicalAnalysis* b = new BP("2013.02.23", 91, 65);
	per.addAnalysis(a);
	per.addAnalysis(b);
}
