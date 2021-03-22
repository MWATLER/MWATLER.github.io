//Animal.cpp - function definitions for animal

#include <iostream>
#include <string>
#include "Cat.h"
#include "Dog.h"

using namespace std;

void operator<<(Animal& an, double amt) {//add weight
    if (amt > 0) {
        an.addWeight(amt);
    }
}

void operator>>(Animal& an, double amt) {//reduce weight
    if (amt > 0) {
        an.reduceWeight(amt);
    }
}

Animal* CreateAnimal() {
    Animal* an = nullptr;
    int sel=0;
    do {
        system("CLS");
        cout << "1.Cat" << endl;
        cout << "2.Dog" << endl;
        cout << "Make a selection: ";
        cin >> sel;
        string name;
        double weight;
        double age;
        cout << "What's the name of your pet? ";
        cin.ignore(1000, '\n');
        getline(cin, name);
        cout << "How much does your pet weight? ";
        cin >> weight;
        cout << "How old is your pet? ";
        cin >> age;
        if (sel == 1) {
            an = new Cat(name);
            an->SetWeight(weight);
            an->SetAge(age);
        }
        else if (sel == 2) {
            an = new Dog(name);
            an->SetWeight(weight);
            an->SetAge(age);
        }
    } while (sel < 1 || sel>2);
    return an;
}