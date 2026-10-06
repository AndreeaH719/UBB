#include "ui.h"

ui::ui(service&s): ser(s) {}

void ui::run()
{
	std::cout << "1.Add\n";
	std::cout << "2.Remove\n";
	std::cout << "3.Update\n";
	std::cout << "4.Filter\n";
	std::cout << "5.See all\n";
	int cmd;
	while (true)
	{
		std::cout << "Enter your schoice: ";
		std::cin >> cmd;
		if (cmd == 1)
		{
		    std::string name;
			int number, wins;
			std::cout << "Name:";
			std::cin >> name;
			std::cout << "Number: ";
			std::cin >> number;
			std::cout << "Wins: ";
			std::cin >> wins;
			this->ser.add(name, number, wins);
		}
		else
			if (cmd == 2)
			{
			    int number;
				std::cout << "Number: ";
				std::cin >> number;
				this->ser.remove(number);
		    }
			else
				if (cmd == 3)
				{
					std::string name;
					int number, wins;
					std::cout << "Name:";
					std::cin >> name;
					std::cout << "New number: ";
					std::cin >> number;
					std::cout << "New wins: ";
					std::cin >> wins;
					this->ser.update(name, number, wins);
		     	}
				else
					if (cmd == 5)
					{
					      for(const auto &d:this->ser.getAll())
						     std::cout << d << "\n";
				    }
					else break;
	}
}
