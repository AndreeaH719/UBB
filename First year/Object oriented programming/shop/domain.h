#pragma once
#include <string>
#include <iostream>
class List
{
      private:
         std::string category;
         std::string name;
         int quantity;
      public:
         List(std::string category="", std::string name="", int quantity=0);
         std::string getCategory() const {return category;}
         std::string getName() const {return name;}
         int getQuantity() const {return quantity;}
         friend std::ostream& operator<<(std::ostream& os, const List& l)
         {
             os << l.getCategory() << " " << l.getName() << " " << l.getQuantity();
             return os;
         }
         friend std::istream& operator>>(std::istream& is, List& l)
         {
             is >> l.category >> l.name >> l.quantity;
             return is;
         }
};

