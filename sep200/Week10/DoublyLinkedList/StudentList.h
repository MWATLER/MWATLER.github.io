//StudentList.h - class declaration for a list of student

#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <iostream>

namespace bsa {
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
//		int num;//not used. Could be used to keep track of the number of nodes in the list
	public:
		class const_iterator {
		protected:
			friend class StudentList;//has access to the private members of StudentList
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
			std::string operator*() const {
				return curr->name;
			}
		};
		class iterator :public const_iterator {
			friend class StudentList;//has access to the private members of StudentList
		public:
			iterator(Student* _curr) :const_iterator(_curr) {}
			iterator() :const_iterator() {}
			iterator operator--() {
				if (this->curr->prev) {
					this->curr = this->curr->prev;
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
		~StudentList();
	};
}

#endif// _STUDENT_H_
