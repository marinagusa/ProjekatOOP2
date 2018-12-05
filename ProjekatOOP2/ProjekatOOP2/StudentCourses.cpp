//============================================================================
// File Name   : StudentCourses.cpp
// Authors     : You
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================
//NASE
// Your code starts here:
#include "StudentCourses.h"
#include "Student.h"
#include "Courses.h"
#include <iostream>
#include <string>
using namespace std;

StudentCourses::StudentCourses() {
}

StudentCourses::StudentCourses(Student s, Courses c) {
	this->student = s;
	this->courses = c;
}


Courses StudentCourses::get_courses() {
	return this->courses;
}

double StudentCourses::get_final_score() {
	return this->courses.get_final_score();
}

char StudentCourses::get_letter_grade() {
	return this->get_courses().get_letter_grade();
}

void StudentCourses::display() {
	cout << this->get_student().get_id() << " " << this->get_student().get_first_name() << " " << this->get_student().get_last_name() << " " << this->get_final_score() << " " << this->get_letter_grade() << endl;


}

bool StudentCourses::value_test()
{
	return courses.value_test();
}

bool StudentCourses::operator<(const StudentCourses & other)
{
	return student < other.student;
}

bool StudentCourses::operator==(const StudentCourses & other)
{
	return (student == other.student);
}

StudentCourses & StudentCourses::operator=(const StudentCourses & other)
{
	student = other.student;
	courses = other.courses;

	return *this;
}

istream& operator >> (istream& in, StudentCourses& sc) {
	in >> sc.student;
	in >> sc.courses;
	return in;
}

ostream& operator << (ostream& out, StudentCourses& sc) {
	out << sc.student << sc.courses;
	return out;
}
