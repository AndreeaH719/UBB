#pragma once
#include "domain.h"
#include <vector>
class repo
{
      private:
          std::vector<Session> elems;
          std::string filename;
          void loadData();
      public:
         repo(std::string filename);
         void add(const Session&s);
         std::vector<Session> getAll();
         void writeData();
};

