//GenericMain.cpp - program to demonstrate the void parameter type

#include <iostream>

using namespace std;

struct MarksData {
	int size;
	double *mark;
};

int SquareNumber(void* param);
int AverageMark(void* param);

int main() {
	int retVal = 0;
	double number;
	MarksData marks;

	cout << "Enter a number: ";
	cin >> number;

	retVal = SquareNumber((void *)&number);
	if (retVal != 0) {
		cout << "Error in SquareNumber." << endl;
	}
	else {
		cout << "Enter the number of marks: ";
		cin >> marks.size;
		marks.mark = new double[marks.size];
		for (int i = 0; i < marks.size; ++i) {
			cout << "Enter mark " << (i + 1) << ": ";
			cin >> marks.mark[i];
		}
		retVal = AverageMark((void *)&marks);
		if (retVal != 0) {
			cout << "Error in the marks." << endl;
		}
		delete marks.mark;
	}

	return retVal;
}

int SquareNumber(void* param) {
	int ret = 0;
//	double num = *(double*)param;//pass by value
	double* num = (double*)param;//pass by address
//	double num = *static_cast<double*>(param);//pass by value
//	double* num = static_cast<double*>(param);//pass by address
	if (*num == 0) {
		ret = -1;
	}
	else {
		*num = *num * *num;
		cout << "The square is " << *num << endl << endl;
	}

	return ret;
}

int AverageMark(void* param) {
	int ret = 0;
//	MarksData student = *static_cast<MarksData*>(param);//pass by value
	MarksData student = *(MarksData*)(param);//pass by value
	double runningSum = 0.0;
	double average;

	if (student.size < 1) {
		ret = -2;
	}
	for (int i = 0; i < student.size && ret==0; ++i) {
		if (student.mark[i] < 0 || student.mark[i]>100) {
			ret = -1;
		}
		else {
			runningSum += student.mark[i];
		}
	}
	if (ret == 0) {
		average = runningSum / student.size;
		cout << "The average mark is " << average << endl;
	}

	return ret;
}