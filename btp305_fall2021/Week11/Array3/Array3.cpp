//Array3.cpp - main function for a 3 dimensional array

#include <iostream>
#define NCOLS 3
#define NHEIGHT 2

void square(int a[][NCOLS][NHEIGHT], int numRows) {
	for (int i = 0; i < numRows; ++i) {
		for (int j = 0; j < NCOLS; ++j) {
			for (int k = 0; k < NHEIGHT; ++k)
				a[i][j][k] *= a[i][j][k];
		}
	}
}

int main() {
	const int NROWS = 3;
	int array[NROWS][NCOLS][NHEIGHT] = {
	  {
		{2, 3},
		{3, 4},
		{1, 6}
	  },
	  {
		{12, 13},
		{13, 14},
		{11, 16},
	  },
	  {
		{-2, 1},
		{-3, 11},
		{5, 6},
	  },
	};

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