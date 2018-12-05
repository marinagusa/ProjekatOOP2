//============================================================================
// File Name   : StudentCourses.h
// Authors     : You
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================
//NASE

#ifndef _STUDENTCOURSES_H_
#define _STUDENTCOURSES_H_

#include "Student.h"
#include "Courses.h"

class StudentCourses
{

private:
	Student student;
	Courses courses;

public:

	StudentCourses();
	StudentCourses(Student s, Courses c);
	Student get_student() const { return student; }
	Courses get_courses();
	double get_final_score();
	char get_letter_grade();
	void display();
	bool value_test();

	friend istream& operator >> (istream& in, StudentCourses& s);
};

#endif
