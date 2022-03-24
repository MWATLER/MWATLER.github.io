//Queue.cpp - main function for a queue

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

class Queue {
    Node* head;
    Node* tail;
public:
    Queue() : head(nullptr), tail(nullptr) {}
    ~Queue() {
        Node* current;
        while (current = head) {
            head = head->next;
            delete current;
        }
    }
    void push(int d) {
        Node* p = new Node(d, 0);
        if (head)
            tail->next = p;
        else
            head = p;
        tail = p;
    }
    Data pop() {
        Data data;
        if (head) {
            Node* p = head;
            data = head->data;
            head = head->next;
            delete p;
            if (!head) tail = nullptr;
        }
        return data;
    }
    bool empty() { return head == nullptr; }
};

int main() {
    Queue q;

    // Push Data onto the Queue
    q.push(3);//head->3->nullptr, tail->3->nullptr
    q.push(5);//head->3->5->nullptr, tail->5->nullptr
    q.push(9);//head->3->5->9->nullptr, tail->9->nullptr
    q.push(8);//head->3->5->9->8->nullptr, tail->8->nullptr

    // Remove First Node
    q.pop();//data=3,head->5,delete 3

    // Pop Data Off the Queue
    while (!q.empty())
        std::cout << q.pop().out() << ' ';
    std::cout << std::endl;
}