//============================================================================
// File Name   : Student.h
// Authors     : Marko Cvijanovic, Milorad Radovic, Marina Gusa
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================


#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
#include <iostream>

using namespace std;

class Student
{
private:
	string first_name;
	string last_name;
	string id;

public:
	Student();
	Student(string first_name, string last_name, string id);

	string get_first_name();
	void set_first_name(string first_name);
	string get_last_name();
	void set_last_name(string last_name);
	string get_id();
	void set_id(string id);

	friend istream& operator>>(istream& in, Student& s);
	Student& operator= (const Student& other);
	bool operator<(const Student& other);
	bool operator==(const Student& other);
	void display();
	friend ostream& operator<<(ostream& out, Student& s);
};

#endif /*STUDENT_H_*/
