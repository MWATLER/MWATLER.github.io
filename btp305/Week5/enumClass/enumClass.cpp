// enumClass.cpp - Enumeration within a class

#include <iostream>

class Ticket {
public:

//  enum classes - enumerator names are local to the enum and their values do not 
//                 implicitly convert to other types(like another enum or int).
//                 ADVANTAGE: Makes enumerations both strongly typed and strongly scoped.
//   Plain enums - where enumerator names are in the same scope as the enum and 
//                 their values implicitly convert to integers and other types.
//                 LIMITATION: Two enumerations cannot share the same name.
//                             No variable can have a name which is already in a plain enumeration.
    enum class TicketType {
        Adult, 
        Child
    };
    void set(TicketType tt);
    TicketType get() const;
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

void Ticket::set(TicketType tt) { ticketType = tt; }

auto Ticket::get() const -> TicketType { return ticketType; }

int main() {
    Ticket a, b;
    a.set(Ticket::TicketType::Adult);
    b.set(Ticket::TicketType::Child);
    std::cout << a.get() << std::endl;
    std::cout << b.get() << std::endl;
}
