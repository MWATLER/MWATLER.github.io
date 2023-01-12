// enumClass.cpp - Enumeration within a class

#include <iostream>

class Ticket {
public:
    enum class TicketType {
        Adult, 
        Child
    };
    void set(TicketType tt) {
        ticketType = tt;
    }
    TicketType get() const {
        return ticketType;
    }
private:
    TicketType ticketType;
};

std::ostream& operator<<(std::ostream& os, const Ticket::TicketType& tt) {
    const char* label = nullptr;
    switch (tt) {
    case Ticket::TicketType::Adult:
        label = "Adult Ticket";
        break;
    case Ticket::TicketType::Child:
        label = "Child Ticket";
        break;
    default:
        label = "No Ticket";
    }
    os << label;
    return os;
}

int main() {
    Ticket a, b;
    a.set(Ticket::TicketType::Adult);
    b.set(Ticket::TicketType::Child);
    std::cout << a.get() << std::endl;
    std::cout << b.get() << std::endl;
}
