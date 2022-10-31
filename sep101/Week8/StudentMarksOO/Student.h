//Student.h - structure declaration and function prototypes for student marks

const int BUF_LEN = 64;
const int MAX_MARKS = 6;

/*
struct Student {
	char name[BUF_LEN];
	int year;
	int mark[MAX_MARKS];
	int numMarks;
	double average;
};

double CalculateAveragePassByValue(struct Student student);
bool CalculateAveragePassByAddress(struct Student *student);
bool CalculateAverages(struct Student *student, int length);
*/

class Student {
	//NOTE: class variables are usually not public
public:
	char name[BUF_LEN];
	int year;
	int mark[MAX_MARKS];
	int numMarks;
	double average;
	bool CalculateAverage();//function prototype
};

double CalculateOverallAverage(Student* student, int length);