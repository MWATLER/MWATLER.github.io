//Student.h - header file for student

class Student {
    int no;
    char *name;//we don't know the size of the array for name at compile time
    double *marks;//we don't know the size of the array for marks at compile time
    double aveMark;
    int numMarks;

public:
    Student();
    void enterInformation();//allocates memory for name and marks
    double average();
    void displayInformation();
    ~Student();//deallocates memory used for name and marks
};