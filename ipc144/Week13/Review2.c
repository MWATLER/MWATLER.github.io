#define _CRT_SECURE_NO_WARNINGS
#define CURRENT_YEAR 2019
#define NUM 3
#include <stdio.h>

struct Car {
	char brand[31];
	int year;
	double purchasePrice;
	double currentValue;
};

int GetValue(struct Car *);

int main() {
	struct Car car[NUM] = {"Toyota Corolla", 2008, 21000.00, 21000.00,
				  		   "Mazda 3", 2013, 24000.00, 24000.00,
						   "Honda Accord", 2016, 30000.00, 30000.00 };
	for (int i = 0; i < NUM; ++i) {
		int err = GetValue(&car[i]);
		if (err == 0) {
			printf("The %d %s was bought for %.2lf but is now worth %.2lf\n",
				car[i].year, car[i].brand, car[i].purchasePrice, car[i].currentValue);
		}
		else {
			printf("Your %d %s is worthless!\n", car[i].year, car[i].brand);
		}
	}
	return 0;
}

int GetValue(struct Car *car) {
	int retVal=0;
    double depreciation = 3000.00 * (CURRENT_YEAR - car->year);//Loses $3000.00 per year

	car->currentValue = car->purchasePrice - depreciation;
	if (car->currentValue <= 0) {
		car->currentValue = 0;
		retVal = -1;
	}

	return retVal;
}