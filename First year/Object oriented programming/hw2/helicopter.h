#pragma once
#include "aircraft.h"

class helicopter:public aircraft
{
     private:
        bool isPrivate;
     public:
         helicopter(int id, string model, bool isPrivate);
         bool isSuitable(string activity) override;
         int maxAltitude() override;
         string toString() override;

};

