//============================================================================
// File Name   : Courses.cpp
// Authors     : You
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================

//  Your code starts here

#include "Courses.h"
#include <iostream>
#include <vector>
using namespace std;
using std::vector;

static const double QUIZ_WORTH = 0.05;
static const double HOMEWORK_WORTH = 0.5;
static const double TEST_WORTH = 0.45;

vector<int> Courses::get_quiz() {
	return this->quiz;
}

void Courses::set_quiz(vector<int> quiz) {
	this->quiz = quiz;
}

vector<int> Courses::get_homework() {
	return this->homework;
}

void Courses::set_homework(vector<int> homework) {
	this->homework = homework;
}

vector<int> Courses::get_test() {
	return this->test;
}

void Courses::set_test(vector<int> test) {
	this->test = test;
}

double Courses::get_final_score() {
	return this->final_score;
}

void Courses::set_final_score(double final_score) {
	this->final_score = final_score;
}

char Courses::get_letter_grade() {
	return this->letter_grade;
}

void Courses::set_letter_grade(char letter_grade) {
	this->letter_grade = letter_grade;
}


void Courses::calc_final_score(){
	double final_score = 0.0;
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

	quiz_score = (quiz_score / quiz.size()) * QUIZ_WORTH;
	homework_score = (homework_score/homework.size()) * HOMEWORK_WORTH;
	test_score = (test_score/test.size()) * TEST_WORTH;

	final_score = quiz_score + homework_score + test_score;
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

void Courses::display() {
	cout << round(final_score) << " " << letter_grade << endl;
}

