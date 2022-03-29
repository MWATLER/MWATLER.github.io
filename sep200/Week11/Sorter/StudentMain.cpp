//StudentMain.cpp - main function for student

#include <algorithm>
#include <vector>
#include "Student.h"

using namespace std;

int main() {
	vector<Student> student;
	student.push_back(Student("Michael Phelps", 65.4));
	student.push_back(Student("Usain Bolt", 92.4));
	student.push_back(Student("Nadia Comaneci", 82.6));
	student.push_back(Student("Simone Biles", 80.1));
	student.push_back(Student("Greg Louganis", 71.0));

	cout << "The unsorted vector of students:" << endl;
	for (auto e = student.begin(); e != student.end(); ++e) {
		e->DisplayInfo();
	}
	cout << endl;

	sort(student.begin(), student.end(), compare);//Provide a comparison function for non-standard data types
	//I should use a lambda function, but in this example I use the address of a function implemented somewhere else

	cout << "The sorted array of students:" << endl;
	for (auto e = student.begin(); e != student.end(); ++e) {
		e->DisplayInfo();
	}
	cout << endl;

	return 0;
}