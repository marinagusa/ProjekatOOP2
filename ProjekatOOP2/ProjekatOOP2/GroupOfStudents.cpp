//============================================================================
// File Name   : GroupOfStudents.cpp
// Authors     : You
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================

//  Your code starts heres

#include "GroupOfStudents.h"
#include "StudentCourses.h"

void GroupOfStudents::izracunajisetuj(){
	for (int i = 0; i < this->stdc_vec.size(); i++) {
		this->stdc_vec[i].get_courses().set_final_score(this->stdc_vec[i].get_final_score());
		this->stdc_vec[i].get_courses().set_letter_grade(this->stdc_vec[i].get_letter_grade());
	}
}

void GroupOfStudents::set_student_courses(vector<StudentCourses>& sc)
{
	stdc_vec = sc;
}

void GroupOfStudents::set_student_courses_empty()
{
	stdc_vec.empty();
}

void GroupOfStudents::display() {

	for (int i = 0; i < this->stdc_vec.size(); i++) {
		this->stdc_vec[i].display();
	}
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
	izracunajisetuj();

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

void GroupOfStudents::sort(vector<StudentCourses>& sc) {
	
}

