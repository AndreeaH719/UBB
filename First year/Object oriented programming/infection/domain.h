#pragma once
#include <string>
#include <iostream>

class Patient
{
   private:
      std::string name;
      int age;
      std::string infect;
      int room;
   public:
      Patient(const std::string&name="",int age =0, const std::string& infect = "", int room=0);

      std::string getName() const {return this->name;}
      int getAge() const {return this->age;}
      std::string getInfect() const {return this->infect;}
      int getRoom() const {return this->room;}

      void setName(const std::string&val1) {this->name = val1;}
      void setAge(int val2) {this->age=val2;}
      void setInfect(const std::string& val3) {this->infect=val3;}
      void setRoom(int val4) {this->room=val4;}

      friend std::ostream& operator <<(std::ostream& os, const Patient& p)
      {
          os << p.name << " | " << p.age << " | " << p.infect << " | " << p.room;
          return os;
      }

      bool operator == (const Patient & a) const
      {
          return name == a.getName();
      }

};

