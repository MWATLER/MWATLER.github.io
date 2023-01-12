//Exception.cpp - main function for exceptions


#include <iostream>

using namespace std;

void divide(double a[], int i, int sizeA, double divisor) {
    if (i < 0 || i >= sizeA)
        throw "Outside bounds";
    else if (divisor == 0)
        throw divisor;
    else
        a[i] = i / divisor;
}

int main() {
    bool keepdividing = true;
    double a[] = { 1.1,2.2,3.3,4.4,5.5,6.6 }, divisor;
    int i, size = sizeof a / sizeof a[0];//sizeof a = sizeof double * 6
	                                     //sizeof a[0] = sizeof double
	                                     //sizeof double * 6 / sizeof double = 6

    do {
        try {
            cout << "Index: ";
            cin >> i;
            cout << "Divisor: ";
            cin >> divisor;
            divide(a, i, size, divisor);
            cout << "a[i] = " << a[i] << endl;
            cout << "Continuing ..." << endl;
        }
        catch (const char* msg) {//look specifically for a string that was thrown
            cout << msg << endl;
            keepdividing = false;
        }
        catch (...) {//the catch all criteria, should always be the last catch block
            cout << "Zero Division!" << endl;
            cout << "a[i] = " << a[i] << endl;
            cout << "Continuing ..." << endl;
        }
    } while (keepdividing);
}
