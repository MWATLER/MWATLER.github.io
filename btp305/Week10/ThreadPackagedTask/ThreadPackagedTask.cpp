//ThreadPackagedTask.cpp - main function to demonstrate a packaged task

#include <iostream>
#include <thread>
#include <future>
#include <windows.h>

double task(int x) { 
    std::cout << "task:" << std::endl;
    Sleep(2000);
    return (double)x * 2; 
}

int main() {
    std::packaged_task<double(int)> pt(task);
    auto f = pt.get_future();
    pt(10);
    std::cout << "Waiting for the result..." << std::endl;
    double r = f.get();
    std::cout << "Result = " << r << std::endl;
}
