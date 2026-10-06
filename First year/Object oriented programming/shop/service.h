#pragma once
#include "repo.h"
class service
{
      private:
          repo &re;
      public:
          service(repo&r);
          void add(std::string category, std::string name, int quantity);
          std::vector<List> getAll();
          void remove(std::string name);
          void addentities();
};

