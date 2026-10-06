#include "ui.h"
#include "Appliance.h"
#include "DishWasher.h"
#include "Refrigerator.h"
#include <iostream>
using namespace std;

ui::ui(service &s): ser(s) {}

void ui::run()
{
	cout << "1.Add\n";
	cout << "2.Show all\n";
	cout << "3.Save\n";
	int cmd;
	while (1)
	{
		cout << "enter your choice: ";
		cin >> cmd;
		if (cmd == 1)
		{
		   try{
			string type;
			cout << "type: ";
			cin >> type;
			Appliance*a;
			if (type == "refrigerator")
			{
			     string id, eu;
				 double w;
				 bool frez;
				 cout << "id: ";
				 cin >> id;
				 cout << "weight: ";
				 cin >> w;
				 cout << "usage class: ";
				 cin >> eu;
				 cout << "freezer: ";
				 cin >> frez;
				 a = new Refrigerator(id,w,eu, frez);
				 ser.add(a);
			}
			else if (type == "dishWasher")
			{
				string id;
				double w;
				double l, c;
				cout << "id: ";
				cin >> id;
				cout << "weight: ";
				cin >> w;
				cout << "length: ";
				cin >> l;
				cout << "consumed el: ";
				cin >> c;
				a = new DishWasher(id, w, l, c);
				ser.add(a);
			}
		   } 
		   catch (runtime_error& e)
		   {
			   cout << e.what() << "\n";
		   }
		}
		else if (cmd == 2)
		{
			for(const auto a: ser.getAll())
			     cout << a->toString() << "\n";
		}
		else if (cmd == 3)
		{
			double e;
			cout << "value: ";
			cin >> e;
			string f;
			cout << "file name: ";
			cin >> f;
			ser.writeToFile(f, e);
		}
	}
}