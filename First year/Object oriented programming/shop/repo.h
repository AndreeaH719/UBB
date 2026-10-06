#pragma once
#include "domain.h"
#include <vector>

class repo
{
      private:
         std::vector<List> elems;
         std::string filename;
         void loadData();
      public:
         repo(std::string filename);
         void writeData();
         void add(const List&l);
         void remove(std::string name);
         std::vector<List> getAll();
};

