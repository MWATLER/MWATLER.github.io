//StudentMain.cpp - main function for the student list

#include "StudentList.h"

using namespace std;
using namespace bsa;

int main() {
	const int NUM = 5;
	StudentList studentList;
	Student* student[NUM];
	student[0] = new Student{ "Michael Phelps", 65.4 };
	student[1] = new Student{ "Usain Bolt", 92.4 };
	student[2] = new Student{ "Nadia Comaneci", 82.6 };
	student[3] = new Student{ "Simone Biles", 80.1 };
	student[4] = new Student{ "Greg Louganis", 71.0 };

	cout << "Push back the students" << endl;
	for (int i = 0; i < NUM; ++i) {
		studentList.PushBack(*student[i]);
	}
	cout << endl;

	cout << "Print List:" << endl;
	studentList.PrintList();
	cout << endl;

	cout << "Get the back student" << endl;
	Student* temp = studentList.GetBack();
	cout << "Name: " << temp->name << " Average: " << temp->average << endl << endl;
	cout << endl;

	cout << "Pop the back student" << endl;
	bool ret = studentList.PopBack();
	if (ret) cout << "Pop back successful" << endl;
	else cout << "Pop back unsuccessful" << endl;
	cout << endl;

	cout << "Print List:" << endl;
	studentList.PrintList();
	cout << endl;

	cout << "Add two more students" << endl;
	Student *stud1 = new Student{ "Carl Lewis", 88.2 };
	Student *stud2 = new Student{ "Dara Torres", 69.7 };
	studentList.PushBack(*stud1);
	studentList.PushBack(*stud2);

	cout << "Print List:" << endl;
	studentList.PrintList();
	cout << endl;

	StudentList::iterator it = studentList.GetBack();
	cout << (*it) << endl;
	--it;
	cout << (*it) << endl;

	return 0;
}