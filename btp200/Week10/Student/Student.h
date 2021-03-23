// Student.h

#include <iostream> // for std::ostream, std::istream
#include <fstream>  // for std::ifstream
const int NG = 13;

class StudentFile;

class Student {
    int no;
    float grade[NG];
    int ng;
public:
    Student();
    Student(int);
    Student(int, const float*, int);
    void read(std::istream&);
    void read(std::ifstream&);
    void display(std::ostream& os) const;
    void display(StudentFile& os) const;
};

std::istream& operator>>(std::istream& is, Student& s);
std::ostream& operator<<(std::ostream& os, const Student& s);
std::ifstream& operator>>(std::ifstream& is, Student& s);

class StudentFile {
public:
    std::ofstream f;
    StudentFile(const char*);
    StudentFile& operator<<(char);
    StudentFile& operator<<(int);
    StudentFile& operator<<(float);
    void close();
};

StudentFile& operator<<(StudentFile& os, const Student& s);