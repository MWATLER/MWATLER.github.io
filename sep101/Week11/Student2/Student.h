//Student.h - header file for student

class Student {
    int no;
    char *name;
    double *marks;
    double aveMark;
    int numMarks;

public:
    Student();
    void enterInformation();
    double average();
    void displayInformation();
    ~Student();
};