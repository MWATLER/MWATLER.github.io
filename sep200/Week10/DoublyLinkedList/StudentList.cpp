//StudentList.cpp - function definitions for a list of students

#include "StudentList.h"

using namespace std;
using namespace bsa;

StudentList::StudentList() {
	curr = head = tail = nullptr;
//	num = 0;
}

Student* StudentList::GetNext() {
	if (curr->next != nullptr) {
		curr = curr->next;
	}
	return curr;
}

Student* StudentList::GetPrev() {
	if (curr->prev != nullptr) {
		curr = curr->prev;
	}
	return curr;
}

//
//  For the next pointers
//  A->B->C->nullptr
//  A->B->C->student->nullptr
//
// For the prev pointers
//  A<-B<-C
//  A<-B<-C<-student
// 
// tail is pointing at C
// tail is advanced to student
void StudentList::PushBack(Student& student) {
	if (curr == nullptr) {
		curr = head = tail = &student;
		student.next = nullptr;
		student.prev = nullptr;
	}
	else {
		tail->next = &student;
		student.prev = tail;
		student.next = nullptr;
		tail = tail->next;
	}
}

Student* StudentList::GetBack() const {
	return tail;//the calling function should test this for nullptr
}

//Should be able to do a GetFront() and PopFront() since it is a doubly linked list

// For the next pointers
// A->B->C->nullptr
// A->B->nullptr
//
// For the prev pointers
// A<-B<-C
// A<-B
//
// tail is pointing at C
// tail falls back to B
bool StudentList::PopBack() {
	bool ret = true;
	if (tail == nullptr) {//no nodes left
		ret = false;
	}
	else if (tail == head) {//only one node left
		delete tail;
		head = tail = curr = nullptr;
	}
	else {//more than one node left
		tail = tail->prev;
		delete tail->next;
		tail->next = nullptr;
	}

	return ret;
}

void StudentList::PrintList() {
	Student* studentPtr = head;
	while (studentPtr != nullptr) {
		cout << "Name: " << studentPtr->name << " Average: " << studentPtr->average << endl;
		studentPtr = studentPtr->next;
	}
}

StudentList::~StudentList() {
	Student* studentPtr = head;
	while (studentPtr != nullptr) {
		Student* temp=studentPtr->next;
		delete studentPtr;
		studentPtr = temp;
	}
}
