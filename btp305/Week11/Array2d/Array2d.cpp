//Array2d - main function for a dynamically allocated two dimensional array

#include <iostream>

using namespace std;

void CurveMarks(float **marks, int numRows, int rowSize[]) {
	for (int i = 0; i < numRows; ++i) {//go through each row, or go through each student
		for (int j = 0; j < rowSize[i]; ++j) {//go through each column, or go through each mark
			marks[i][j] *= 1.1;//Curve the marks up by 10%
			if (marks[i][j] > 100.0) marks[i][j] = 100.0;//cap at 100%
		}
	}
}

int main(int argc, char* argv[]) {//argv is a ragged array. For example, argv[0]: Array2d:exe, argv[1]: data.txt
	float** studentMarks;//Row: a student, Col: the marks for that student
	int numStudents;//The number of students
	int* numMarks;//The number of marks for a given student
	              //numMarks would normally be an array of size numStudents,
	              //but I don't know yet how many students there will be.
	cout << "Enter the number of students: ";
	cin >> numStudents;
	numMarks = new int[numStudents];//would be nice to use a smart pointer instead to handle this resource
//	numMarks[0] represents the number of marks for the first student
//	numMarks[1] represents the number of marks for the second student, etc...
	studentMarks = new float* [numStudents];//Allocate the number of rows, which represents the number of students
	cout << endl;
	for (int i = 0; i < numStudents; ++i) {
		cout << "Enter the number of marks for student " << (i + 1) << ": ";
		cin >> numMarks[i];//I can syntactically treat numMarks the same as an ordinary array
		studentMarks[i] = new float[numMarks[i]];//Allocate the number of columns, 
		                                         //which represents the number of marks for this student
		for (int j = 0; j < numMarks[i]; ++j) {
			cout << "Enter mark " << (j + 1) << ": ";
			cin >> studentMarks[i][j];//studentMarks[0][0]=66, studentMarks[0][1]=67, studentMarks[0][2]=88, studentMarks[0][3]=87
		}
		cout << endl;
	}

	cout << "Student Marks:" << endl;
	for (int i = 0; i < numStudents; ++i) {
		cout << "Marks for student " << (i + 1) << ":";
		for (int j = 0; j < numMarks[i]; ++j) {
			cout << " " << studentMarks[i][j];
		}
		cout << endl;
	}
	cout << endl;

	//Let's curve the marks!
	CurveMarks(studentMarks, numStudents, numMarks);

	cout << "Student Marks Curved by 10%:" << endl;
	for (int i = 0; i < numStudents; ++i) {
		cout << "Marks for student " << (i + 1) << ":";
		for (int j = 0; j < numMarks[i]; ++j) {
			cout << " " << studentMarks[i][j];
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < numStudents; ++i) {
		delete []studentMarks[i];
	}
	delete[] studentMarks;
	delete[] numMarks;
	return 0;
}