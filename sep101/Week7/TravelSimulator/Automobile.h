// Automobile.h - Header file for the Automobile

#define MAX_STR 32

struct Automobile {
    char make[MAX_STR];
    char model[MAX_STR];
    char colour[MAX_STR];
    int year;
    double fuelEfficiency;
    double fuelInTank;
};

int drive(struct Automobile *automobile, double _distance);
void displayReport(struct Automobile automobile);