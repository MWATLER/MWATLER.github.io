//Stack.cpp - main function for a stack

#include <iostream>

class Data {
    int data;
public:
    Data(int d = 0) : data(d) {}
    int out() const { return data; }
};

struct Node {
    Data data;
    Node* next;
    Node(const Data& d, Node* n) : data(d), next(n) {}
};

class Stack {
    Node* head;
public:
    Stack() : head(nullptr) {}
    ~Stack() {
        while (Node* p = head) {
            head = head->next;
            delete p;
        }
    }
    void push(int d) { head = new Node(d, head); }
    Data pop() {//with our stack, pop() will return the Data at the top of our stack
        Data data;
		//head->8->9->5->3->nullptr
        if (head) {
            Node* p = head;//a temporary pointer to assist us
            data = head->data;
            head = head->next;
            delete p;
        }
		//head->9->5->3->nullptr
        return data;//returns 8
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
	//A stack is like a "stack" of dishes:
	//   8
	//   9
	//   5
	//   3
    //head->8->9->5->3->nullptr

    // Remove first Node
    s.pop();//data=8,head points to 9, 8 is deleted
    //head->9->5->3->nullptr

    // Pop Data Off Stack
    while (!s.empty())
        std::cout << s.pop().out() << ' ';//'s.pop() returns Data, effectively Data.out()
    std::cout << std::endl;
}