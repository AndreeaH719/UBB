#include "ui.h"
#include <limits>

ui::ui(service &s): ser(s) {}

void ui::run()
{
	std::cout << "LIGHTS OUT AND AWAY WE GO\n";
	std::cout << "\n";
	std::cout << "1.Make your team and add your new driver\n";
	std::cout << "2.No result? Get ride of a driver\n";
	std::cout << "3.Half of the season has passed. Any updates?\n";
	std::cout << "4.See all the drivers\n";
	std::cout << "5.Filter the driver\n";
	std::cout << "6.Sort the drivers\n";
	std::cout << "\n";
	int cmd;
	while (true)
	{	
		std::cout << "\n";
		std::cout << "Enter your command: ";
		std::cin >> cmd;
		std::cout << "\n";
		while(std::cin.fail())
		{
			std::cout << "Only an integer is available: ";
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cin >> cmd;
		}
		if (cmd == 1)
		{
		    try{
				std::string name, team;
				int wins, number;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Name: ";
				std::getline(std::cin, name);
				std::cout << "Team: ";
				std::getline(std::cin, team);
				std::cout << "Wins: ";
				std::cin >> wins;
				while (std::cin.fail())
				{
					std::cout << "Only an integer is available: ";
					std::cin.clear();
					std::cin.ignore(1000, '\n');
					std::cin >> wins;
				}
				std::cout << "Number: ";
				std::cin >> number;
				while (std::cin.fail())
				{
					std::cout << "Only an integer is available: ";
					std::cin.clear();
					std::cin.ignore(1000, '\n');
					std::cin >> number;
				}
				this->ser.add(name, team, wins, number);
			}
			catch (std::runtime_error& e)
			{
				std::cout << e.what() << "\n";
			}
		}
		else if (cmd == 2)
		{
			try {
				std::string name;
				std::cout << "Name: ";
				std::cin >> name;
                this->ser.remove(name);
			}
			catch (std::runtime_error& e)
			{
				std::cout << e.what();
			}
		    
		}
		else if (cmd == 3)
		{
			try {
				std::string name, team;
				int wins, number;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Name: ";
				std::getline(std::cin, name);
				std::cout << "Team: ";
				std::getline(std::cin, team);
				std::cout << "Wins: ";
				std::cin >> wins;
				while (std::cin.fail())
				{
					std::cout << "Only an integer is available: ";
					std::cin.clear();
					std::cin.ignore(1000, '\n');
					std::cin >> wins;
				}
				std::cout << "Number: ";
				std::cin >> number;
				while (std::cin.fail())
				{
					std::cout << "Only an integer is available: ";
					std::cin.clear();
					std::cin.ignore(1000, '\n');
					std::cin >> number;
				}
				this->ser.update(name, team, wins, number);
			}
			catch (std::runtime_error& e)
			{
				std::cout << e.what() << "\n";
			}
		}
		else if (cmd == 4)
		{
			TElem *e = this->ser.get_all();
			int n = this->ser.get_size();
			for(int i = 0; i < n; i++)
			   std::cout << e[i] << "\n";
		}
		else if (cmd == 5)
		{
			std::vector<Driver> r= this->ser.filter();
			for (int i = 0; i < r.size(); i++)
				std::cout << r[i] << "\n";
		}
		else if (cmd == 6)
		{
			TElem* e = this->ser.get_all();
			int n = this->ser.get_size();
			this->ser.sort_d();
			for (int i = 0; i < n; i++)
				std::cout << e[i] << "\n";

		}
	}
}