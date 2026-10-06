#pragma once
#include "repo.h"

class Service
{
    private:
        Repo &re;
    public:
        Service(Repo &r);
        void add(const std::string& name, int age, const std::string& infect, int room);
        std::vector<Patient> update(int a);
        void pacients();
        int get_size() const;
        TElem* get_all() const;
};

