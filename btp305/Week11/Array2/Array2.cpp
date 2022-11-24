//Array2.cpp - main function for a two dimensional array

#include <iostream>
#define NCOLS 3

//To pass a two-dimensional array to a function, we use the name of the array as the argument in the function call.
//The corresponding function parameter receives the address of the array.  The parameter's declaration includes 
//the array's column dimension.

//The compiler determines the start of each row within the array from the column dimension (NCOLS).  
//Since the compiler assumes row-major order, the function does not require the row dimension.
void square(int a[][NCOLS], int numRows) {
	for (int i = 0; i < numRows; ++i) {
		for (int j = 0; j < NCOLS; ++j) {
			a[i][j] *= a[i][j];
		}
	}
}

//To work with a particular row from within a function, we pass the row as the argument in the function call.
void cube(int a[]) {
	//NCOLS is global, otherwise we would have to pass the number
	//of columns through to the function as the second parameter
	for (int j = 0; j < NCOLS; ++j) {
		a[j] = a[j] * a[j] * a[j];
	}
}

int main() {
	const int NROWS = 3;
	int array[NROWS][NCOLS] = {//stored in contiguous memory as: 2,3,5,3,4,7,1,6,8
		{2, 3, 5},
		{3, 4, 7},
		{1, 6, 8},
	};

	std::cout << "The array:" << std::endl;
	for (int i = 0; i < NROWS; ++i) {
		for (int j = 0; j < NCOLS; ++j) {
			std::cout << " " << array[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	square(array, NROWS);
	std::cout << "The array squared:" << std::endl;
	for (int i = 0; i < NROWS; ++i) {
		for (int j = 0; j < NCOLS; ++j) {
			std::cout << " " << array[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	//We refer to a row of a two-dimensional array by the name of the array
	//followed by the row number within brackets
	cube(array[1]);
	std::cout << "The second row of the array cubed:" << std::endl;
	for (int i = 0; i < NROWS; ++i) {
		for (int j = 0; j < NCOLS; ++j) {
			std::cout << " " << array[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	return 0;
}