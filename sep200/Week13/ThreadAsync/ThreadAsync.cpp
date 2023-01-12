//ThreadAsync.cpp - main function to launch a thread asynchronously

#include <iostream>
#include <thread>
#include <future>
#include <windows.h>

double task(double x) { 
    std::cout << "task:" << std::endl;
    Sleep(5000);
    return x * 2;//returns the value only at the end of the task 
}

int main() {
    std::future<double> f = std::async(task, 10);//the task is invoked immediately
    double r = f.get();//have to wait until the task completes to "get" the value
    std::cout << "Result = " << r << std::endl;
}
