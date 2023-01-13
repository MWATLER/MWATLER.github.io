//SmartMarks.cpp - code to demonstrate smart pointers

#include <iostream>
#include <memory>

int main() {
//	int* marks;
	int numMarks;

	std::cout << "Enter the number of marks: ";
	std::cin >> numMarks;
//	marks = new int[numMarks];
	std::unique_ptr<int[]> marks(new int[numMarks]);

	int total = 0;
	for (int i = 0; i < numMarks; ++i) {
		std::cout << "Enter mark " << (i + 1) << ": ";
		std::cin >> marks[i];
		total += marks[i];
	}

	double average = (double)total / numMarks;
	std::cout << "Your average is " << average << std::endl;

//	delete[] marks;
	return 0;
}//marks is now out of scope, its destructor will be invoked,
 //which will destroy the array of integers