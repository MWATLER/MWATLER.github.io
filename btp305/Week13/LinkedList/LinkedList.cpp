//LinkedList.cpp - a linked list

#include <iostream>

struct Element {//structures are public by default
    int data;
    Element* next;//points to the next element in the list
    Element(int d, Element* n) {
        data = d;
        next = n;
    }
};

int main() {
    Element* head = nullptr;

    // Add one element at a time to the head of the chain 
    head = new Element(3, head);//next points to nullptr, head points to 3
    head = new Element(5, head);//next points to 3, head points to 5
    head = new Element(9, head);//next points to 5, head points to 9
    head = new Element(8, head);//next points to 9, head points to 8
    //head->8->9->5->3->nullptr, this is kind-of like a stack (LIFO)

    // Display elements from head to tail
    for (Element* p = head; p; p = p->next)
        std::cout << p->data << ' ';
    std::cout << std::endl;

    // Remove first two elements
    Element* remove = head;//remove->8
    if(head->next!=nullptr) head = head->next;//head->9
    delete remove;//removes 8
	//head->9->5->3->nullptr
    remove = head;//remove->9
	if (head->next != nullptr) head = head->next;//head->5
    delete remove;//removes 9
    //head->5->3->nullptr

    // Display elements from head to tail
    for (Element* p = head; p; p = p->next)
        std::cout << p->data << ' ';
    std::cout << std::endl;

    // Deallocate memory one element at a time
    while (Element* p = head) {
        head = head->next;
        delete p;
    }
}