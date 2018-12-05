//============================================================================
// File Name   : GroupOfStudents.h
// Authors     : You
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================


#ifndef GROUPOFSTUDENTS_H_
#define GROUPOFSTUDENTS_H_

#include <vector>
#include "StudentCourses.h"

using std::vector;
using namespace std;

class GroupOfStudents
{
private:
	vector<StudentCourses> stdc_vec;
	void search_for_highest(vector<int>& indices_max) const; // utility

public:
	GroupOfStudents() {};
	GroupOfStudents(vector< StudentCourses >& v);

	// add required methods
	vector<StudentCourses>& get_student_courses();
	void set_student_courses(vector<StudentCourses>&);
	void set_student_courses_empty();
	
	void display();
	void display_all();	
	void display_highest();
	void write_to_file();
	void izracunajisetuj();
	void sort(vector<StudentCourses>& sc);
};

#endif /*GROUPOFSTUDENTS_H_*/
