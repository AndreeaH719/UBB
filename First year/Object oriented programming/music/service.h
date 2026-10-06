#pragma once
#include "repo.h"
#include <vector>

class Service
{
    private:
       Repo &re;
    public:
       Service(Repo &r);
       void add(const std::string& name, const std::string& album, const std::string& song, int wins);
       void remove(const std::string& name);
       void update(const std::string& name, const std::string& new_album, const std::string& new_song, int new_wins);

       int get_size() const;
       TElem* get_all() const;

       std::vector<Artist> filter();
};

