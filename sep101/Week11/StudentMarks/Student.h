//Student.h - header file for student

const int N_CHARS = 31;
const int N_MARKS = 3;

class Student {
    int no;
    char name[N_CHARS];
    double marks[N_MARKS];
    double aveMark;

public:
    void enterInformation();
    double average();
    void displayInformation();
};