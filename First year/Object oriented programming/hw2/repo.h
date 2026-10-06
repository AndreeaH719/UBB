#pragma once
#include "aircraft.h"
#include <vector>
class repo
{
      private:
          vector<aircraft*> elems;
      public: 
          repo();
          void add(aircraft*a);
          vector<aircraft*> display1(string filename, string activity);
          vector<aircraft*> display2(int altitude);
          vector<aircraft*> display();
};

