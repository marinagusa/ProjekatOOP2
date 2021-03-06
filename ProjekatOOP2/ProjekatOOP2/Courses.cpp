//============================================================================
// File Name   : Courses.cpp
// Authors     : Marko Cvijanovic, Milorad Radovic, Marina Gusa
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================

//  Your code starts here

#include "Courses.h"
#include <vector>

static const double QUIZ_WORTH = 0.05;
static const double HOMEWORK_WORTH = 0.5;
static const double TEST_WORTH = 0.45;



double Courses::get_final_score() const {
	return this->final_score;
}


char Courses::get_letter_grade() const {
	return this->letter_grade;
}


bool Courses::value_test() const{
	for (int i = 0; i<quiz.size(); i++) {
		if (quiz[i]>100 || quiz[i] < 0) {
			return false;
		}
	}

	for (int i = 0; i<homework.size(); i++) {
		if (homework[i]>100 || homework[i] < 0) {
			return false;
		}
	}

	for (int i = 0; i<test.size(); i++) {
		if (test[i]>100 || test[i] < 0) {
			return false;
		}
	}

	return true;

}
void Courses::input_format_check() {
	for (int i = 0; i<quiz.size(); i++) {
		if (quiz[i] > 100 || quiz[i] < 0) {
			cout << "Invalid input data format" << endl;
		}
	}

	for (int i = 0; i<homework.size(); i++) {
		if (homework[i] > 100 || homework[i] < 0) {
			cout << "Invalid input data format" << endl;
		}
	}

	for (int i = 0; i<test.size(); i++) {
		if (test[i] > 100 || test[i] < 0) {
			cout << "Invalid input data format" << endl;

		}
	}
}

Courses & Courses::operator=(const Courses & other)
{
	quiz = other.quiz;
	homework = other.homework;
	test = other.test;
	final_score = other.final_score;
	letter_grade = other.letter_grade;
	
	return *this;
}

void Courses::calc_final_score(){
	double res = 0.0;
	double quiz_score = 0.0;
	double homework_score = 0.0;
	double test_score = 0.0;

	for (int i = 0; i < quiz.size(); i++) {
		quiz_score += quiz[i];
	}

	for (int i = 0; i < homework.size(); i++) {
		homework_score += homework[i];
	}

	for (int i = 0; i < test.size(); i++) {
		test_score += test[i];
	}

	quiz_score = quiz_score / quiz.size();
	quiz_score = (quiz_score / quiz.size()) * QUIZ_WORTH;
	homework_score = homework_score / homework.size();
	homework_score = homework_score * HOMEWORK_WORTH;
	test_score = test_score / test.size();
	test_score = test_score * TEST_WORTH;

	res = quiz_score + homework_score + test_score;
	final_score = round(res);
}

void Courses::calc_letter_grade() {
	if (final_score >= 91) {
		letter_grade = 'A';
	}
	else if (final_score >= 81 && final_score < 91) {
		letter_grade = 'B';
	}
	else if (final_score >= 71 && final_score < 81) {
		letter_grade = 'C';
	}
	else if (final_score >= 61 && final_score < 71) {
		letter_grade = 'D';
	}
	else if (final_score >= 51 && final_score < 61) {
		letter_grade = 'E';
	}
	else {
		letter_grade = 'F';
	}
}


istream& operator>>(istream& in, Courses& cours) {
	for (int i = 0; i < cours.quiz.size(); i++) {
		in >> cours.quiz[i];	
	}


	for (int i = 0; i < cours.homework.size(); i++) {
		in >> cours.homework[i];
	}

	for (int i = 0; i < cours.test.size(); i++) {
		in >> cours.test[i];
	}

	cours.calc_final_score();
	cours.calc_letter_grade();
	return in;
}

ostream& operator<<(ostream& out, Courses& courses) {
	out << " " << courses.final_score << " " << courses.letter_grade << "\n";
	return out;
}
