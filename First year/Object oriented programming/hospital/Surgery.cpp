#include "Surgery.h"

Surgery::Surgery(string hospitalName, int numberOfDoctors, int numberOfPatients): HospitalDepartment(hospitalName, numberOfDoctors), numberOfPatients(numberOfPatients) {}

bool Surgery::isEfficient()
{
	return numberOfPatients/numberOfDoctors >= 2;
}

string Surgery::toString()
{
	return hospitalName + " | " + to_string(numberOfDoctors) + " | "
	   + to_string(numberOfPatients);
}

