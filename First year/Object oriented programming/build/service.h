#pragma once
#include "Controller.h"

class service
{
     private:
        Controller &con;
     public:
        service(Controller &c);
        void add(Building* b);
        vector<Building*> getAll();
        vector<Building*> getAllRestored();
        vector<Building*> getAllDemolished();
        void writeFile(string filename, vector<Building*>b);
        void remove(string s);
};