#pragma once
#include "repo.h"

class service
{
    private:
        repo &re;
    public:
        service(repo &r);
        void add(aircraft* a);
        vector<aircraft*> display1(string filename, string activity);
        vector<aircraft*> display2(int altitude);
        vector<aircraft*> display();
};

