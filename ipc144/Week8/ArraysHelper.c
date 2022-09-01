// ArraysHelper.c : Helper functions for Arrays.c
//
//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section: XXY
//
// 30-Oct-2019  M Watler: Created.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Arrays.h"

//CurveGenerator - this function will take an array of marks and change them according to a factor.
//                 Marks over 100 will be set to 100. If there are more than two marks over 100 the
//                 functions returns an error.
//
// IN: marks[] - the array of marks
//     size    - the size of the array
//     factor  - the curve factor
//OUT: error status (0: OK, -1: error)
//
//31-Oct-2018  M Watler: Created
int CurveGenerator(int marks[], int size, double factor) {
	//int marks[] = grade;//pass by address
	//int size = SIZE;//pass by value
	//double factor = curveFactor;//pass by value
	int retVal = 0;
	int hundredCounter = 0;//keep track of marks with 100
	for (int i = 0; i < size && retVal == 0; ++i) {
		marks[i] = marks[i] * factor;//curve the marks
		if (marks[i] >= 100) {
			marks[i] = 100;
			++hundredCounter;
		}
		if (hundredCounter > 2) {
			retVal = -1;//error, too many hundreds
		}
	}
	return retVal;//error status
}

/*int CurveGenerator(int *marks, int size, double factor) {
	int retVal = 0;
	int hundredCounter = 0;//keep track of marks with 100
	for (int i = 0; i < size && retVal == 0; ++i) {
		*(marks+i) = *(marks+i) * factor;//curve the marks
		if (*(marks+i) > 100) {
			*(marks+i) = 100;
			++hundredCounter;
		}
		if (hundredCounter > 2) {
			retVal = -1;//error, too many hundreds
		}
	}
	return retVal;//error status
}*/

//MarksValidator - This function will take an array of marks and validate them against realistic values
//
// IN: marks[] - the array of marks
//     size    - the size of the array
//OUT: error status (0: OK, -1: error, -2: valid but unrealistic)
//
//31-Oct-2018  M Watler: Created
int MarksValidator(const int marks[], int size) {
	//const int marks[] = grade;//pass by address. Why constant? Because,
	//                                             we can only pass arrays by address, and
	//                                             we don't want the values in grade[] to change
	//int size = SIZE;//pass by value.
	const int MAXVAL = 100;
	const int MINVAL = 0;
	int hundredCounter = 0;
	const int MAXHUNDREDS = 2;

	int retVal = 0;
	for (int i = 0; i < size && retVal == 0; ++i) {
		if (marks[i]<MINVAL || marks[i]>MAXVAL) retVal = -1;
		else if (marks[i] == MAXVAL) ++hundredCounter;
		if (hundredCounter > MAXHUNDREDS) retVal = -2;
	}
	return retVal;
}