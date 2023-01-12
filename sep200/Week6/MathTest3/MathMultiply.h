//MathMultiply.h - class declarations for adding a series of numbers

#ifndef _MATHMULTIPLY_H_
#define _MATHMULTIPLY_H_

template<class T>
class MathMultiply {
public:
	T Calculate(T args[], int num) {
		T retVal = args[0];
		for (int i = 1; i < num; ++i) {
			retVal *= args[i];
		}
		return retVal;
	}
};

#endif// _MATHMULTIPLY_H_