// Automobile.h - Header file for the Automobile

#define MAX_STR 32

struct Automobile {
	//could collect make, model, colour, and year inside one big char array called info[]
    char make[MAX_STR];
    char model[MAX_STR];
    char colour[MAX_STR];
    int year;
    double fuelEfficiency;//or fuelEfficiencyCity and fuelEfficiencyHighway
    double fuelInTank;//may add tank capacity as well
	//engine power
	//mileage
	//maximum speed
	//acceleration
	//price
};

int drive(struct Automobile *automobile, double _distance);
void displayReport(struct Automobile automobile);