//DietClient.cpp - A dietician's client
#include "DietClient.h"

using namespace std;

DietClient::DietClient() {
	name = "";
	height = 0;
	weight = 0;
	numDays = 0;
	calories = 0;
}

DietClient::DietClient(string _name, double _height, double _weight) {
	name = _name;
	height = _height;
	weight = _weight;
	numDays = 0;
	calories = 0;
}

DietClient::operator bool() const {//The return type of bool is implied to be bool
	bool retval = false;
	if (name.size() > 0) {
		retval = true;
	}
	return retval;
}


//Add calories to the client
DietClient& DietClient::operator+=(int _calories) {//client1 += 4000;
	calories += _calories;
	return *this;
}

//Add a food item
DietClient& DietClient::operator+=(string foodItem) {//client1 += "Apple";
	if(foodItem=="Apple") {
		calories += 81;
	}
	else if (foodItem == "Banana") {
		calories += 105;
	}
	else if (foodItem == "Carrot") {
		calories += 31;
	}
	else if (foodItem == "Bagel") {
		calories += 165;
	}
	else if (foodItem == "Yoghurt") {
		calories += 225;
	}
	else {
		cout << "Food item not found" << endl;
	}
	return *this;
}

//Pre-Increment the number of days
DietClient& DietClient::operator++() {
	++numDays;
	return *this;
}

//Post-increment the number of days
DietClient& DietClient::operator++(int) {
	++numDays;
	return *this;
}

double DietClient::GetCaloriesPerDay() const {
	return (double)calories / numDays;
}

std::ostream& DietClient::PrintReport() {
	double weightGain = numDays * (GetCaloriesPerDay() - caloriesBurntPerDay) / caloriesPerKg;
	weight += weightGain;//Due to this, PrintReport() cannot be const
	double bodyMassIndex = weight / (height * height);//BMI = weight/height^2 , where weight is in kg and height in m

	cout << name << " has a height of " << height << "m and a weight of " << weight << "kg." << endl;
	cout << name << " has a body mass index of " << bodyMassIndex << endl;
	if (bodyMassIndex >= 30) cout << name << " is obese" << endl;
	else if (bodyMassIndex >= 25) cout << name << " is overweight" << endl;
	else if (bodyMassIndex >= 18.5) cout << name << " has normal weight" << endl;
	else cout << name << " is underweight" << endl;

	if (weightGain > 0) {
		cout << name << " has suffered a weight gain of " << weightGain << "kg over the last " << numDays << " days." << endl;
	}
	else if (weightGain < 0) {
		cout << name << " has enjoyed a weight loss of " << -weightGain << "kg over the last " << numDays << " days." << endl;
	}
	else {
		cout << name << " has not changed weight." << endl;
	}
	return cout;
}

