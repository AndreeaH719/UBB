#pragma once
#include "repo.h"

class service
{
     private:
         repo &re;
     public:
        service(repo &r);
        void add(const std::string&name, int number, int wins);
        void remove(int number);
        void update(const std::string&name, int new_number, int new_wins);
        int getSize() const;
        std::vector<Driver>& getAll();
        std::vector<Driver> filter(int wins);

};

