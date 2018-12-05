//============================================================================
// File Name   : Menu.cpp
// Authors     : Marko Cvijanovic, Milorad Radovic, Marina Gusa
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

GroupOfStudents Menu::get_gs()
{
	return gs;
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

void Menu::read_students(string file_path) {

	gs.set_student_courses_empty(); 

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

	}


	input.close();
}

void Menu::read_students_binary(string input_path)
{
	vector <StudentCourses> data;
	ifstream _file;
	_file.open(input_path, ios::in | ios_base::binary);
	char c;

	while (!_file.eof()) {
		string first_name = "";
		string last_name = "";
		string id = "";

		vector<int> quiz;
		vector<int> homework;
		vector<int> test;

		_file.read((char*)&c, sizeof(char));

		while (c != ' ')
		{
			first_name += c;
			_file.read((char*)&c, sizeof(char));
		}

		_file.read((char*)&c, sizeof(char));

		while (c != ' ')
		{
			last_name += c;
			_file.read((char*)&c, sizeof(char));
		}

		_file.read((char*)&c, sizeof(char));

		while (c != '\n')
		{
			id += c;
			_file.read((char*)&c, sizeof(char));
		}

		Student student(first_name, last_name, id);

		_file.read((char*)&c, sizeof(char));
		string num = "";

		while (c != '\n')
		{
			if (c == ' ') {
				quiz.push_back(atoi(num.c_str()));
				num = "";
			}
			else {
				num += c;
			}

			_file.read((char*)&c, sizeof(char));
		}


		_file.read((char*)&c, sizeof(char));
		num = "";

		while (c != '\n')
		{
			if (c == ' ') {
				quiz.push_back(atoi(num.c_str()));
				num = "";
			}
			else {
				num += c;
			}

			_file.read((char*)&c, sizeof(char));
		}


		_file.read((char*)&c, sizeof(char));
		num = "";

		while (c != '\n')
		{
			if (c == ' ') {
				homework.push_back(atoi(num.c_str()));
				num = "";
			}
			else {
				num += c;
			}

			_file.read((char*)&c, sizeof(char));
		}


		_file.read((char*)&c, sizeof(char));
		num = "";

		while (c != '\n')
		{
			if (c == ' ') {
				test.push_back(atoi(num.c_str()));
				num = "";
			}
			else {
				num += c;
			}

			_file.read((char*)&c, sizeof(char));
		}

		Courses course(quiz, homework, test);
		StudentCourses studcourse(student, course);
		data.push_back(studcourse);
	}

	gs.set_student_courses(data);
}

void Menu::display_single()
{
	string input_id;
	cout << "Unesite broj indeksa studenta za prikaz: ";
	cin >> input_id;

	gs.display(input_id);


}

void Menu::display_students()
{
	gs.display_all();
}

void Menu::display_highest_score()
{
	gs.display_highest();
}

void Menu::mSort()
{
	gs.callSort();
}

void Menu::writetofile(bool given, string path) {
	gs.write_to_file(given, path);
}

void Menu::write_binary(bool given, string path)
{
	gs.write_binary(given, path);
}

