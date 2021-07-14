#include <iostream>
using namespace std;

class Shape {
    double width;
protected:
    double radius;
    double length;
public:
    Shape() { length = width = radius = 0.0; };
    Shape(double l, double w, double r) {
        length = l;
        width = w;
        radius = r;
        cout << "Shape::Shape" << endl;
    };
    double CalculateArea() {
        return length * width;
    };
    ~Shape() {
        cout << "Shape::~Shape" << endl;
    }
};

class Square : public Shape {
public:
    Square(double l, double w, double r) : Shape(l, w, r) { 
        cout << "Square::Square" << endl;
    };
    double CalculateArea() {
        return length * length;
    };
    ~Square() {
        cout << "Square::~Square" << endl;
    }
};

class Circle : public Shape {
public:
    Circle(double l, double w, double r) : Shape(l, w, r) { 
        cout << "Circle::Circle" << endl;
    };
    double CalculateArea() {
        const double PI = 3.14;
        return PI * radius * radius;
    };
    ~Circle() {
        cout << "Circle::~Circle" << endl;
    }

};

class Rectangle : public Shape {
public:
    Rectangle(double l, double w, double r) : Shape(l, w, r) {
        cout << "Rectangle::Rectangle" << endl;
    };
    ~Rectangle() {
        cout << "Rectangle::~Rectangle" << endl;
    }

};

int main() {
    Circle circle(0, 0, 7.0);
    Square square(6.0, 0, 0);
    Rectangle rectangle(5.0, 4.0, 0);

    cout << "The area of the circle is " << circle.CalculateArea() << endl;
    cout << "The area of the square is " << square.CalculateArea() << endl;
    cout << "The area of the rectangle is " << rectangle.CalculateArea() << endl;

    return 0;
}