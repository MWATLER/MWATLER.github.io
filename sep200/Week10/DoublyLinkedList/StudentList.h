//StudentList.h - class declaration for a list of student

#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <iostream>
struct Student {
	std::string name;
	double average;
	Student* next;
	Student* prev;
};

class StudentList {
	Student* curr;
	Student* head;
	Student* tail;
	int num;
public:
	StudentList();
	Student* GetNext();
	Student* GetPrev();
	void PushBack(Student& student);
	Student* GetBack() const;
	bool PopBack();
	void PrintList();
	~StudentList();
};

#endif// _STUDENT_H_
