//StudentList.cpp - main function for students

#include<iostream>
#include<fstream>
#include <iomanip>
#include<string>
#include "Student.h"

using namespace std;

int main(void) {
	Student* student;
	int numStudents = 0;
	ifstream file;

	//Get the number of students
	file.open("Students.csv");
	while (file) {//Note: the last entry will have a carriage return
		if (file.get() == '\n') {
			++numStudents;
		}
	}
	file.close();

	//Allocate memory for the students
	student = new Student[numStudents];

	//Extract student information from the file
	file.open("Students.csv");
	for (int i = 0; i < numStudents; ++i) {
		string data;
		//get and store the student's name
		getline(file, data, ',');
		student[i].SetName(data);

		//get the number of marks and allocate memory for the marks
		getline(file, data, ',');
		int numMarks = stoi(data);//string-to-integer
		double *marks = new double[numMarks];//create an array for marks by dynamic memory allocation
		for (int j = 0; j < numMarks-1; ++j) {
			getline(file, data, ',');
			marks[j] = stod(data);//string-to-double
		}
		getline(file, data, '\n');
		marks[numMarks - 1] = stod(data);

		//Now store the marks for the student
		student[i].SetMarks(marks, numMarks);

		//Calculate the average mark for the student
		student[i].CalculateAverage();

		//deallocate memory for the marks
		delete[] marks;
		marks = nullptr;
	}
	file.close();

	//Print out the students
	for (int i = 0; i < numStudents; ++i) {
		cout << student[i].GetName() << " has an average of " << student[i].GetAverage() << endl;
	}
	cout << endl;

	//Now sort the students
	for (int i = 0; i < numStudents; ++i) {
		for (int j = i+1; j < numStudents; ++j) {
			if (student[i].GetAverage() > student[j].GetAverage()) {
				student[j].IncrementRank();
			} else {//ignore ties
				student[i].IncrementRank();
			}
		}
	}

	//Print out the students again
	for (int i = 0; i < numStudents; ++i) {
		cout << student[i].GetName() << " has an average of " << student[i].GetAverage() << " and a rank of " << student[i].GetRank() << endl;
	}
	cout << endl;

	//Create a list of students sorted by rank
	Student* studentSorted = new Student[numStudents];

	for (int i = 0; i < numStudents; ++i) {
		int rank = student[i].GetRank();
		studentSorted[rank-1].SetName(student[i].GetName());
		studentSorted[rank-1].SetMarks(student[i].GetMarks(), student[i].GetNumMarks());
		studentSorted[rank - 1].CalculateAverage();
	}


	//Print out the sorted students to the screen and to a file
	ofstream fout;
	fout.open("StudentSorted.txt");
	fout.setf(ios::fixed);
	fout.precision(2);
	cout.setf(ios::fixed);
	cout.precision(2);
	for (int i = 0; i < numStudents; ++i) {
		cout << setw(2) << (i + 1) << setw(20) << studentSorted[i].GetName() << setw(8) << studentSorted[i].GetAverage() << endl;
		fout << setw(2) << (i + 1) << setw(20) << studentSorted[i].GetName() << setw(8) << studentSorted[i].GetAverage() << endl;
	}
	fout.close();

	//Delete memory for the students
	delete[] student;
	delete[] studentSorted;

	return 0;
}