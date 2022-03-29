//StudentMain.cpp - main function for student

#include <algorithm>
#include <numeric>
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

	cout << "The vector of students:" << endl;
	for (auto e = student.begin(); e != student.end(); ++e) {
		e->DisplayInfo();
	}
	cout << endl;

	int count = 0;
	auto runningTotal = accumulate(student.begin(), student.end(), 0.0, [&](double sum, const Student& s) {
		++count;
		sum += s.GetAverage();
		return sum;
		});

	cout << "The average of the averages is " << runningTotal / count << endl;
	cout << endl;

	return 0;
}