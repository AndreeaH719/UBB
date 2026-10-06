#include "ui.h"
#include <string>
#include <iostream>
#include <limits>

Ui::Ui(Service &s): ser(s) {}

void Ui::run()
{
	std::cout << "WELCOME TO THE SHOW\n";
	std::cout << "1.Add an artist\n";
	std::cout << "2.Remove an artist\n";
	std::cout << "3.Update an artist\n";
	std::cout << "4.See all\n";
	int cmd;
	while (true)
	{
		std::cout << "Enter your choice: ";
		std::cin >> cmd;
		while (std::cin.fail())
		{
			std::cout << "invlaid input";
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cin >> cmd;
		}
		if (cmd == 1)
		{
		    try{
				std::string name, album, song;
				int wins;
				std::cin.ignore(std :: numeric_limits< std::streamsize > ::max(), '\n');
				std::cout << "Name: ";
				std::getline(std::cin, name);
				std::cout << "Album: ";
				std::cin >> album;
				std::cout << "Song: ";
				std::cin >> song;
				std::cout << "Wins: ";
				std::cin >> wins;
				this->ser.add(name, album, song, wins);
			}
			catch (std::runtime_error& e)
			{
				std::cout << e.what() << '\n';
			}
		}
		else if (cmd == 2)
		{
		    try{
				std::string name;
				int wins;
				std::cout << "Name: ";
				std::cin >> name;
				this->ser.remove(name);
			}
			catch (std::runtime_error& e)
			{
				std::cout << e.what() << '\n';
			}
		}
		else if (cmd == 3)
		{   
		    try{
				std::string name, album, song;
				int wins;
				std::cout << "Name: ";
				std::cin >> name;
				std::cout << "Album: ";
				std::cin >> album;
				std::cout << "Song: ";
				std::cin >> song;
				std::cout << "Wins: ";
				std::cin >> wins;
				this->ser.update(name, album, song, wins);
			}
			catch (std::runtime_error& e)
			{
				std::cout << e.what() << '\n';
			}
		}
		else if (cmd == 4)
		{
			TElem*e = this->ser.get_all();
			int n = this->ser.get_size();
			for(int i = 0; i < n; i++)
			   std::cout << e[i] << "\n";
		}
		else if(cmd == 5) 
		        break;
	}
}
