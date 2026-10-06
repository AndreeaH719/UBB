#pragma once
#include "Appliance.h"

class DishWasher:public Appliance
{
     private:
        double length;
        double elec_cons;
     public:
        DishWasher(string id, double weight, double length, double elec_cons);
        double consumedEnergy() override;
        string toString() override;
};

