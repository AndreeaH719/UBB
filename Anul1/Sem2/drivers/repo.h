#pragma once
#include "domain.h"
#include <vector>

class repo
{
     private:
        std::vector<Driver> elems;

        std::string filename;
        void loadFile();
        void saveFile();
    public:
        repo(const std::string &filename);
        void add(const Driver&d);
        void remove(int number);
        void update(const std::string &name, int new_number, int new_wins);
        int getSize() const;
        std::vector<Driver>& getAll();
};

