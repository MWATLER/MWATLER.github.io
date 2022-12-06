//Queue.cpp - main function for a queue

#include <iostream>

class Data {
    int data;
public:
    Data(int d = 0) : data(d) {}
    int out() const { return data; }
};

struct Node {//A wrapper for data with linked list functionality
    Data data;
    Node* next;
    Node(const Data& d, Node* n) : data(d), next(n) {}
};

class Queue {
    Node* head;//remove from the head
    Node* tail;//add to the tail
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
        Node* p = new Node(d, 0);//adding to the tail, next will always be a nullptr
        if (head)
            tail->next = p;//the old tail points to the new piece of data
        else
            head = p;//if p is the first node, have head point to p
        tail = p;//update tail to point to the new piece of data
    }
    Data pop() {
        Data data;
        if (head) {//remove from the head
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
    q.push(3);//    3->nullptr
              //    ^         
              //    |         
              //head/tail
    q.push(5);// 3 -> 5->nullptr
              // ^    ^
              // |    |
              //head tail
    q.push(9);// 3->5->9->nullptr
              // ^     ^
              // |     |
              //head  tail
    q.push(8);// 3->5->9->8->nullptr
              // ^        ^
              // |        |
              //head     tail

    // Remove First Node
    q.pop();//data=3,delete 3, head points to 5
	// 5->9->8->nullptr
    // ^     ^
    // |     |
    //head  tail

    // Pop Data Off the Queue
    while (!q.empty())
        std::cout << q.pop().out() << ' ';//data.out()
    std::cout << std::endl;
}