//GeneralException.cpp - code to demonstrate catching exceptions

#include <iostream>

using namespace std;


int main() {
	const int SIZE = 32;
	const int NUM = 16;
	char* name = new char[SIZE];
	int* marks = new int[NUM];
	long long int dataSize;
	unsigned long int* dataArea = nullptr;

	bool isRunning = true;

	while (isRunning) {
		int mark;
		int runningTotal = 0;
		int num = 0;
		try {
			cout << "Enter name : ";
			cin >> name;
			do {
				cout << "Enter mark " << (num + 1) << " (-1 to quit) : ";
				cin >> mark;
				if (mark != -1) {
					marks[num] = mark;
					runningTotal += mark;
					++num;
				}
			} while (mark != -1);
			double average = static_cast<double>(runningTotal) / num;
			cout << name << " has an average of " << average << endl;
			//Now let's allocate a huge amount of memory
			cout << "Enter the size of the data: ";
			cin >> dataSize;
			dataArea = new unsigned long int[dataSize];
		}
		catch (const system_error& e) {
			std::cout << e.what() << endl;
			std::cout << e.code() << endl;
			cout << "Exiting gracefully..." << endl;
			isRunning = false;
		}
		catch (const std::exception& e) {
			std::cout << e.what() << endl;
			cout << "Exiting gracefully..." << endl;
			isRunning = false;
		}
		catch (...) {
			cout << "Exiting gracefully..." << endl;
			isRunning = false;
		}
	}

    delete[] name;
	delete[] marks;
	delete[] dataArea;

	return 0;
}