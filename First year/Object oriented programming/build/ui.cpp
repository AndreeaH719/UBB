#include "ui.h"
#include <iostream>
#include "Building.h"
#include "Block.h"
#include "House.h"
#include <stdexcept>
using namespace std;

ui::ui(service &s): ser(s) {}

void ui::run()
{
	cout << "1.Add\n";
	cout << "2.Remove\n";
	cout << "3.See all\n";
	cout << "4.Save\n";
	int cmd;
	while (1)
	{
		cout << "enter your choice: ";
		cin >> cmd;
		Building*b;
		if (cmd == 1)
		{
		   try{
				string type;
				cout << "type: ";
				cin >> type;
				if (type == "block")
				{
					string ad;
					int cy, ta, oa;
					cout << "address: ";
					cin >> ad;
					cout << "year: ";
					cin >> cy;
					cout << "total ap: ";
					cin >> ta;
					cout << "occupied ap: ";
					cin >> oa;
					b = new Block(ad, cy, ta, oa);
					ser.add(b);
				}
				else if (type == "house")
				{
					string ad, t;
					int cy;
					bool h;
					cout << "address: ";
					cin >> ad;
					cout << "year: ";
					cin >> cy;
					cout << "type: ";
					cin >> t;
					cout << "historical: ";
					cin >> h;
					b = new House(ad, cy, t, h);
					ser.add(b);
			    }
		   }catch(runtime_error &e)
		    {
			   cout << e.what() << "\n";
		    }
		}
		else if (cmd == 2)
		{
		     string s;
			 cout << "string: ";
			 cin >> s;
			 ser.remove(s);
		}
		else if (cmd == 3)
		{
			for(const auto a: ser.getAll())
			     cout << a->toString() << "\n";
		}
		else if (cmd == 4)
		{
			vector<Building*> r1 = ser.getAllRestored();
			vector<Building*> r2 = ser.getAllDemolished();
			string f1, f2;
			cout << "file1: ";
			cin >> f1;
			ser.writeFile(f1, r1);
			cout << "file2: ";
			cin >> f2;
			ser.writeFile(f2, r2);
		}
	}
}