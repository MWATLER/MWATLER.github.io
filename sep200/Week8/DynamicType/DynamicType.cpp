// DynamicType.cpp - main function to demonstrate dynamic types.

#include <typeinfo> // for typeid
#include <iostream>

class A {
    int x;
public:
    A(int a) : x(a) {}
    virtual void display() const {
        std::cout << x << std::endl;
    }
};

class B : public A {
    int y;
public:
    B(int a, int b) : A(a), y(b) {}
    void display() const {
        A::display();
        std::cout << y << std::endl;
    }
};

class C : public B {
    int z;
public:
    C(int a = 4, int b = 6, int c = 7) :
        B(a, b), z(c) {}
    void display() const {
        B::display();
        std::cout << z << std::endl;
    }
};

// show calls display() on all types except C
//
void show(const A* a) {//A, B, C
    C cref;
    if (typeid(*a) != typeid(cref)) {
        std::cout << typeid(*a).name() << std::endl;//prints the class name
            a->display();
    }
    else {
        std::cout << typeid(cref).name() <<//prints the class name
            " objects are private" << std::endl;
    }
}

int main() {
    A* a[3];
    a[0] = new A(3);
    a[1] = new B(2, 5);
    a[2] = new C(4, 6, 7);
    for (int i = 0; i < 3; i++)
        show(a[i]);
    for (int i = 0; i < 3; i++)
        delete a[i];
}