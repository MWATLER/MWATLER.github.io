//StudentList.h - class declaration for a list of student

#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <iostream>
struct Student {
	//data portion
	std::string name;
	double average;
	//links portion
	Student* next;
	Student* prev;
};

class StudentList {
	Student* curr;
	Student* head;
	Student* tail;
	int num;
public:
	class const_iterator {
	protected:
		friend class StudentList;
		Student* curr;
	public:
		const_iterator(Student* _curr) {
			curr = _curr;
		}
		const_iterator() {
			curr = nullptr;
		}
		const_iterator operator--() {
			if (curr->prev) {
				curr = curr->prev;
			}
			return *this;
		}
		std::string operator*() const{
			return curr->name;
		}
	};
	class iterator :public const_iterator {
		friend class StudentList;
	public:
		iterator(Student* _curr) :const_iterator(_curr) {}
		iterator() :const_iterator() {}
		iterator operator--() {
			if (this->curr->prev) {
				this->curr = this->curr->prev;
			}
			return *this;
		}
		iterator operator++() {
			if (this->curr->next) {
				this->curr = this->curr->next;
			}
			return *this;
		}
		std::string operator*() {
			return curr->name;
		}
	};
	StudentList();
	Student* GetNext();
	Student* GetPrev();
	void PushBack(Student& student);
	Student* GetBack() const;
	bool PopBack();
	void PrintList();
	int size() { return num; }
	~StudentList();
};

#endif// _STUDENT_H_
