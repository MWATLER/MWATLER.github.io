//Student.cpp - student information

#include <iostream>     // std::cout, std::fixed
#include <iomanip>      // std::setprecision
#include "Student.h"

using namespace std;

void Student::enterInformation() {
    cout << "Enter the student's last name: ";
    cin >> name;
    cout << "Enter the student number: ";
    cin >> no;
    cout << "Enter the student's marks (3 in total):" << endl;
    for (int i = 0; i < N_MARKS; ++i) {
        cout << "Mark " << i + 1 << ": ";
        cin >> marks[i];
    }
}

double Student::average() {
    aveMark = 0;
    for (int i = 0; i < N_MARKS; ++i) aveMark += marks[i];
    aveMark /= N_MARKS;
    return aveMark;
}

void Student::displayInformation() {
    cout << name << ", student number " << no << ", has an average of " << fixed << setprecision(2) << aveMark << endl << endl;
}
