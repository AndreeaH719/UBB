#pragma once
#include "dynamic.h"
#include "domain.h"

class repo
{
    private:
        DynamicArray array;
    public:
        void add(const std::string& name, const std::string& team, int wins, int number);
        void remove(const std::string& name);
        void update(const std::string& name, const std::string& new_team, int new_wins, int new_number);
        int get_size() const;
        TElem* get_all() const;
};

