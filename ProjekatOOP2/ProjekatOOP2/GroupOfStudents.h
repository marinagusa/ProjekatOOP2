//============================================================================
// File Name   : GroupOfStudents.h
// Authors     : Marko Cvijanovic, Milorad Radovic, Marina Gusa
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
	void search_for_highest(vector<int>& indices_max) const;

public:
	GroupOfStudents() {};
	GroupOfStudents(vector< StudentCourses >& v);

	vector<StudentCourses>& get_student_courses();
	void set_student_courses(vector<StudentCourses>&);
	void set_student_courses_empty();

	void display(string);
	void display_all();	
	void display_highest();
	void write_to_file(bool,string);
	void callSort();
	void sort(vector<StudentCourses>& sc, int, int);
	void write_binary(bool, string);

	friend ostream& operator<<(ostream& os, GroupOfStudents gs);


};

#endif /*GROUPOFSTUDENTS_H_*/
