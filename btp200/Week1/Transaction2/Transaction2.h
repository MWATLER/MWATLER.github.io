// Modular Example
// Transaction2.h

class Transaction2 {
    int acct;      // account number
    char type;     // credit 'c' debit 'd'
    double amount; // transaction amount

public:
    void enter(void);
    void display(void);
};