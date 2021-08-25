//LambdaSelect.cpp - main function to demonstrate the use of lambda's

#include <iostream>
#include <vector>

using namespace std;

void output_vector(const string& title, const vector<int>& vec) {
	cout << title << endl;
	for (int number : vec) {
		cout << "Number: " << number << endl;
	}
}

int main() {
	cout << "C++ Lambda Expressions" << endl;

	vector<int> vec = { 33,44,55,28,72 };

	cout << "Before erase!" << endl;
	output_vector("Integer Vectors", vec);
	cout << endl;

	//Erase items higher than 50
	const int max = 50;
	vec.erase
	(
		remove_if
		(
			vec.begin(), vec.end(),
			[max](int number)->bool//could use [=] pass by value, or [&] pass by reference
			{
				if (number > max) return true;
				return false;
			}
		)
		, vec.end()
	);

	cout << "After erase!" << endl;
	output_vector("Integer Vectors", vec);
	cout << endl;


	return 0;
}