//Student.h - header file for student

const int N_CHARS = 31;
const int N_MARKS = 3;

class Student {
    int no;
    char name[N_CHARS];//no need for dynamic memory allocation
    double marks[N_MARKS];//no need for dynamic memory allocation
    double aveMark;

public:
    void enterInformation();
    double average();
    void displayInformation();
};