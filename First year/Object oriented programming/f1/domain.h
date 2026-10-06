#pragma once
#include <string>
#include <iostream>
class Driver
{
    private:
        std::string name;
        std::string team;
        int wins;
        int number;
    public:
        Driver(const std::string &name="", const std::string& team="", int wins = 0, int number =0);
        std::string getName() const {return this->name;}
        std::string getTeam() const {return this->team;}
        int getWins() const {return this->wins;}
        int getNumber() const {return this->number;}

        void setName(const std::string value1) {this->name = value1;}
        void setTeam(const std::string value2) {this->team = value2;}
        void setWins(int value3) {this->wins = value3;}
        void setNumber(int value4) {this->number = value4;}

        friend std::ostream& operator <<(std::ostream& os, const Driver& d)
        {
            os << d.name << " | " << d.team << " | " << d.wins << " | " << d.number;
            return os;
        }

        bool operator ==(const Driver& d)
        {
            return name==d.name && team==d.team;
        }


};

