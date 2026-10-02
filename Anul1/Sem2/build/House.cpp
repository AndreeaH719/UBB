#include "House.h"
House::House(string address, int constructionYear, string type, bool isHistorical):
    Building(address, constructionYear), type(type), isHistorical(isHistorical) {}

bool House::mustBeRestored()
{
    return (2026-constructionYear) > 100;
}

bool House::canBeDemolished()
{
    if(isHistorical) return false;
    return true;
}

string House::toString()
{
    string r;
    if(isHistorical) r = "is historical";
    else r = "is not historical";
    return address + " | " + to_string(constructionYear)
     + " | " + type + " | " + r;
}

