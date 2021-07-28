//Division.cpp - source code for templated division functions

#include <iostream>
using namespace std;

template<typename T>
T division(T& numerator, T& denominator) {//do these need to be references
	T result = numerator / denominator;
	return result;
}

template<typename T, typename W>
T division(T& numerator, W& denominator) {
	T result = numerator / denominator;
	return result;
}

int main(void) {
	double a = 10.0;
	double b = 4.0;
	int c = 3;
	double result1, result2;

	result1 = division(a, b);//which function is called
	cout << "result1 is " << result1 << endl;//what is result

	result2 = division(a, c);//which function is called
	cout << "result2 is " << result2 << endl;//what is result

	return 0;
}