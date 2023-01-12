//Student.cpp - source code for quiz 9
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>
class Person {
	char* name;
protected:
	void SetName(const char* _name) {
		if (name != nullptr) delete[] name;
		int len = strlen(_name) + 1;
		name = new char[len];
		strcpy(name, _name);
	}
	char* GetName() const { return name; }
public:
	Person() {
		name = nullptr;
	}
	Person(const char* _name) {
		int len = strlen(_name) + 1;
		name = new char[len];
		strcpy(name, _name);
	}
	virtual ~Person() {
		if (name != nullptr) delete[] name;
	}
};

class Student :public Person {
	double* marks;
	int numMarks;
public:
	Student() {};
	Student(const char* _name, double* _marks, int _numMarks) : Person(_name) {
		marks = new double[_numMarks];
		numMarks = _numMarks;
		for (int i = 0; i < numMarks; ++i) marks[i] = _marks[i];
	}
	Student(const Student& st) : Person(st.GetName()) {
		//SetMarks(rhs.marks, rhs.numMarks)
		marks = nullptr;
		*this = st;
		/*		marks = new double[st.numMarks];
				numMarks = st.numMarks;
				for (int i = 0; i < numMarks; ++i) marks[i] = st.marks[i];*/
	}
	Student& operator=(const Student& rhs) {
		if (this != &rhs) {
			//SetName(rhs.GetName())
			Person::SetName(rhs.GetName());
			//SetMarks(rhs.marks, rhs.numMarks)
			if (marks != nullptr) delete[] marks;
			marks = new double[rhs.numMarks];
			numMarks = rhs.numMarks;
			for (int i = 0; i < numMarks; ++i) marks[i] = rhs.marks[i];
		}
		return *this;
	}
	Student(Student&& st) noexcept {
		*this = std::move(st);
	}
	Student& operator=(Student&& rhs) {
		if (this != &rhs) {
			//shallow copies
			Person::SetName(rhs.GetName());
			numMarks = rhs.numMarks;
			//remove the resource on the current object
			delete[] marks;
			//take control of the resource on the rhs
			marks = rhs.marks;
			//put the rhs into an empty state
			rhs.SetName("");
			rhs.numMarks = 0;
			rhs.marks = nullptr;
		}
		return *this;
	}
	void SetName(const char* _name) {
		Person::SetName(_name);
	};
	char* GetName() const { return Person::GetName(); };
	void SetMarks(double* _marks, int _numMarks) {
		if (marks != nullptr) delete[] marks;
		marks = new double[_numMarks];
		numMarks = _numMarks;
		for (int i = 0; i < numMarks; ++i) marks[i] = _marks[i];
	};
	double GetAverage() {
		double runningTotal = 0.0;
		for (int i = 0; i < numMarks; ++i) runningTotal += marks[i];
		return runningTotal / numMarks;
	}
	~Student() {
		if (marks != nullptr) delete[] marks;
	}
};

int main(void) {
	double marks1[] = { 55.0, 66.0, 66.0, 76.0 };
	Student student1("Beth", marks1, 4);
	double marks2[] = { 77.0, 66.0, 82.0, 86.0, 90.0 };
	Student student2("John", marks2, 5);
	Student student3(student2);
	student3.SetName("Barry");
	Student student4;
	student4 = student1;

	std::cout << student1.GetName() << " has an average of " << student1.GetAverage() << "%" << std::endl;
	std::cout << student2.GetName() << " has an average of " << student2.GetAverage() << "%" << std::endl;
	std::cout << student3.GetName() << " has an average of " << student3.GetAverage() << "%" << std::endl;
	std::cout << student4.GetName() << " has an average of " << student4.GetAverage() << "%" << std::endl;

	Student student5(std::move(student4));
	std::cout << student4.GetName() << " has an average of " << student4.GetAverage() << "%" << std::endl;
	std::cout << student5.GetName() << " has an average of " << student5.GetAverage() << "%" << std::endl;
	return 0;
}