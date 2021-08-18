//Reorder.cpp - main function for reordering an array

#include <algorithm>
#include <iostream>
#include "Stack.h"

using namespace std;

void ReOrder(int newarr[], int arr[], int size) {
	Stack stack;
	Queue queue;
	//TODO: Complete this function using stack and queue
	//      The number 0 is used as a delimiter between sets of numbers
	//      The new array should have all negative numbers on one side
	//      and all positive numbers on the other side.
	//      The zero should be pushed to the end of the array.
	//      See the sample run.
}

//TODO: Provide a custom compare function to sort the numbers from greatest to least

int main() {
	const int SIZE = 18;
	int array[] = { -3,2,-1,5,1,-4,0,11,12,13,-11,-12,0,-1,-2,6,8,7 };
	int newArray[SIZE] = { 0 };
	
	//Print out the original array
	std::cout << "array:    ";
	for (int i = 0; i < SIZE; ++i) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
	
	//Reorder this array in newArray
	ReOrder(newArray, array, SIZE);
	//Print out the new array
	std::cout << "newArray: ";
	for (int i = 0; i < SIZE; ++i) {
		std::cout << newArray[i] << " ";
	}
	std::cout << std::endl;

    //TODO: sort newArray using the standard sort function providing a
	//      custom compare function to sort the numbers from greatest to least.
    
	//Print out the sorted new array
	std::cout << "newArray sorted: ";
	for (int i = 0; i < SIZE; ++i) {
		std::cout << newArray[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}