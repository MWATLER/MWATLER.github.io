//Stack.cpp - A simple program showing stacks
//Stacks are used when a function is called. All parameters are put on the stack, and popped off once the function has been exited.

#include <iostream>
#include <stack>

using namespace std;

void showdata(stack<int> stack1)
{
    while (stack1.size() > 0) {
        cout << stack1.top() << endl;//get top element
        stack1.pop();//remove top element
    }
}

int main()
{
    stack<int> mystack;
    mystack.push(230); // pushing data to the front
    mystack.push(240); // pushing data to the front
    mystack.push(250);  // pushing data to the front
    mystack.push(260);  // pushing data to the front
    cout << "Stack elements are: ";
    showdata(mystack);

    return (0);
}