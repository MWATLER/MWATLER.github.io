#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace  std;
class Person {
  char name[30];
  double age;
public:
  Person(const char* nm = "Mio", int _age = 21) {
    if (nm && _age > 0) {
      strncpy(name, nm, 30);
      name[29] = '\0';
      age = _age;
    }
    else {
      name[0] = '\0';
      age = 0;
    }
  }
  void display() const {
    if (name)
      cout << "Name: " << name << " Age: " << age << endl;
  }
};
class Youth : public Person {
  bool worksOut;
public:
  Youth() { worksOut = false; }
  Youth(bool wo, const char* nm, int _age) {
    if (strlen(nm) > 0) {
      worksOut = wo;
      strncpy(name, nm, 29);
      name[29] = '\0';
      age = _age;
    }
    else
      *this = Youth();
  }
  Youth& operator++() {
    age++;
    return *this;
  }
};
int main() {
  Youth w;
  Youth w2(3, "Miosha", 18);
  ++w2;
  ++w;
  w.display();
  w2.display();
}




















/* ANSWER */
/* age and name are private in the base class and not accessible in the derived class. */
/* age and name could be protected in the base class, then they would be accessible in the derived class. */