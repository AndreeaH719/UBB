#pragma once
#include <string>
using namespace std;

class aircraft
{
     protected:
         int id;
         string model;
     public:
         aircraft(int id, string model);
         virtual bool isSuitable(string activity) = 0;
         virtual int maxAltitude() = 0;
         virtual string toString() = 0;
         virtual ~aircraft() = default;
};

