//BodyMassIndex.h - header file for body mass index

#define MAX_STR 32
#define NUM_PATIENTS 3

struct Person {
	char name[MAX_STR];
	int OHIP;//Ontario Health Insurance Plan number
	double height;//m's
	double weight;//kg's
	double BMI;//weight/height^2
	char weightCategory[MAX_STR];//underweight, normal weight, overweight, obese
};

struct HealthCareProvider {
	char name[MAX_STR];//the name of the health care provider
	struct Person patient[NUM_PATIENTS];//the health care provider has 3 patients
};

double CalculateBMI(struct Person* person);
char* DetermineWeightCategory(struct Person* person);//assumes BMI is known
double CalculateAverageBMI(struct HealthCareProvider provider);//assumes BMI's are known
