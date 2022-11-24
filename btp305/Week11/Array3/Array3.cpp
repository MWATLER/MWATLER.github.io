//Array3.cpp - main function for a 3 dimensional array

#include <iostream>
#define NCOLS 3
#define NHEIGHT 2

void square(int a[][NCOLS][NHEIGHT], int numRows) {
	for (int i = 0; i < numRows; ++i) {//rows
		for (int j = 0; j < NCOLS; ++j) {//columns
			for (int k = 0; k < NHEIGHT; ++k)//height
				a[i][j][k] *= a[i][j][k];
		}
	}
}
//#define NCOLS 3
//#define NHEIGHT 2
int main() {
	const int NROWS = 3;
	int array[NROWS][NCOLS][NHEIGHT] = {
	  {//Row 0
		{2, 3},//Column 0
		{3, 4},//Column 1
		{1, 6} //Column 2
	  },
	  {//Row 1
		{12, 13},//Column 0
		{13, 14},//Column 1
		{11, 16},//Column 2
	  },
	  {//Row 2
		{-2, 1}, //Column 0
		{-3, 11},//Column 1
		{5, 6},  //Column 2
	  },
	};
//	std::cout << "array[0][0][3] is " << array[0][0][3] << std::endl;//prints 4 and exits
	std::cout << "The array:" << std::endl;
	for (int i = 0; i < NROWS; ++i) {
		for (int j = 0; j < NCOLS; ++j) {
			for (int k = 0; k < NHEIGHT; ++k) {
				std::cout << " " << array[i][j][k];
			}
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
	square(array, NROWS);
	std::cout << "The array squared:" << std::endl;
	for (int i = 0; i < NROWS; ++i) {
		for (int j = 0; j < NCOLS; ++j) {
			for (int k = 0; k < NHEIGHT; ++k) {
				std::cout << " " << array[i][j][k];
			}
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;

	return 0;
}