#include "Block.h"

Block::Block(string address, int constructionYear, int totalApartments, int occupiedApartments):
       Building(address, constructionYear), totalApartments(totalApartments), occupiedApartments(occupiedApartments) {}


bool Block::mustBeRestored()
{
     return (2026-constructionYear) > 40 && occupiedApartments > 80/100*totalApartments;
}

bool Block::canBeDemolished()
{
    return occupiedApartments > 5/100*totalApartments;
}

string Block::toString()
{
    return address + " | " + to_string(constructionYear) +
     " | " + to_string(totalApartments) +
     " | " + to_string(occupiedApartments);
}
