#pragma once
#include <string>
using namespace std;

class Appliance
{
     protected:
         string id;
         double weight;
     public:
         Appliance(string id, double weight);

         virtual double consumedEnergy() = 0;
         virtual string toString() = 0;

         virtual ~Appliance() = default;

         int getWeight() {return weight;}
         string getId() {return id;}
};

