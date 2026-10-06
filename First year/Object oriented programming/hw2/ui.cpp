#include "ui.h"
#include "AirBalloon.h"
#include "aircraft.h"
#include "helicopter.h"
#include "plane.h"
#include <iostream>
using namespace std;
ui::ui(service &s): ser(s) {}

void ui::run()
{
    cout << "1.Add\n";
    cout << "2.See all\n";
    cout << "3.See all suitable\n";
    cout << "4.See by altitude\n";
    int cmd;
    while (1)
    {
        cout << "enter your choice: ";
        cin >> cmd;
        aircraft* a;
        if (cmd == 1)
        {
            string type;
            cout << "type: ";
            cin >> type;
            if (type == "helicopter")
            {
                int id;
                string model;
                bool pv;
                cout << "id: ";
                cin >> id;
                cout << "model: ";
                cin >> model;
                cout << "private: ";
                cin >> pv;
                a = new helicopter(id, model, pv);
                ser.add(a);
            }
            else if (type == "plane")
            {
                int id, w;
                string model;
                bool pv;
                cout << "id: ";
                cin >> id;
                cout << "model: ";
                cin >> model;
                cout << "private: ";
                cin >> pv;
                cout << "wings: ";
                cin >> w;
                a = new plane(id, model, pv, w);
                ser.add(a);
            }
            else if (type == "balloon")
            {
                int id, w;
                string model;
                bool pv;
                cout << "id: ";
                cin >> id;
                cout << "model: ";
                cin >> model;
                cout << "weight: ";
                cin >> w;
                a = new AirBalloon(id, model, w);
                ser.add(a);
            }
        }
        else if (cmd == 2)
        {
            for(const auto a: ser.display())
                 cout << a->toString() << "\n";
        }
        else if (cmd == 3)
        {
            string act, f;
            cout << "activity: ";
            cin >> act;
            cout << "filename: ";
            cin >> f;
            for(const auto a: ser.display1(f, act))
                 cout << a->toString() << "\n";
         }
        else if (cmd == 4)
        {
            int alt;
            cout << "altitude: ";
            cin >> alt;
            for(const auto a: ser.display2(alt))
                 cout << a->toString() << "\n";
        }
    }
}