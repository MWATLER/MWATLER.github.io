//Quiz7.cpp - class declarations and definitions for a math library

#include <iostream>
using namespace std;

class MathBase {
public:
	double GetPerimeter() {
		cout << "GetPerimeter Error: You have hit the base class" << endl;
		return 0.0;
	}
	virtual double GetArea() {
		cout << "GetArea Error: You have hit the base class" << endl;
		return 0.0;
	}
	virtual double GetVolume() = 0;
};

class Rectangle : public MathBase {
	double length, width, height;
public:
	Rectangle(double l, double w, double h) {
		length = l;
		width = w;
		height = h;
	}
	double GetPerimeter() {
		return 2 * (length + width);
	}
	double GetArea() {
		return length * width;
	}
	double GetVolume() {
		return length * width * height;
	}
};

class Circle : public MathBase {
	double radius, height;
	const double PI = 3.1416;
public:
	Circle(double r, double h) {
		radius = r;
		height = h;
	}
	double GetPerimeter() {
		return 2.0 * PI * radius;
	}
	double GetArea() {
		return PI * radius * radius;
	}
	double GetVolume() {
		return PI * radius * radius * height;
	}
};

void PrintGetArea(MathBase& shape) {
	cout << shape.GetArea() << endl;
}
void PrintGetArea(Rectangle& shape) {
	cout << shape.MathBase::GetArea() << endl;
}

int main(void) {
	const int NUM = 2;
	MathBase *math[NUM];

	math[0] = new Rectangle(5.0, 6.0, 7.0);
	math[1] = new Circle(4.0, 8.0);

	for (int i = 0; i < NUM; ++i) {
		cout << "Shape " << (i + 1) << " Perimeter: " << math[i]->GetPerimeter() << endl;
		cout << "Shape " << (i + 1) << " Area:      " << math[i]->GetArea() << endl;
		cout << "Shape " << (i + 1) << " Volume:    " << math[i]->GetVolume() << endl << endl;
	}

	cout << "Testing PrintGetArea()" << endl;
	PrintGetArea(*math[0]);
	PrintGetArea((Rectangle&)*math[1]);

	for (int i = 0; i < NUM; ++i) delete math[i];

	return 0;
}