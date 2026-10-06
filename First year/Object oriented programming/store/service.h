#pragma once
#include "Controller.h"

class service
{
       private:
           Controller &con;
       public:
           service(Controller &c);
           void add(Appliance* a);
           vector<Appliance*> getAll();
           vector<Appliance*> getAllWithConsumedElec(double elec);
           void writeToFile(string filename, double elec);
};
