//============================================================================
// File Name   : Menu.cpp
// Authors     : You
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================

//  Your code starts here

#include "Menu.h"

#include <iostream>
#include <fstream>


using namespace std;

Menu::Menu() {
}

void Menu::display_menu() {
	cout << "\n";
	cout << "1. Prikazi osnovne informacije o autorima" << endl;
	cout << "2. Ucitaj studente iz datoteke" << endl;
	cout << "3. Prikazi informacije o studentu" << endl;
	cout << "4. Prikazi studente sa najboljim prosekom" << endl;
	cout << "5. Sortiraj" << endl;
	cout << "6. Prikazi informacije o svim studentima" << endl;
	cout << "7. Upisi studente u izlaznu datoteku" << endl;
	cout << "8. Izlaz iz programa" << endl;
	cout << endl;
}

void Menu::display_info() {
	cout << "Autori: " << endl;
	cout << "Marko Cvijanovic sw23/2017" << endl;
	cout << "Milorad Radovic sw67/2017" << endl;
	cout << "Marina Gusa sw49/2017" << endl;
}

void Menu::read_students() {

	gs.set_student_courses_empty(); 

	cout << "Unesite putanju do zeljenog fajla:\n";
	string file_path;
	cin >> file_path;
	StudentCourses sc;
	vector<StudentCourses> data;
	ifstream input;

	input.open(file_path);

	if (!input.is_open()) {
		throw InvalidFile();
	}


	do
	{
		input >> sc;
		if (!sc.value_test()) {
			throw InvalidData();
		}

		data.push_back(sc);

	} while (input.good());
	if (input.fail()) {
		throw InvalidData();
	}
	else {
		gs.set_student_courses(data);
		gs.izracunajisetuj();

	}


	input.close();
}

void Menu::display_students()
{
	gs.display_all();
}

