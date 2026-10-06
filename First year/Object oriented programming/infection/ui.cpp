#include "ui.h"

Ui::Ui(Service &s): ser(s) {}

void Ui::run()
{
	std::cout << "1.Add\n";
	std::cout << "2.Show all\n";
	std::cout << "3.Update\n";
	std::cout << "4.Exit\n";
	std::cout << "\n";
	int cmd;

	while (true)
	{
		std::cout << "Enter your choice: ";
		std::cin >> cmd;
		if (cmd == 1)
		{
		    try{
				std::string name,infect;
				int age, room;
				std::cout << "Name: ";
				std::cin >> name;
				std::cout << "Age: ";
				std::cin >> age;
				std::cout << "Infect: ";
				std::cin >> infect;
				std::cout << "Room: ";
				std::cin >> room;
				this->ser.add(name, age, infect, room);
			}
			catch (std::runtime_error& e)
			{
				std::cout << e.what();
			}
			
		}
		else if (cmd == 2)
		{
			TElem*e=this->ser.get_all();
			int n = this->ser.get_size();
			for (int i = 0; i < n; i++)
			{
				std::cout << e[i] << "\n";
			}
		}
		else if (cmd == 3)
		{
			int a;
			std::cout << "Age: ";
			std::cin >> a;
			std::cout << "All infected\n";
			std::vector<Patient> r = this->ser.update(a);
			for (int i = 0; i < r.size(); i++)
			{
				std::cout << r[i] << "\n";
			}
		}
		else if(cmd == 4)
		         break;
    }
}