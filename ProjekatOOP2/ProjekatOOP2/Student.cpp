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
#include <string>
using namespace std;

Student::Student() {
}

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
	cout << id << " " << first_name << " " << last_name << endl;
}

istream& operator >> (istream& in, Student& stud) {
	string first, last, br;
	in >> first;
	in >> last;
	in >> br;

	stud.first_name = first;
	stud.last_name = last;
	stud.id = br;

	return in;

}

Student & Student::operator=(const Student & other)
{
	first_name = other.first_name;
	last_name = other.last_name;
	id = other.id;

	return *this;
}

bool Student::operator<(const Student & other)
{
	return last_name < other.last_name;
}

bool Student::operator==(const Student & other)
{
	return ((first_name == other.first_name) && (last_name == other.last_name) && (id == other.id));
}

ostream& operator<<(ostream& out, Student& s) {
	out << s.id << " " << s.first_name << " " << s.last_name << " ";
	return out;
}
