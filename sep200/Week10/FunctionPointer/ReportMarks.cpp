//ReportMarks.cpp - main function to demonstrate function pointers

#include <iostream>
#include <iomanip>

using namespace std;

const int NUM_MARKS = 3;
struct Student {
	string name;
	int marks[NUM_MARKS];
};

void ReportAverageLD(const Student&);
void ReportAverageHD(const Student&);

int main() {
	const int NUM_STUDENTS = 4;
	void (*ReportAveragePtr)(const Student&);

	Student student[NUM_STUDENTS] = { 
		{"Henry Ford", 56, 67, 75},
		{"Bette Midler", 62, 64, 71},
		{"Priti Patel", 87, 98, 86},
		{"Olivia Cheng", 81,78, 79} };

	ReportAveragePtr = ReportAverageLD;
	ReportAveragePtr(student[0]);
	ReportAveragePtr(student[1]);

	ReportAveragePtr = ReportAverageHD;
	ReportAveragePtr(student[2]);
	ReportAveragePtr(student[3]);

	return 0;
}

double GetAverage(const Student& student) {
	double runningTotal = 0.0;
	for (int i = 0; i < NUM_MARKS; ++i) {
		runningTotal += student.marks[i];
	}
	return runningTotal / NUM_MARKS;
}

void ReportAverageLD(const Student& student) {
	double average = GetAverage(student);
	cout << fixed;
	cout << setprecision(2);
	cout << student.name << " has an average of " << average << endl;
}

void ReportAverageHD(const Student& student) {
	double average = GetAverage(student);
	cout << fixed;
	cout << setprecision(8);
	cout << student.name << " has an average of " << average << endl;
}