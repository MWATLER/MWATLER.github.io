 // StudentMain.cpp

#include <iostream>
#include "Student.h"

int main() {
    Student harry;

    std::cin >> harry;
    std::cout << harry;

    StudentFile studentFile("Student.txt");
    studentFile << harry;
    studentFile.close();

    std::ifstream inFile("Student.txt");
    inFile >> harry;
    std::cout << harry;
}