//Student.cpp - student information
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>     // std::cout, std::fixed
#include <iomanip>      // std::setprecision
#include <string.h>     //strcpy()
#include "Student.h"

using namespace std;

Student::Student() {
    no = 0;
    name = nullptr;
    marks = nullptr;
    aveMark = 0.0;
    numMarks = 0;
}

void Student::enterInformation() {
    char tmpName[32];
    cout << "Enter the student's last name: ";
    cin >> tmpName;//If I entered "Mark", tmpName will look as follows:
	//tmpName[0]='M', tmpName[1]='a', tmpName[2]='r', tmpName[3]='k', tmpName[4]='\0'
    int len = strlen(tmpName);//strlen returns the number of characters, excluding the null terminator
    delete[] name;//delete name if it already exists
    name = new char[len + 1];//len is the number of characters in tmpName, +1 for the null terminator
    strcpy(name, tmpName);//strcpy copies from tmpName to name
    cout << "Enter the student number: ";
    cin >> no;
    cout << "Enter the number of marks: ";
    cin >> numMarks;
    delete[] marks;//delete marks if it already exists (C++11)
//	if (marks != nullptr) {//Before 2011 (C++11) we had to test the pointer to see
//		                   //if it was pointing to allocated memory
//		delete[] marks;
//	}
    marks = new double[numMarks];
    cout << "Enter the student's marks ("<<numMarks<<" in total):" << endl;
    for (int i = 0; i < numMarks; ++i) {
        cout << "Mark " << i + 1 << ": ";
        cin >> marks[i];
    }
}

double Student::average() {
    aveMark = 0;
    for (int i = 0; i < numMarks; ++i) aveMark += marks[i];
    aveMark /= numMarks;
    return aveMark;
}

void Student::displayInformation() const {
    cout << name << ", student number " << no << ", has an average of " << fixed << setprecision(2) << aveMark << endl << endl;
}

Student::~Student() {
    //Since 2011, there is no longer a need to test if memory has
    //actually been allocated before deleting it.
    delete[] name;
    delete[] marks;
}
