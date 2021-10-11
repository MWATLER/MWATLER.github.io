//Reorder.cpp - main function for reordering an array

#include <algorithm>
#include <iostream>
#include "Stack.h"

using namespace std;

void ReOrder(int newarr[], int arr[], int size) {
	Stack stack;
	Queue queue;
	int newArrIndex = 0;
	for (int i = 0; i < size; ++i) {
		if (arr[i] < 0) queue.enqueue(arr[i]);
		else if (arr[i] > 0) stack.push(arr[i]);
		if (arr[i] == 0 || i == (size - 1)) {
			while (!queue.isEmpty()) {
				newarr[newArrIndex++] = queue.front();
				queue.dequeue();
			}
			while (!stack.isEmpty()) {
				newarr[newArrIndex++] = stack.top();
				stack.pop();
			}
		}
	}
}

bool mysort(int i, int j) { return i > j; }

int main() {
	const int SIZE = 18;
	int array[] = { -3,2,-1,5,1,-4,0,11,12,13,-11,-12,0,-1,-2,6,8,7 };
	int newArray[SIZE] = { 0 };
	std::cout << "array:    ";
	for (int i = 0; i < SIZE; ++i) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
	ReOrder(newArray, array, SIZE);
	std::cout << "newArray: ";
	for (int i = 0; i < SIZE; ++i) {
		std::cout << newArray[i] << " ";
	}
	std::cout << std::endl;

	sort(&newArray[0], &newArray[SIZE], mysort);
	std::cout << "newArray sorted: ";
	for (int i = 0; i < SIZE; ++i) {
		std::cout << newArray[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}