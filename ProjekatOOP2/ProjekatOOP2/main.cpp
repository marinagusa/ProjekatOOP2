//============================================================================
// File Name   : main.cpp 
// Authors     : You
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================

#include "Menu.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	string input_path;
	string output_path = "";
	bool output_given;

	if (argc != 2 && argc != 3) {
		"Pogresan broj argumenata!";
		exit(1);
	}
	else {
		if (argc == 2) {
			input_path = argv[1];
			output_given = false;
		}
		else {
			input_path = argv[1];
			output_path = argv[2];
			output_given = true;
		}
	}

	Menu m;
	int option;
	m.display_menu();
	bool is_read = false;

	do
	{
		cout << "> ";
		while (!(cin >> option) || option < 1 || option > Menu::EXIT)
		{
			if (cin.fail())	// we found something that wasn’t an integer
			{
				cin.clear();	// we’d like to look at the characters
				char ch;
				while (cin>>ch && !isdigit(ch))
				{
					cerr << "Invalid input; please try again" << endl;
					cout << "> ";
				}
				cin.unget();
			} 
			else
			{	// option < 1 || option > Menu::EXIT */
				cerr << "Invalid input; please try again" << endl;
				cout << "> ";
			}
		}
			
		switch (option)
		{
		case Menu::INFO:
			m.display_info();
			break;
		case Menu::READ_FILE:
			try
			{
				m.read_students(input_path);
				is_read = true;
			}
			catch (const Menu::InvalidFile& excp)
			{
				cerr << excp.what() << endl;
			}
			catch (const Menu::InvalidData& excp)
			{
				cerr << excp.what() << endl;
			}
			break;

		case Menu::DISPLAY:
			if (is_read) m.display_single();
			else cout << "Nema ucitanih studenata!";
			break;

		case Menu::DISPLAY_ALL:
			if (is_read) m.display_students();
			else cout << "Nema ucitanih studenata!";
			break;


		case Menu::HIGHEST:
			if (is_read) m.display_highest_score();
			else cout << "Nema ucitanih studenata!";
			break;

		case Menu::SORT:
			if (is_read) m.mSort();
			else cout << "Nema ucitanih studenata!";
			break;
		
		case Menu::SAVE:
			if (is_read) m.writetofile(output_given, output_path);
			else cout << "Nema ucitanih studenata!";
			break;
		}

		m.display_menu();
	} while (option != Menu::EXIT);
	return 0;
}
