//ThreadAsync.cpp - main function to launch a thread asynchronously

#include <iostream>
#include <thread>
#include <future>
#include <windows.h>

double task(double x) { 
    std::cout << "task:" << std::endl;
    Sleep(5000);
    return x * 2; 
}

int main() {
    std::future<double> f = std::async(task, 10);
    std::cout << "Waiting..." << std::endl;
	//Can do all sorts of stuff while task is running
	//When task is finished, f.get() will equal what task has returned.
    double r = f.get();
    std::cout << "Result = " << r << std::endl;
}
