//============================================================================
// File Name   : GroupOfStudents.cpp
// Authors     : Marko Cvijanovic, Milorad Radovic, Marina Gusa
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================

//  Your code starts heres

#include "GroupOfStudents.h"
#include "StudentCourses.h"
#include <iostream>
#include <fstream>



void GroupOfStudents::set_student_courses(vector<StudentCourses>& sc)
{
	stdc_vec = sc;
}

void GroupOfStudents::set_student_courses_empty()
{
	stdc_vec.empty();
}

void GroupOfStudents::display(string id) {

	for (int i = 0; i < this->stdc_vec.size(); i++) {
		if (stdc_vec[i].get_student().get_id() == id) {
			stdc_vec[i].display();
			return;
		}
	}

	cout << "Student sa trazenim brojem indeksa nije pronadjen";
	return;
}

void GroupOfStudents::display_all()
{
	for (int i = 0; i < stdc_vec.size(); i++) {
		stdc_vec[i].display();
		cout << "\n";
	}
}

void GroupOfStudents::display_highest() {
	double max = 0;

	for (int i = 0; i < this->stdc_vec.size(); i++) {
		if (this->stdc_vec[i].get_final_score() > max) {
			max = this->stdc_vec[i].get_final_score();
		}
	}

	for (int j = 0; j < this->stdc_vec.size(); j++) {
		if (this->stdc_vec[j].get_final_score() == max) {
			this->stdc_vec[j].display();
		}
	}
}


void swap(StudentCourses* a, StudentCourses* b)
{
	StudentCourses temp = *a;
	*a = *b;
	*b = temp;
}

int partition(vector<StudentCourses>& sc, int low, int high)
{
	StudentCourses pivot = sc[high];     
	int i = (low - 1);  

	for (int j = low; j <= high - 1; j++)
	{
		if ((sc[j] < pivot) || (sc[j] == pivot))
		{
			i++;     
			swap(&sc[i], &sc[j]);
		}
	}
	swap(&sc[i + 1], &sc[high]);
	return (i + 1);
}


void GroupOfStudents::sort(vector<StudentCourses>& arr, int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);

		sort(arr, low, pi - 1);
		sort(arr, pi + 1, high);
	}
}

void GroupOfStudents::write_binary(bool given, string path)
{
	if (!given) {
		cout << "Unesite adresu fajla: " << "\n";
		cin >> path;
	}

	ofstream _file(path, ios::out | ios_base::binary);

	for (int i = 0; i < stdc_vec.size(); i++) {
		StudentCourses studcourse = stdc_vec[i];
		Student student = studcourse.get_student();
		Courses course = studcourse.get_courses();

		char r = ' ';
		char nextline = '\n';
		_file.write(student.get_first_name().c_str(), student.get_first_name().size() * sizeof(char));
		_file.write(&r, sizeof(char));

		_file.write(student.get_last_name().c_str(), student.get_last_name().size() * sizeof(char));
		_file.write(&r, sizeof(char));

		_file.write(student.get_id().c_str(), student.get_id().size() * sizeof(char));
		_file.write(&r, sizeof(char));

		int s = int(course.get_final_score());
		_file.write((char*)&s, sizeof(int));
		_file.write(&r, sizeof(char));

		char letter = course.get_letter_grade();
		_file.write((char*)&letter, sizeof(char));
		_file.write(&r, sizeof(char));
		_file.write(&nextline, sizeof(char));
	}
	_file.close();
}

void GroupOfStudents::callSort()
{
	sort(stdc_vec, 0, stdc_vec.size() - 1);
}


void GroupOfStudents::write_to_file(bool given, string path) {
	if (!given) {
		cout << "Unesite adresu fajla: " << "\n";
		cin >> path;
	}
		ofstream _file;
		_file.open(path);

		for (int i = 0; i < stdc_vec.size(); i++) {
			_file << stdc_vec[i];
		}

		_file.close();
	
}