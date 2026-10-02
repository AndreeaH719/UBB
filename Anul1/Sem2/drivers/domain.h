#pragma once
#include <string>
#include <iostream>

class Driver
{
     private:
        std::string name;
        int wins;
        int number;
    public:
        Driver(const std::string&name = "", int number=0, int wins =0);

        std::string getName() const {return name;}
        int getWins() const {return wins;}
        int getNumber()const {return number;}

        void setName(const std::string&value1) {name = value1;}
        void setWins(int value2) {wins = value2;}
        void setNumber(int value3) {number = value3;}

        friend std::ostream& operator <<(std::ostream& os, const Driver& d)
        {
            os << d.name << " " << d.number << " " << d.wins;
            return os;
        }

        friend std::istream& operator >>(std::istream& is, Driver& d)
        {
            is >> d.name >> d.number >> d.wins;
            return is;
        }

        bool operator ==(const Driver& d) const
        {
            return name == d.name;
        }
};

