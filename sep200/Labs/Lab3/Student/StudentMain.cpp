//StudentMain.cpp - main function for students

#include "Student.h"
#include "LetterStudent.h"
#include "NumberStudent.h"

using namespace std;

int main() {
	int marks1[] = { 55,77,66,62 };
	int marks2[] = { 75,72,86,92,55 };
	int marks3[] = { 92, 62, 70 };
	const int NUM_STUDENT = 3;
	Student student[NUM_STUDENT] = {//uses percentage
		//Student(std::string _name, int _number, int* _marks, int _numMarks);
		{"Brett Lee", 1000123, marks1, 4 },
		{"Muttiah Muralitharan", 1000124, marks2, 5 },
		{"Lasith Malinga", 1000125, marks3, 3 },
	};

	int marks4[] = { 97, 92, 94, 85 };
	int marks5[] = { 81, 89, 76, 62, 100 };
	const int NUM_LETTER_STUDENT = 2;
	LetterStudent letterStudent[NUM_LETTER_STUDENT] = {//uses a letter grading system (A,B,C,D,F)
		{"Chris Gayle", 1000126, marks4, 4},
		{"Brian Lara", 1000127, marks5, 5},
	};

	int marks6[] = { 61, 67, 82 };
	int marks7[] = { 45, 67, 89, 82, 71 };
	int marks8[] = { 53, 45, 67, 77, 71, 68 };
	const int NUM_NUMBER_STUDENT = 3;
	NumberStudent numberStudent[NUM_NUMBER_STUDENT] = {//uses a number grading system (5,4,3,2,1,0)
		{"Wasim Akram", 1000128, marks6, 3},
		{"M S Dhoni", 1000129, marks7, 5},
		{"Shoaib Akhtar", 1000130, marks8, 6}
	};

	for (int i = 0; i < NUM_STUDENT; ++i) cout << student[i];
	for (int i = 0; i < NUM_LETTER_STUDENT; ++i) cout << letterStudent[i];
	for (int i = 0; i < NUM_NUMBER_STUDENT; ++i) cout << numberStudent[i];

	return 0;
}