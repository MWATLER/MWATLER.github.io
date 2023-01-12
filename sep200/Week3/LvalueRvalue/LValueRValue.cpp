//LValueRValue.cpp - fun with lvalues and rvalues
//lvalues are variables that have some kind of storage
//rvalues are temporary values

#include <iostream>

using namespace std;

int GetValue() {
	return 10;
}

int& GetValue2() {//returns a reference, must return an lvalue
	static int value = 10;//the value needs to be stored somewhere
	return value;//returns an lvalue
}

void SetValue(int value) {//can accept an lvalue or an rvalue

}

void SetValue2(int& value) {//can only accept an lvalue

}

void SetValue3(const int& value) {//can accept an lvalue and an rvalue
	                //because value has to be initialized to something
}

void PrintName(string& name) {//needs a reference to an lvalue
	cout << name << endl;
}

void PrintName2(const string& name) {//needs a reference to an lvalue, can also accept an rvalue
	                                 //because the const needs to be initialized to something
	cout << name << endl;
}

void PrintName3(string&& name) {//this accepts an rvalue reference (a reference to a temporary object)
	//cannot accept a reference to an lvalue

}

int main() {
	int i = 10;//i is an lvalue, 10 is an rvalue
	           //i occupies memory, 10 does not
//  10 = i;//not possible, 10 does not occupy memory
	int a = i;//sets an lvalue to an lvalue, this is ok

	i = GetValue();//GetValue() returns an rvalue, a temporary value,
	               //           the value 10 which has no storage
//  GetValue() = 5;//not possible, GetValue() is an rvalue
	GetValue2() = 5;//this works!! GetValue2() is an lvalue
	cout << GetValue2() << endl;//this prints 5!!!

	i = 10;
	SetValue(i);//calling SetValue() with an lvalue
	SetValue(10);//calling SetValue() with an rvalue, the 10 is a temporary value,
	             //the number 10 will become an lvalue when the function is called 
	             //because it is assigned to the variable int value
//  SetValue2(10);//not possible, needs a reference to an lvalue
	SetValue3(10);//possible!!

	string firstName = "Erin";//firstName is an lvalue, "Erin" is an rvalue
	string lastName = "O\'Toole";//lastName is an lvalue, "O\'Toole" is an rvalue
	string fullName = firstName + lastName;//fullName is an lvalue, firstName+lastName is an rvalue
	//the concatenation of the two is stored in a temporary place by the compiler, then assigned to fullName

	PrintName(fullName);//passes an lvalue to PrintName, which expects a reference to an lvalue
//  PrintName(firstName+lastName);//not possible, firstName+lastName is temporary and no reference can be made to it
	PrintName2(firstName + lastName);//possible, const needs to be initialized with the temporary value of firstName+lastName

//  PrintName3(fullName);//not possible, expects an rvalue
	PrintName3(firstName + lastName);//possible, expects an rvalue

	return 0;
}