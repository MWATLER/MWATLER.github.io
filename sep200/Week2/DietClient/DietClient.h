//DietClient.h - A dietician's client
#include <iostream>

class DietClient {
	std::string name;
	double height;//metres
	double weight;//kilograms
	int numDays;
	int calories;
	const int caloriesBurntPerDay = 2500;
	const double caloriesPerKg = 6600;//6600 calories will cause a 1kg weight gain
public:
	DietClient();
	DietClient(std::string _name, double _height, double _weight);
	operator bool() const;//It is known that bool is either true or false
	DietClient& operator+=(int);//Add calories to the client
	DietClient& operator+=(std::string);//Add a food item
	DietClient& operator++();//Pre-increment the number of days
	DietClient& operator++(int);//Post-increment the number of days
	double GetCaloriesPerDay() const;
	std::ostream& PrintReport();
};