//Stack.cpp - main function for a stack

#include <iostream>

class Data {
    int data;
public:
    Data(int d = 0) : data(d) {}
    int out() const { 
        return data; 
    }
};

struct Node {//wraps around the data. Node takes data and adds linked list functionality to it
    Data data;
    Node* next;
    Node(const Data& d, Node* n) : data(d), next(n) {}
};

class Stack {//like a stack of dishes, you remove the last thing you put on the stack
    Node* head;
public:
    Stack() : head(nullptr) {}
    ~Stack() {
        while (head) {
            Node* p = head;
            head = head->next;
            delete p;
        }
    }
    void push(int d) { 
        head = new Node(d, head); 
    }//head is always pointing to the most recent thing added
    Data pop() {
        Data data;
        if (head) {
            Node* p = head;
            data = head->data;
            head = head->next;
            delete p;
        }
        return data;
    }
    bool empty() { return head == nullptr; }
};

int main() {
    Stack s;

    // Push Data Onto Stack
    s.push(3);//next points to nullptr, head points to 3
    s.push(5);//next points to 3, head points to 5
    s.push(9);//next points to 5, head points to 9
    s.push(8);//next points to 9, head points to 8
    // 8->9->5->3->nullptr
    // ^
    // |
    //head

    // Remove first Node
    s.pop();//data=8,head points to 9, 8 is deleted
    // 9->5->3->nullptr
    // ^
    // |
    //head

    // Pop Data Off Stack
    while (!s.empty())
        std::cout << s.pop().out() << ' ';//'s.pop() returns Data, effectively Data.out()
    std::cout << std::endl;

    return 0;
}