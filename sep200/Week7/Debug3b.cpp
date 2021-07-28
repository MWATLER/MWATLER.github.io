#include<iostream>

using namespace std;

template <class T>
class Conversion
{
	int kg, km, celsius;
public:
	Conversion(int _kg, int _km, int _celsius)
	{
		kg = _kg;
		km = _km;
		celsius = _celsius;
	}

	void displayResults()
	{
		cout << kg << "kg in pounds is " << kgToPounds() << "lbs" << endl;
		cout << km << "km in miles is " << kmToMiles() << " miles" << endl;
		cout << celsius << "C in Fahrenheit is " << CelsiusToFahrenheit() << "F" << endl;
	}

	T kgToPounds() { 
		return kg*2.20462;
	}

	T kmToMiles() {
		return km*0.621371;
	}

	T CelsiusToFahrenheit() {
		return celsius*1.8+32.0;
	}
};


int main()
{
	Conversion<int> intCalc(100, 200, 29);
	Conversion<double> doubleCalc(100.0, 200.0, 29.0);

	cout << "Integer results:" << endl;
	intCalc.displayResults();

	cout << endl << "Double results:" << endl;
	doubleCalc.displayResults();

	return 0;
}



























/* ANSWER */
/* The variables kg, km and celsius should be of type T.*/
/* The constructor for Conversion should accept variables of type T.*/
/* The functions kgToPounds(), kmToMiles() and CelsiusToFahrenheit() will have to apply type conversion if T is not double.*/
