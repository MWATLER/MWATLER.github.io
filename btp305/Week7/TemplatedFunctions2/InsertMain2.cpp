//InsertMain2.cpp - main function for insert-at-end

#include <iostream>

using namespace std;

template <typename S, typename T>
void insertAtEnd(S elem1, T elem2) {
	static S* array1 = nullptr;
	static T* array2 = nullptr;
	static int size1 = 0;
	static int size2 = 0;
	S* newArray1 = new S[size1 + 1];
	for (int i = 0; i < size1; ++i) newArray1[i] = array1[i];
	newArray1[size1++] = elem1;
	if (array1 != nullptr) delete[] array1;
	array1 = newArray1;

	T* newArray2 = new T[size2 + 1];
	for (int i = 0; i < size2; ++i) newArray2[i] = array2[i];
	newArray2[size2++] = elem2;
	if (array2 != nullptr) delete[] array2;
	array2 = newArray2;

	if (size1 == 3) {
		for (int i = 0; i < size1; ++i) cout << " " << array1[i];
		cout << endl;
	}
	if (size2 == 3) {
		for (int i = 0; i < size2; ++i) cout << " " << array2[i];
		cout << endl;
	}
}

template <typename S>
void insertAtEnd(S elem1, char elem2) {
	static S* array1 = nullptr;
	static char* array2 = nullptr;
	static int size1 = 0;
	static int size2 = 0;
	S* newArray1 = new S[size1 + 1];
	for (int i = 0; i < size1; ++i) newArray1[i] = array1[i];
	newArray1[size1++] = elem1;
	if (array1 != nullptr) delete[] array1;
	array1 = newArray1;

	char* newArray2 = new char[size2 + 2];
	for (int i = 0; i < size2; ++i) newArray2[i] = array2[i];
	newArray2[size2] = elem2;
	newArray2[size2 + 1] = '\0';
	++size2;
	if (array2 != nullptr) delete[] array2;
	array2 = newArray2;

	for (int i = 0; i < size1; ++i) cout << " " << array1[i];
	cout << endl;
	for (int i = 0; i < size2; ++i) cout << " " << array2[i];
	cout << endl;
}

template <>
void insertAtEnd(char elem1, char elem2) {
	static char* array1 = nullptr;
	static char* array2 = nullptr;
	static int size1 = 0;
	static int size2 = 0;
	char* newArray1 = new char[size1 + 2];
	for (int i = 0; i < size1; ++i) newArray1[i] = array1[i];
	newArray1[size1] = elem1;
	newArray1[size1 + 1] = '\0';
	++size1;
	if (array1 != nullptr) delete[] array1;
	array1 = newArray1;

	char* newArray2 = new char[size2 + 2];
	for (int i = 0; i < size2; ++i) newArray2[i] = array2[i];
	newArray2[size2] = elem2;
	newArray2[size2 + 1] = '\0';
	++size2;
	if (array2 != nullptr) delete[] array2;
	array2 = newArray2;

	for (int i = 0; i < size1; ++i) cout << " " << array1[i];
	cout << endl;
	for (int i = 0; i < size2; ++i) cout << " " << array2[i];
	cout << endl;
}

int main()
{
	{
		insertAtEnd(1, 1.2); // 1 / 1.2
		insertAtEnd(5, 2.3); // 1, 5 / 1.2, 2.3
		insertAtEnd(-3, 3.4);// 1, 5, -3 / 1.2, 2.3, 3.4
		cout << endl;
	}
	{
		insertAtEnd(1, 'a'); // 1 / a
		insertAtEnd(5, 'b'); // 1, 5 / ab
		insertAtEnd(-3, 'c');// 1, 5, -3 / abc
		cout << endl;
	}
	{
		insertAtEnd('x', 'a'); // x / a
		insertAtEnd('y', 'b'); // xy / ab
		insertAtEnd('z', 'c');// xyz / abc
		cout << endl;
	}
	return 0;
}