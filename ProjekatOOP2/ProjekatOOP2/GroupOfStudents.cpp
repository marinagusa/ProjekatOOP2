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
#include <iostream>
#include <fstream>



void GroupOfStudents::set_student_courses(vector<StudentCourses>& sc)
{
	stdc_vec = sc;
}

void GroupOfStudents::set_student_courses_empty()
{
	stdc_vec.empty();
}

void GroupOfStudents::display(string id) {

	for (int i = 0; i < this->stdc_vec.size(); i++) {
		if (stdc_vec[i].get_student().get_id() == id) {
			stdc_vec[i].display();
			return;
		}
	}

	cout << "Student sa trazenim brojem indeksa nije pronadjen";
	return;
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


void swap(StudentCourses* a, StudentCourses* b)
{
	StudentCourses temp = *a;
	*a = *b;
	*b = temp;
}

int partition(vector<StudentCourses>& sc, int low, int high)
{
	StudentCourses pivot = sc[high];    // pivot 
	int i = (low - 1);  // Index of smaller element 

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or 
		// equal to pivot 
		if ((sc[j] < pivot) || (sc[j] == pivot))
		{
			i++;    // increment index of smaller element 
			swap(&sc[i], &sc[j]);
		}
	}
	swap(&sc[i + 1], &sc[high]);
	return (i + 1);
}


void GroupOfStudents::sort(vector<StudentCourses>& arr, int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before 
		// partition and after partition 
		sort(arr, low, pi - 1);
		sort(arr, pi + 1, high);
	}
}

void GroupOfStudents::callSort()
{
	sort(stdc_vec, 0, stdc_vec.size() - 1);
}


void GroupOfStudents::write_to_file() {
	string adresa;
	cout << "Unesite adresu fajla: " << "\n";
	cin >> adresa;
	ofstream _file;
	_file.open(adresa);

	for (int i = 0; i < stdc_vec.size(); i++) {
		_file << stdc_vec[i];
	}

	_file.close();
}

