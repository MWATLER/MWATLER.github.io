//Pet.h - structure declaration for a pet

#define LEN 32

struct Pet {
	char type[LEN];
	char colour[LEN];
	int age;
	double price;
	double weight;
	char behaviourGrade[LEN];
};