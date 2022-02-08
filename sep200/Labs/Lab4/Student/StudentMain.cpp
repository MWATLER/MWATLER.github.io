//StudentMain.cpp - main function for students

#include "Student.h"
#include "LetterStudent.h"
#include "NumberStudent.h"

using namespace std;

int main() {
	int marks1[] = { 55,77,66,62 };
	int marks2[] = { 75,72,86,92,55 };
	int marks3[] = { 92, 62, 70 };
	int marks4[] = { 97, 92, 94, 85 };
	int marks5[] = { 81, 89, 76, 62, 100 };
	int marks6[] = { 61, 67, 82 };
	int marks7[] = { 45, 67, 89, 82, 71 };
	int marks8[] = { 53, 45, 67, 77, 71, 68 };

	const int NUM_STUDENT = 8;
	Student* student[NUM_STUDENT];
	//Student(std::string _name, int _number, int* _marks, int _numMarks);
	student[0] = new Student("Brett Lee", 1000123, marks1, 4);
	student[1] = new Student("Muttiah Muralitharan", 1000124, marks2, 5);
	student[2] = new Student("Lasith Malinga", 1000125, marks3, 3);
	student[3] = new LetterStudent("Chris Gayle", 1000126, marks4, 4);
	student[4] = new LetterStudent("Brian Lara", 1000127, marks5, 5);
	student[5] = new NumberStudent("Wasim Akram", 1000128, marks6, 3);
	student[6] = new NumberStudent("M S Dhoni", 1000129, marks7, 5);
	student[7] = new NumberStudent("Shoaib Akhtar", 1000130, marks8, 6);

	for (int i = 0; i < NUM_STUDENT; ++i) cout << *student[i];

	for (int i = 0; i < NUM_STUDENT; ++i) delete student[i];

	return 0;
}