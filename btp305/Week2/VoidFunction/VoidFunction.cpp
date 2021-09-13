//VoidFunction.cpp - main function to demonstrate a use of the void data type.

#include <iostream>

using namespace std;

struct Student {
	string name;
	int age;
};

void PrintInfo(void*);
void SetInfo(void*);

int main() {
	Student student;
	student.name = "Michal";
	student.age = 16;

	PrintInfo((void*)&student);
	SetInfo((void*)&student);
	PrintInfo((void*)&student);

	return 0;
}

void PrintInfo(void* s) {//pass by address
	Student st = *(Student*)s;//effectively pass by value
	cout << st.name << " " << st.age << endl;
}

void SetInfo(void* s) {//pass by address
	Student* st = (Student*)s;//effectively pass by address
	st->age += 2;
}
