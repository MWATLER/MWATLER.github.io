//InsertAtEndPtr.cpp - main function for insert-at-end using function pointers

#include <iostream>

using namespace std;

char* insertAtEnd(const char arr[], size_t size, char elem){
	char* newArray = new char[size + 2];
    for (int i = 0; i < size; ++i) {
        newArray[i] = arr[i];
    }
    delete[] arr;
    newArray[size] = elem;
    newArray[size + 1] = '\0';
    return newArray;
}

char* insertAtEndUpper(const char arr[], size_t size, char elem) {
    char* newArray = new char[size + 2];
    for (int i = 0; i < size; ++i) {
        newArray[i] = toupper(arr[i]);
    }
    delete[] arr;
    newArray[size] = toupper(elem);
    newArray[size + 1] = '\0';
    return newArray;
}

char* insertAtEndLower(const char arr[], size_t size, char elem) {
    char* newArray = new char[size + 2];
    for (int i = 0; i < size; ++i) {
        newArray[i] = tolower(arr[i]);
    }
    delete[] arr;
    newArray[size] = tolower(elem);
    newArray[size + 1] = '\0';
    return newArray;
}

int main()
{
    {
        char* arrC = nullptr;
        arrC = insertAtEnd(arrC, 0, 'a');// a\0
        arrC = insertAtEnd(arrC, 1, 'B');// ab\0
        arrC = insertAtEnd(arrC, 2, 'c');// abc\0
        cout << "arrC: " << arrC << endl << endl;
        delete[] arrC;
    }
    {
        char* arrC = nullptr;
        arrC = insertAtEndUpper(arrC, 0, 'a');// A\0
        arrC = insertAtEndUpper(arrC, 1, 'B');// AB\0
        arrC = insertAtEndUpper(arrC, 2, 'c');// ABC\0
        cout << "arrC: " << arrC << endl << endl;
        delete[] arrC;
    }
    {
        char* arrC = nullptr;
        arrC = insertAtEndLower(arrC, 0, 'A');// a\0
        arrC = insertAtEndLower(arrC, 1, 'b');// ab\0
        arrC = insertAtEndLower(arrC, 2, 'C');// abc\0
        cout << "arrC: " << arrC << endl << endl;
        delete[] arrC;
    }

	cout << "-------------------" << endl << endl;
    char* (*insertAtEndFn)(const char arr[], size_t size, char elem) = nullptr;
	{
        insertAtEndFn = insertAtEnd;
        char* arrC = nullptr;
        arrC = insertAtEndFn(arrC, 0, 'a');// a\0
        arrC = insertAtEndFn(arrC, 1, 'B');// aB\0
        arrC = insertAtEndFn(arrC, 2, 'c');// aBc\0
        cout << "arrC: " << arrC << endl << endl;
        delete[] arrC;
    }
    {
        insertAtEndFn = insertAtEndUpper;
        char* arrC = nullptr;
        arrC = insertAtEndFn(arrC, 0, 'a');// A\0
        arrC = insertAtEndFn(arrC, 1, 'B');// AB\0
        arrC = insertAtEndFn(arrC, 2, 'c');// ABC\0
        cout << "arrC: " << arrC << endl << endl;
        delete[] arrC;
    }
    {
        insertAtEndFn = insertAtEndLower;
        char* arrC = nullptr;
        arrC = insertAtEndFn(arrC, 0, 'A');// a\0
        arrC = insertAtEndFn(arrC, 1, 'b');// ab\0
        arrC = insertAtEndFn(arrC, 2, 'C');// abc\0
        cout << "arrC: " << arrC << endl << endl;
        delete[] arrC;
    }

	//Declare a function pointer that returns a float, but accepts a float and int as arguments
	//This is a power function, that takes a float number, takes an int exponent, and returns a float
//	float (*powerPtr)(float num, int exp) = nullptr;

    return 0;
}