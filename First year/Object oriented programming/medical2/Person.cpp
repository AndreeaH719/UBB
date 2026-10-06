#include "Person.h"
#include <fstream>

Person::Person() {}

void Person::addAnalysis(MedicalAnalysis* a)
{
	analysis.push_back(a);
}

vector<MedicalAnalysis*> Person::getAllAnalysis()
{
	return analysis;
}

vector<MedicalAnalysis*> Person::getAnalyses1(int month)
{
	vector<MedicalAnalysis*> r;
	for (const auto m : analysis)
	{
	    string date = m->getDate();
		int mon = stoi(date.substr(5,2));
		if(mon == month) r.push_back(m);
	}
	return r;
}

bool Person::isIll(int month)
{
	vector<MedicalAnalysis*> r = getAnalyses1(month);
	for (const auto a : r)
	{
		if(a->isResultOk()) return false;
	}
	return true;
}

vector<MedicalAnalysis*> Person::getAnalyses2(string date1, string date2)
{
	vector<MedicalAnalysis*> r;
	for (const auto a : analysis)
	{
		if(a->getDate() >= date1 && a->getDate() <= date2)
		     r.push_back(a);
	}
	return r;
}

void Person::writeFile(string filename, string date1, string date2)
{
	vector<MedicalAnalysis*> r = getAnalyses2(date1, date2);
	ofstream fout(filename);
	for (const auto a : r)
	{
	    string k;
		if(a->isResultOk()) k = "ok";
		else k = "not ok";
		fout << a->toString() << " " << k << '\n';
	}
}
