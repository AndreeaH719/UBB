#pragma once
#include "dynamic.h"
#include <vector>

class Repo
{
    private:
       Dynamic array;
    public:
       void add(const std::string& name, const std::string& team, int goals, int age);
       void remove(const std::string& name);
       void update(const std::string& name, const std::string& new_team, int new_goals, int new_age);
       std::vector<Player> filter(int g);
       int get_size() const;
       TElem* get_all() const;
};

