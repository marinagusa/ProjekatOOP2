//============================================================================
// File Name   : Courses.h
// Authors     : You
// Version     : 1.0
// Copyright   : Your copyright notice (if applicable)
// Description : C++ group project
//============================================================================

#ifndef COURSES_H_
#define COURSES_H_

#include <iostream>
#include <vector>

using std::vector;
using namespace std;

class Courses
{
public:
	static const int NUM_QUIZZES = 10;
	static const int NUM_HW = 6;
	static const int NUM_TESTS = 4;

private:
	// this will not compile
	// non-integral constants must be initialized in Courses.cpp
	// with these values 0.05, 0.5, 0.45


	// private data
	vector<int> quiz;
	vector<int> homework;
	vector<int> test;
	double final_score;
	char letter_grade;

public:
	// constructors
	
	Courses (): quiz(NUM_QUIZZES), homework(NUM_HW), test(NUM_TESTS) {}
	Courses(const vector<int>& q, const vector<int>& h, const vector<int>& t)
		: quiz(q), homework(h), test(t), final_score(0), letter_grade('F') {}


	// utility functions
	vector<int> get_quiz();
	void set_quiz(vector<int> quiz);
	vector<int> get_homework();
	void set_homework(vector<int> homework);
	vector<int> get_test();
	void set_test(vector<int> test);
	double get_final_score();
	void set_final_score(double final_score);
	char get_letter_grade();
	void set_letter_grade(char letter_grade);
	bool value_test();

	void display();
	void calc_final_score();
	void calc_letter_grade();
	void input_format_check();

	friend istream& operator >> (istream& in, Courses& c);
};


#endif 
