// Transaction.h

class Transaction {
    int acct;      // account number
    char type;     // credit 'c' debit 'd'
    double amount; // transaction amount

public:
    void enterAccount(void);
    void enterTransaction(void);
    void display(void);
    void add(double&);
};