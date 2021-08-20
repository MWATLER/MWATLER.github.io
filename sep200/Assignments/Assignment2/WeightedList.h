//WeightedList.h - class definitions for a weighted list

#ifndef _WEIGHTEDLIST_H_
#define _WEIGHTEDLIST_H_

#include <iostream>

template <typename T>

class WeightedList {
	struct Node {
		T data;
		Node* next;

		Node(const T& _data) {
			data = _data;
			next = nullptr;
		}
	};
	Node* front;
	int num;
public:
	class iterator {
	protected:
		friend class WeightedList<T>;
		Node* curr;
		iterator(Node* _curr) {
			curr = _curr;
		}
	public:
		iterator() {
			curr = nullptr;
		}
		//TODO: Complete the iterator functionality

	};
	//TODO: Complete the weighted list functionality.
	//      You can put your function declarations or prototypes here
	//      and function definitions or implementations below
};

#endif// _WEIGHTEDLIST_H_