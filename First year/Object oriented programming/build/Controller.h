#pragma once
#include "Building.h"
#include <vector>

class Controller
{
      private:
          vector<Building*> elems;
      public:
          Controller();
          void add(Building*b);
          void remove(string s);
          vector<Building*> getAll();
          vector<Building*> getAllRestored();
          vector<Building*> getAllDemolished();
          void writeFile(string filename, vector<Building*>b);
};

