//Student.h - header file for student

const int N_CHARS = 31;
const int N_MARKS = 3;

class Student {
    int num;
    char name[N_CHARS];
    double marks[N_MARKS];
    double aveMark;

public:
    void enterInformation();
    double average();
    void displayInformation();
/*	bool setName(char nm[]) {
		int len = strlen(nm);
		bool retVal;
		//What if len > N_CHARS??
		if (len < N_CHARS) {
			strcpy(name, nm);
			retVal = true;
		}
		else {
			retVal = false;
		}
		return retVal;
	}*/
};
