//ThreadPackagedTask.cpp - main function to demonstrate a packaged task

#include <iostream>
#include <thread>
#include <future>
#include <windows.h>

double task(int x) { 
    std::cout << "task:" << std::endl;
    Sleep(2000);
    return (double)x * 2;//A packaged task returns a value only at the end of the task
}

int main() {
    std::packaged_task<double(int)> pt(task);
    auto f = pt.get_future();
    pt(10);//I can invoke the packaged task anywhere within main()
    double r = f.get();//But I have to wait for the task to complete before "getting" my value
    std::cout << "Result = " << r << std::endl;
}
