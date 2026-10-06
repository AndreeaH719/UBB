#pragma once
#include "repo.h"
class service
{
    private:
        repo &re;
    public:
        service(repo&r);
        void add(const Session& s);
        std::vector<Session> getAll();
        void addentites();
};

