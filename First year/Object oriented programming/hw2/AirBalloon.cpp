#include "AirBalloon.h"

AirBalloon::AirBalloon(int id, string model, int weight): aircraft(id, model), weight(weight) {}

bool AirBalloon::isSuitable(string activity)
{
	if(activity == "leisure")  return true;
	return false;
}

int AirBalloon::maxAltitude()
{
	return 21;
}

string AirBalloon::toString()
{
	return to_string(id) + " | " + model +
		  " | " + to_string(weight);
}