//InsertMain.cpp - main function for insert-at-end

#include <iostream>

using namespace std;

template <typename T>
T* insertAtEnd(const T arr[], size_t size, T elem) {
	T* newArray = new T[size + 1];
	for (int i = 0; i < size; ++i) {
		newArray[i] = arr[i];
	}
    delete[] arr;
	newArray[size] = elem;
	return newArray;
}

template<>
char* insertAtEnd(const char arr[], size_t size, char elem) {
    char* newArray = new char[size + 2];
    for (int i = 0; i < size; ++i) {
        newArray[i] = arr[i];
    }
    delete[] arr;
    newArray[size] = elem;
    newArray[size + 1] = '\0';
    return newArray;
}

int main()
{
    {
        int* arrI = nullptr;
        arrI = insertAtEnd(arrI, 0, 1); // 1
        arrI = insertAtEnd(arrI, 1, 5); // 1, 5
        arrI = insertAtEnd(arrI, 2, -3);// 1, 5, -3
        cout << "arrI:";
        for (int i = 0; i < 3; ++i) cout << " " << arrI[i];
        cout << endl << endl;
        delete[] arrI;
    }
    {
        double* arrD = nullptr;
        arrD = insertAtEnd(arrD, 0, 1.2);// 1.2
        arrD = insertAtEnd(arrD, 1, 2.3);// 1.2, 2.3
        arrD = insertAtEnd(arrD, 2, 3.4);// 1.2, 2.3, 3.4
        cout << "arrD:";
        for (int i = 0; i < 3; ++i) cout << " " << arrD[i];
        cout << endl << endl;
        delete[] arrD;
    }
    {
        char* arrC = nullptr;
        arrC = insertAtEnd(arrC, 0, 'a');// a\0
        arrC = insertAtEnd(arrC, 1, 'b');// ab\0
        arrC = insertAtEnd(arrC, 2, 'c');// abc\0
        cout << "arrC: " << arrC;
        cout << endl << endl;
        delete[] arrC;
    }

    return 0;
}