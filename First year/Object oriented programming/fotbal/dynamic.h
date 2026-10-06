#pragma once
#include "domain.h"

typedef Player TElem;

class Dynamic
{
    private:
       int size;
       int capacity;
       TElem* elems;
       void _resize();
    public:
       Dynamic(int initial=2);
       ~Dynamic();
       void add(TElem e);
       void remove(int poz);
       int get_size() const {return this->size;}
       TElem* get_all() const {return this->elems;}
};

