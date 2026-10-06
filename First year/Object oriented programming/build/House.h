#pragma once
#include "Building.h"

class House:public Building
{
     private:
         string type;
         bool isHistorical;
    public:
         House(string address, int constructionYear, string type, bool isHistorical);
         bool mustBeRestored() override;
         bool canBeDemolished() override;
         string toString() override;
};

