//ParameterAdder.cpp - main program to demonstrate variadic templates

#include <iostream>

using namespace std;

template<typename T>
T adder(T v) {
	return v;
}

template<typename T, typename... Args>
T adder(T first, Args... args) {
	return first + adder(args...);
}

int main() {
	long sum = adder(1, 2, 3, 8, 7);
	cout << "sum is " << sum << endl;

	string str1 = "x", str2 = "aa", str3 = "bb";
	string strSum = adder(str1, str2, str3);
	cout << "strSum is " << strSum << endl;

	return 0;
}