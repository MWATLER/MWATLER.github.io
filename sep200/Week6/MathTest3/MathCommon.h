//MathBase.h - function definitions for math test 3

#ifndef _MATHBASE_H_
#define _MATHBASE_H_

//Parametric polymorphism exposes a common interface to all Calculate() functions
template<typename S, typename T> T Calculate(S& math, T args[], int num) {
	return math.Calculate(args, num);//will call either MathAdd.Calculate()
}                                    //or MathMultiply.Calculate()
//In reality, this function can take any object of type S so long as that object
//exposes a Calculate function with an array and size of array as parameters

#endif _MATHBASE_H_
