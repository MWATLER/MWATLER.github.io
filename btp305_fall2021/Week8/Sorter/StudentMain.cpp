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
/*
	student.push_back(Student("Nichael Phelps", 64.4));
	student.push_back(Student("Vsain Bolt", 91.4));
	student.push_back(Student("Oadia Comaneci", 83.6));
	student.push_back(Student("Timone Biles", 81.1));
	student.push_back(Student("Hreg Louganis", 70.0));

	student.push_back(Student("Aichael Phelps", 55.4));
	student.push_back(Student("Bsain Bolt", 82.4));
	student.push_back(Student("Cadia Comaneci", 72.6));
	student.push_back(Student("Dimone Biles", 70.1));
	student.push_back(Student("Ereg Louganis", 91.0));

	student.push_back(Student("Fichael Phelps", 66.4));
	student.push_back(Student("Gsain Bolt", 96.4));
	student.push_back(Student("Hadia Comaneci", 89.6));
	student.push_back(Student("Iimone Biles", 56.1));
	student.push_back(Student("Jreg Louganis", 60.0));
*/
	cout << "The unsorted array of students:" << endl;
	for (auto e = student.begin(); e != student.end(); ++e) {
		e->DisplayInfo();
	}
	cout << endl;

    //https://www.cplusplus.com/reference/algorithm/sort/
	sort(student.begin(), student.end(), compare);//Provide a comparison function for non-standard data types

	cout << "The sorted array of students:" << endl;
	for (auto e = student.begin(); e != student.end(); ++e) {
		e->DisplayInfo();
	}
	cout << endl;

	return 0;
}