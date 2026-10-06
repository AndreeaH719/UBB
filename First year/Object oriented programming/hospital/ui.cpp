#include "ui.h"
#include "HospitalDepartment.h"
#include "Surgery.h"
#include "Unit.h"
#include <iostream>
using namespace std;

ui::ui(service &s): ser(s) {}

void ui::run()
{
     cout << "1.Add\n";
     cout << "2.See all\n";
     cout << "3.See all efficients\n";
     int cmd;
     while (1)
     {
         cout << "Enter your choice: ";
         cin >> cmd;
         if (cmd == 1)
         {
             string type;
             cout << "Enter type(Unit/Surgery): ";
             cin >> type;
             HospitalDepartment* d;
             if (type == "Unit")
             {
                 int nm, nb, nd;
                 double g;
                 string name;
                 cout << "Name: ";
                 cin >> name;
                 cout << "Nb doctors: ";
                 cin >> nd;
                 cout << "Nb mothers:";
                 cin >> nm;
                 cout << "Nb newborns: ";
                 cin >> nb;
                 cout << "Grade: ";
                 cin >> g;
                 d = new Unit(name, nd, nm, nb, g);
                 ser.addDepartment(d);
             }
             else if (type == "Surgery")
             {
                 int np, nd;
                 string name;
                 cout << "Name: ";
                 cin >> name;
                 cout << "Nb doctors: ";
                 cin >> nd;
                 cout << "Nb pacients: ";
                 cin >> np;
                 d = new Surgery(name, nd, np);
                 ser.addDepartment(d);
             }
         }
         else if (cmd == 2)
         {
             for(const auto d: ser.getAllDepartments())
                 cout << d->toString() << "\n";
         }
         else if (cmd == 3)
         {
             for(const auto d: ser.getAllEfficients())
                 cout << d->toString() << "\n";
         }
         else if (cmd == 4)
         { 
             string name;
             cout << "Enter file name: ";
             cin >> name;
             ser.writeToFile(name);
             cout << "All saved\n";
         }
     }
}