#pragma once
#include "service.h"

class ui
{
    private:
       service &ser;
    public:
        ui(service &s);
        void run();
};

