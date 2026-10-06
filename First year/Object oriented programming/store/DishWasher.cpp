#include "DishWasher.h"

DishWasher::DishWasher(string id, double weight, double length, double elec_cons): Appliance(id, weight), length(length), elec_cons(elec_cons) {}

double DishWasher::consumedEnergy()
{
	return length*elec_cons*8;
}

string DishWasher::toString()
{
	return id + " | " + to_string(weight) +
	   " | " + to_string(length) + " | " +
	   to_string(elec_cons);
}