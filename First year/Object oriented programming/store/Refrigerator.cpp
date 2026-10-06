#include "Refrigerator.h"

Refrigerator::Refrigerator(string id, double weight, string elecUsage, bool freezer): Appliance(id, weight), elecUsage(elecUsage), freezer(freezer) {}

double Refrigerator::consumedEnergy()
{
    double x;
    if(elecUsage == "A") x = 3;
    else if(elecUsage == "A+") x = 2.5;
    else x = 2;
    if(!freezer) return 30 * x;
    return 30 * x + 20;
}

string Refrigerator::toString()
{
    return id + " | " + to_string(weight) + " | "
        + elecUsage + " | " + to_string(freezer);
}