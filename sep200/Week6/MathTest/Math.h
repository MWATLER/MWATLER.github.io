//Math.h - header file for the math features

/*
int square(int);
double square(double);
int square(int numerator, int denominator);
float square(float numerator, float denominator);
*/

template<typename T>
T square(T num) {
	T result = num * num;
	return result;
}

template<typename T>
T square(T numerator, T denominator) {
	T result = (numerator * numerator) / (denominator * denominator);
	return result;
}
/*
int square(int num) {
	int result = num * num;
	return result;
}

double square(double num) {
	double result = num * num;
	return result;
}

int square(int numerator, int denominator) {
	int result = (numerator * numerator) / (denominator * denominator);
	return result;
}

float square(float numerator, float denominator) {
	float result = (numerator * numerator) / (denominator * denominator);
	return result;
}
*/