//============================================================================
// File Name   : Menu.h
// Authors     : Marko Cvijanovic, Milorad Radovic, Marina Gusa
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================


#ifndef MENU_H_
#define MENU_H_

#include <string>
#include <stdexcept>
#include "GroupOfStudents.h"

using std::string;

class Menu
{
public:
	struct InvalidData : std::runtime_error {
		InvalidData(): runtime_error("Invalid input data format") {}
	};

	struct InvalidFile : std::runtime_error {
		InvalidFile(): runtime_error("Invalid input file name") {}
	};

	enum OPTIONS{ INFO=1, READ_FILE, DISPLAY, HIGHEST, SORT, DISPLAY_ALL, SAVE, EXIT}; 
		
private:
	GroupOfStudents gs;

public:
	Menu();
	
	GroupOfStudents get_gs();
	void display_menu();
	void display_info();
	void read_students(string);
	void display_single();
	void display_students();
	void display_highest_score();
	void mSort();
	void writetofile(bool,string);
};

#endif /*MENU_H_*/
