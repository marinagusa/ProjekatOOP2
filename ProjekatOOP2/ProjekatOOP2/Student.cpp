//============================================================================
// File Name   : Student.cpp
// Authors     : You
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================

//  Your code starts here

#include "Student.h"
#include <iostream>
using namespace std;

Student::Student(string first_name, string last_name, string id)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->id = id;
}

string Student::get_first_name() {
	return this->first_name;
}

void Student::set_first_name(string first_name) {
	this->first_name = first_name;
}

string Student::get_last_name() {
	return this->last_name;
}

void Student::set_last_name(string last_name) {
	this->last_name = last_name;
}

string Student::get_id() {
	return this->id;
}

void Student::set_id(string id) {
	this->id = id;
}

void Student::display() {
	cout << "Ime: " + first_name + ", Prezime: " + last_name + ", ID: " + id << endl;
}


