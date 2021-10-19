//College.h - declarations for a College
#define MAX_STR 64
struct College {
	char name[MAX_STR];
	char address[MAX_STR];
	double tuition;
	double employerSatisfaction;
	double satisfactionToTuitionRatio;
	int ranking;
};

int CalculateSatisfactionToTuitionRatio(struct College* college);
void PrintReport(struct College college);
void utilClearInputBuffer();