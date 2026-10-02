#pragma once
#include "Building.h"

class Block:public Building
{
     private:
        int totalApartments;
        int occupiedApartments;
     public:
        Block(string address, int constructionYear, int totalApartments, int occupiedApartments);
        bool mustBeRestored() override;
        bool canBeDemolished() override;
        string toString() override;
};

