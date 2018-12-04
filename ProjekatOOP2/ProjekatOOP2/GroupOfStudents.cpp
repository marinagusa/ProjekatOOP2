//============================================================================
// File Name   : GroupOfStudents.cpp
// Authors     : You
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================

//  Your code starts here

#include "GroupOfStudents.h"

void GroupOfStudents::izracunajisetuj(){
	for (int i = 0; i < this->stdc_vec.size(); i++) {
		this->stdc_vec[i].get_courses().set_final_score(this->stdc_vec[i].get_final_score());
		this->stdc_vec[i].get_courses().set_letter_grade(this->stdc_vec[i].get_letter_grade());
	}
}

void GroupOfStudents::display() {
	izracunajisetuj();

	for (int i = 0; i < this->stdc_vec.size(); i++) {
		this->stdc_vec[i].display();
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

void GroupOfStudents::sortiraj(vector<StudentCourses>& sc) {

}

void GroupOfStudents::display_sorted() {
	sortiraj(this->stdc_vec);
	display();
}