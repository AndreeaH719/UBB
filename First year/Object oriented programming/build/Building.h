#pragma once
#include <string>
using namespace std;

class Building
{  
     protected:
         string address;
         int constructionYear;
     public:
         Building(string address, int constructionYear);
         virtual bool mustBeRestored() = 0;
         virtual bool canBeDemolished() = 0;
         virtual string toString() = 0;
         virtual ~Building() = default;
         string getAddress() {return address;}
         int getYear() {return constructionYear;}
};

