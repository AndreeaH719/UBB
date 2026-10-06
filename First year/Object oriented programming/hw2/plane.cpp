#include "plane.h"


plane::plane(int id, string model, bool isPrivate, int wings) : aircraft(id, model), isPrivate(isPrivate), wings(wings) {}

bool plane::isSuitable(string activity)
{
	if(activity == "military" ||
	   activity == "transportation") return true;
	if(activity == "leisure" && wings == 2) return true;
	return false;
}

int plane::maxAltitude()
{
	return 26;
}

string plane::toString()
{
	string r;
	if (isPrivate) r = "is private";
	else r = "is not private";
	return to_string(id) + " | " + model +
		" | " + r + " | " + to_string(wings);
}
