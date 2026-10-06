#include "ui.h"
#include "BMI.h"
#include "BP.h"
#include "MedicalAnalysis.h"
#include <iostream>
using namespace std;
ui::ui(service &s):ser(s) {}

void ui::run()
{
	cout << "1.Add\n";
	cout << "2.See all\n";
	cout << "3.See all ill\n";
	cout << "4.Sve to file\n";
	int cmd;
	while (1)
	{
		cout << "Enter your choice: ";
		cin >> cmd;
		if (cmd == 1)
		{
			string type;
			cout << "Enter the type(BMI/BP): ";
			cin >> type;
			MedicalAnalysis* a;
			if (type == "BMI")
			{
				string date;
				double value;
				cout << "Date: ";
				cin >> date;
				cout << "Value: ";
				cin >> value;
				a = new BMI(date, value);
				ser.addAnalysis(a);
			}
			else if (type == "BP")
			{
				string date;
				int sv, dv;
				cout << "Date: ";
				cin >> date;
				cout << "Sv: ";
				cin >> sv;
				cout << "Dv: ";
				cin >> dv;
				a = new BP(date, sv, dv);
				ser.addAnalysis(a);
			}
		}
		else if (cmd == 2)
		{
			for(const auto a: ser.getAllAnalysis())
			   cout << a->toString() << "\n";
		}
		else if (cmd == 3)
		{
			int month;
			cout << "Month: ";
			cin >> month;
			if(ser.isIll(month)) cout << "is ill";
			else cout << "is not ill";
		}
		else if (cmd == 4)
		{
			string f, d1, d2;
			cout << "Name: ";
			cin >> f;
			cout << "Date1: ";
			cin >> d1;
			cout << "Date2: ";
			cin >> d2;
			ser.writeFile(f, d1, d2);
		}
	}
}