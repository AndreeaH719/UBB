#include "BP.h"

BP::BP(string date, int systolicValue, int diastolicValue): MedicalAnalysis(date), systolicValue(systolicValue), diastolicValue(diastolicValue) {}

bool BP::isResultOk()
{
	return systolicValue >= 90 && systolicValue <= 119
	   && diastolicValue >= 60 && diastolicValue <= 79;
}

string BP::toString()
{
	return date + " | " + to_string(systolicValue) + " | "
	 +to_string(diastolicValue);
}
