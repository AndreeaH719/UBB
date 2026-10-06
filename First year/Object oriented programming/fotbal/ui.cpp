#include "ui.h"
#include <limits>

Ui::Ui(Service &s): ser(s) {}

void Ui::run()
{
	std::cout << "1.See all\n";
	std::cout << "2.Add\n";
	std::cout << "3.Remove\n";
	std::cout << "4.Update\n";
	std::cout << "5.Filter\n";
	std::cout << "6.Exit\n";
	int cmd;
	while (true)
	{
		std::cout << "Enter your choice: ";
		std::cin >> cmd;
		while (std::cin.fail())
		{
			std::cout << "must be integer";
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cin >> cmd;
		}
		if (cmd == 1)
		{
			TElem *e = this->ser.get_all();
			int n = this->ser.get_size();
			for(int i = 0; i < n; i++)
			   std::cout << e[i] << "\n";
		}
		else if (cmd == 2)
		{
			try {
				std::string name,team;
				int goals,age;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Name: ";
				std::getline(std::cin, name);
				std::cout << "Team: ";
				std::getline(std::cin, team);
				std::cout << "Goals: ";
				std::cin >> goals;
				std::cout << "Age: ";
				std::cin >> age;
				this->ser.add(name,team,goals,age);
			}
			catch (std::runtime_error& e)
			{
				std::cout << e.what() << '\n';
			}
		}
		else if (cmd == 3)
		{
			try {
				std::string name;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Name: ";
				std::getline(std::cin, name);
				this->ser.remove(name);
			}
			catch (std::runtime_error& e)
			{
				std::cout << e.what() << '\n';
			}
		}
		else if (cmd == 4)
		{

			try {
				std::string name, team;
				int goals, age;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Name: ";
				std::getline(std::cin, name);
				std::cout << "Team: ";
				std::getline(std::cin, team);
				std::cout << "Goals: ";
				std::cin >> goals;
				std::cout << "Age: ";
				std::cin >> age;
				this->ser.update(name, team, goals, age);
			}
			catch (std::runtime_error& e)
			{
				std::cout << e.what() << '\n';
			}
		}
		else if (cmd == 5)
		{
			int g;
			std::cin >> g;
			while (std::cin.fail())
			{
				std::cout << "must be integer";
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cin >> g;
			}
			std::vector<Player> r = this->ser.filter(g);
			for(int i = 0; i < r.size(); i++)
			   std::cout << r[i] << "\n";
		}
		else if(cmd == 6)
		       break;
		else std::cout << "Unknown coomand";
	}
}
