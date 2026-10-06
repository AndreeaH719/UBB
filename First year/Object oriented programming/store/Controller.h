#pragma once
#include "Appliance.h"
#include <vector>
class Controller
{
      private:
          vector<Appliance*> elems;
      public:
         Controller();
         void add(Appliance*a);
         vector<Appliance*> getAll();
         vector<Appliance*> getAllWithConsumedElec(double elec);
         void writeToFile(string filename, double elec);
};

