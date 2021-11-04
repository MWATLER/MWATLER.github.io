//Stack.h - class definitions for a Stack class and a Queue class

#ifndef _STACK_H_
#define _STACK_H_

#include<string>

const int MAX_DATA = 1000;

class Stack {
	int data[MAX_DATA];
	int count;
public:
	Stack() { count = 0; memset(data, 0, sizeof(data)); }
	void push(int v) {
		if (count < MAX_DATA - 1) {
			for (int i = count; i > 0; --i) data[i] = data[i - 1];
			data[0] = v;
			++count;
		}
	}
	void pop() {
		if (count > 0) {
			--count;
			for (int i = 0; i < count; ++i) data[i] = data[i + 1];
			data[count] = 0;
		}
	}
	int top() {
		return data[0];
	}
	bool isEmpty() {
		return count == 0;
	}
};

class Queue {
	int data[MAX_DATA];
	int count;
public:
	Queue() { count = 0; memset(data, 0, sizeof(data)); }
	void enqueue(int v) {
		if (count < MAX_DATA - 1) {
			data[count] = v;
			++count;
		}
	}
	void dequeue() {
		if (count > 0) {
			--count;
			for (int i = 0; i < count; ++i) data[i] = data[i + 1];
			data[count] = 0;
		}
	}
	int front() {
		return data[0];
	}
	bool isEmpty() {
		return count == 0;
	}

};

#endif// _STACK_H_
