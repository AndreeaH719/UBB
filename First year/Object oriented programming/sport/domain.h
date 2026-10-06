#pragma once
#include <string>
#include <iostream>
class Session
{
     private:
        int start, end,level;
        std::string type, description;
    public:
        Session(int start=0,int end=0, std::string type="", int level=0, std::string description="");
        int getStart() const {return start;}
        int getEnd() const {return end;}
        int getLevel() const {return level;}
        std::string getType() const {return type;}
        std::string getDescription() const {return description;}
        friend std::ostream& operator<<(std::ostream& os, const Session& s)
        {
            os << s.getStart() << " " << s.getEnd() << " " << s.getType() << " " << s.getLevel() << " " <<
                s.getDescription();
            return os;
        }
        friend std::istream& operator>>(std::istream& is, Session& s)
        {
            is >> s.start >> s.end >> s.type >> s.level >> s.description;
            return is;
        }
};

