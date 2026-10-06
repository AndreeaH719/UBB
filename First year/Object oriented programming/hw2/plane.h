#pragma once
#include "aircraft.h"

class plane:public aircraft
{
     private:
        bool isPrivate;
        int wings;
     public:
         plane(int id, string model, bool isPrivate, int wings);
         bool isSuitable(string activity) override;
         int maxAltitude() override;
         string toString() override;

};

