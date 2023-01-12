#include <iostream>
using namespace std;
class Vehicle {
public:
  virtual void CruiseControlOn() = 0;
  virtual void LaneAssistOn() = 0; 
  virtual ~Vehicle() {
  }
};
class Truck : public Vehicle {
  const char *type = "truck";
public:
  void display() {
      cout << "Type :" << type << endl;
  }
  ~Truck() {
  }
};

class Car : public Vehicle {
  const char *type = "Car";
public:
  void display() {
      cout << "Type :" << type << endl;
  }
  ~Car() {
  }
};

int main() {
    Truck volvo;
    Car     chevy;

    volvo.display();
    chevy.display();
}










































/* ANSWER */
/* The functions CruiseControlOn() and LaneAssistOn() have to be implemented in the derived classes. */