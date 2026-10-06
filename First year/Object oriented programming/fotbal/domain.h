#pragma once
#include <string>
#include <iostream>

class Player
{
    private:
        std::string name;
        std::string team;
        int goals;
        int age;
    public:
        Player(const std::string&name="", const std::string& team="", int goals = 0, int age=0);

        std::string getName() const {return name;}
        std::string getTeam() const {return team;}
        int getGoals() const {return goals;}
        int getAge() const {return age;}

        void setName(const std::string&val1) {name=val1;}
        void setTeam(const std::string&val2) {team=val2;}
        void setGoals(int val3) {goals = val3;}
        void setAge(int val4) {age = val4;}

        friend std::ostream& operator<<(std::ostream& os, const Player& p)
        {
            os << p.name << " " << p.team << " " << p.goals << " " << p.age;
            return os;
        }
};

