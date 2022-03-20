// Factorial.cpp - main function to demonstrate factorial using recursion and using the alternative to recursion.
 // fibonacci.cpp

#include <iostream>

unsigned factorialRecursion(unsigned x) {
    if (x > 1u) return x * factorialRecursion(x - 1);//the recursive case
    else return x;//the base case
}

unsigned factorialAlternative(unsigned x) {
    unsigned result = 1u;
    while (x > 1u) {
        result = result * x;
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
