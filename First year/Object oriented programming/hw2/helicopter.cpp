#include "helicopter.h"

helicopter::helicopter(int id, string model, bool isPrivate): aircraft(id, model), isPrivate(isPrivate) {}

bool helicopter::isSuitable(string activity)
{
	if(activity == "military" || activity == "medical" ||
	    activity == "transportation" || activity == "leisure")
		   return true;
	return false;
}
int helicopter::maxAltitude()
{
	return 12;
}

string helicopter::toString()
{
    string r;
	if(isPrivate) r = "is private";
	else r = "is not private";
	return to_string(id) + " | " + model + 
	   " | " + r;
}

