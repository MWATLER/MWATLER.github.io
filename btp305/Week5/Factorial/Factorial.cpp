// Factorial.cpp - main function to demonstrate factorial using recursion and using the alternative to recursion.

#include <iostream>

//n! = n*(n-1)!
//(n-1)! = (n-1)*(n-2)*(n-3)...*3*2*1
//
//5! = 5*(4*3*2*1)
//5! = 5*4!
//4! = 4*3!
//3! = 3*2!
//2! = 2*1! = 2
//1! = 1
unsigned factorialRecursion(unsigned x) {
    if (x > 2u) return x * factorialRecursion(x - 1);//the recursive case
    else return x;//the base case
}

unsigned factorialAlternative(unsigned x) {
    unsigned result = 1u;
    while (x > 1u) {//5! = 5*4*3*2*1
        result = result * x;
        --x;
    }
    return result;
}


int main() {
    std::cout << "2! = " << factorialRecursion(2) << std::endl;
    std::cout << "3! = " << factorialRecursion(3) << std::endl;
    std::cout << "4! = " << factorialRecursion(4) << std::endl << std::endl;

    std::cout << "2! = " << factorialAlternative(2) << std::endl;
    std::cout << "3! = " << factorialAlternative(3) << std::endl;
    std::cout << "4! = " << factorialAlternative(4) << std::endl;
}
