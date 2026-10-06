#include "BMI.h"



BMI::BMI(string date, double value) :MedicalAnalysis(date), value(value) {}


bool BMI::isResultOk()
{
	return value >= 18.5 && value <= 25;
}

string BMI::toString()
{
	return date + " | " + to_string(value);
}
