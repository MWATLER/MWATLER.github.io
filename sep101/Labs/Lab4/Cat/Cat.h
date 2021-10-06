//Cat.h - structure declarations for a cat

#define MAX_STR 32
#define MAX_TOYS 3

struct CatToy {
	char name[MAX_STR];
	char colour[MAX_STR];
	double cost;
};

struct Cat {
	char name[MAX_STR];
	int age;
	struct CatToy toy[MAX_TOYS];
	int numToys;
};

void InitializeInfo(struct Cat* cat);
int GetAverageCostPerCat(struct CatToy cattoy[], int len, double* average);