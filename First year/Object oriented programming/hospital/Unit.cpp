#include "Unit.h"

Unit::Unit(string hospitalName, int numberOfDoctors, int numberOfMothers, int numberOfNewborn, double averageGrade): HospitalDepartment(hospitalName, numberOfDoctors), numberOfMothers(numberOfMothers), numberOfNewborn(numberOfNewborn), averageGrade(averageGrade) {}

bool Unit::isEfficient()
{
	return averageGrade > 8.5 && numberOfNewborn >= numberOfMothers;
}

string Unit::toString()
{
	return hospitalName + " | " + to_string(numberOfDoctors) + " | "
	 + to_string(numberOfMothers) + " | " + to_string(numberOfNewborn) 
	 + " | " + to_string(averageGrade);
}