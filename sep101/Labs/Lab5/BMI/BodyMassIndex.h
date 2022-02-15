//BodyMassIndex.h - header file for body mass index

#define MAX_STR 32
#define NUM_PATIENTS 3

struct Person {
	char name[MAX_STR];
	int OHIP;
	double height;//m's
	double weight;//kg's
	double BMI;
	char weightCategory[MAX_STR];
};

struct HealthCareProvider {
	char name[MAX_STR];
	struct Person patient[NUM_PATIENTS];
};

double CalculateBMI(struct Person* person);
char* DetermineWeightCategory(struct Person* person);//assumes BMI is known
double CalculateAverageBMI(struct HealthCareProvider provider);//assumes BMI's are known
