//============================================================================
// File Name   : Courses.h
// Authors     : Marko Cvijanovic, Milorad Radovic, Marina Gusa
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
	
	double final_score;
	char letter_grade;

public:
	vector<int> quiz;
	vector<int> homework;
	vector<int> test;
	Courses (): quiz(NUM_QUIZZES), homework(NUM_HW), test(NUM_TESTS) {}
	Courses(const vector<int>& q, const vector<int>& h, const vector<int>& t)
		: quiz(q), homework(h), test(t), final_score(0), letter_grade('F') {}

	double get_final_score() const;
	char get_letter_grade() const;
	bool value_test() const;

	void calc_final_score();
	void calc_letter_grade();
	void input_format_check();

	friend istream& operator >> (istream& in, Courses& c);
	Courses& operator=(const Courses& other);
	friend ostream& operator << (ostream& out, Courses& c);
};


#endif 
