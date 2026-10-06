#pragma once
#include "aircraft.h"

class AirBalloon:public aircraft
{
    private:
        int weight;
    public:
        AirBalloon(int id, string model, int weight);
        bool isSuitable(string activity) override;
        int maxAltitude() override;
        string toString() override;

};