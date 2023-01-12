// Factorial.cpp - main function to demonstrate factorial using recursion and using the alternative to recursion.
 // fibonacci.cpp

#include <iostream>

unsigned factorialRecursion(unsigned x) {//beautifully implements the mathematics,
	                                     //it reflects the mathematical equation.
	                                     //To implement factorial recursively is very intuitive
    if (x > 1u) return x * factorialRecursion(x - 1);//the recursive case
    else return x;//the base case. If there is no base case, your program will run out of stack memory and crash
}

unsigned factorialAlternative(unsigned x) {
    unsigned result = 1u;
    while (x > 1u) {//will loop until x=1. If the while loop runs indefinitely, the program will hang
        result = result * x;//result=1*5, result=5*4=20, result=20*3=60, result=60*2=120
        --x;
    }
    return result;
}


int main() {
    //1! = 1
    //2! = 2*1 = 2*1!
    //3! = 3*2*1 = 3*2!
    //4! = 4*3*2*1 = 4*3!
    std::cout << "2! = " << factorialRecursion(2) << std::endl;
    std::cout << "3! = " << factorialRecursion(3) << std::endl;
    std::cout << "4! = " << factorialRecursion(4) << std::endl << std::endl;

    std::cout << "2! = " << factorialAlternative(2) << std::endl;
    std::cout << "3! = " << factorialAlternative(3) << std::endl;
    std::cout << "4! = " << factorialAlternative(4) << std::endl;
}
