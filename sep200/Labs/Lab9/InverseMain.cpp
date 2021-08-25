//FunctorMain.cpp - main program for exercises with functors

#include <iostream>
#include <algorithm>
#include "Inverse.h"

using namespace std;

int main() {
	double mat3x3[3][3] = { {14,17,11}, {5,-8,-2}, {12,3,-16} };

	inverse<double> inverse3;
	inverse3(mat3x3);
	cout << "The inverse of mat3x3 is:" << endl;
	for (int i = 0; i < 3; ++i) {
		cout << "row " << (i + 1) << ":";
		for (int j = 0; j < 3; ++j) {
			cout << " " << mat3x3[i][j];
			if (j < 2) cout << ",";
		}
		cout << endl;
	}
	cout << endl;

	float mat3x3f[3][3] = { {14,17,11}, {5,-8,-2}, {12,3,-16} };
	inverse<float> inverse3f;
	inverse3f(mat3x3f);
	cout << "The inverse of mat3x3 as a float is:" << endl;
	for (int i = 0; i < 3; ++i) {
		cout << "row " << (i + 1) << ":";
		for (int j = 0; j < 3; ++j) {
			cout << " " << mat3x3f[i][j];
			if (j < 2) cout << ",";
		}
		cout << endl;
	}
	cout << endl;

	//Compare your answers with the inverse matrix calculator found at
	//https://matrix.reshish.com/inverse.php

	return 0;
}