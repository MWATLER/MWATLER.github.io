//Reorder.cpp - main function for reordering an array

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void ReOrder(int newarr[], int arr[], int size) {
	stack<int> stack;
	queue<int> queue;
	int newArrIndex = 0;
	for (int i = 0; i < size; ++i) {
		if (arr[i] < 0) queue.push(arr[i]);
		else if (arr[i] > 0) stack.push(arr[i]);
		if (arr[i] == 0 || i == (size - 1)) {
			while (!queue.empty()) {
				newarr[newArrIndex++] = queue.front();
				queue.pop();
			}
			while (!stack.empty()) {
				newarr[newArrIndex++] = stack.top();
				stack.pop();
			}
		}
	}
}

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

	return 0;
}