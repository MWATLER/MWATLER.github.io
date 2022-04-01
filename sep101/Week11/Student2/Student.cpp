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
    cin >> tmpName;
    int len = strlen(tmpName);
    delete[] name;//delete name if it already exists
    name = new char[len + 1];//+1 for the null terminator
    strcpy(name, tmpName);
    cout << "Enter the student number: ";
    cin >> no;
    cout << "Enter the number of marks: ";
    cin >> numMarks;
    delete[] marks;//delete marks if it already exists
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

void Student::displayInformation() {
    cout << name << ", student number " << no << ", has an average of " << fixed << setprecision(2) << aveMark << endl << endl;
}

Student::~Student() {
    delete[] name;
    delete[] marks;
}
