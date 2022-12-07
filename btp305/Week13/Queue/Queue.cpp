//Queue.cpp - main function for a queue

#include <iostream>

class Data {
    int data;
public:
    Data(int d = 0) : data(d) {}
    int out() const { 
        return data; 
    }
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
    void push_back(int d) {
        Node* p = new Node(d, nullptr);//adding to the tail, next will always be a nullptr
        if (head)
            tail->next = p;//the old tail points to the new piece of data
        else
            head = p;//if p is the first node, have head point to p
        tail = p;//update tail to point to the new piece of data
    }
    Data pop_front() {
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
    q.push_back(3);//    3->nullptr
                   //    ^         
                   //    |         
                   //head/tail
    q.push_back(5);// 3 -> 5->nullptr
                   // ^    ^
                   // |    |
                   //head tail
    q.push_back(9);// 3->5->9->nullptr
                   // ^     ^
                   // |     |
                   //head  tail
    q.push_back(8);// 3->5->9->8->nullptr
                   // ^        ^
                   // |        |
                   //head     tail

    // Remove First Node
    Data d = q.pop_front();//data=3,delete 3, head points to 5
    std::cout << "Popped " << d.out() << " from the queue" << std::endl;
    // 5->9->8->nullptr
    // ^     ^
    // |     |
    //head  tail

    // Pop Data Off the Queue
    while (!q.empty()) {
        d = q.pop_front();
        std::cout << "Popped " << d.out() << " from the queue" << std::endl;
    }
    std::cout << std::endl;
}