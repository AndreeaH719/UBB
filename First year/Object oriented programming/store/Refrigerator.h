#pragma once
#include "Appliance.h"

class Refrigerator: public Appliance
{
     private:
         string elecUsage;
         bool freezer;
     public:
        Refrigerator(string id, double weight, string elecUsage, bool freezer);
        double consumedEnergy() override;
        string toString() override;
};

