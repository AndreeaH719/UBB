#pragma once
#include "dynamic.h"
#include <vector>
class Repo
{
   private:
      Dynamic array;
   public:
      void add(const std::string& name, int age, const std::string& infect, int room);
      std::vector<Patient> update(int a);

      int get_size() const;
      TElem* get_all() const;
};

