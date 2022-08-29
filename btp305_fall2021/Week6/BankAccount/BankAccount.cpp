//BankAccount.cpp - main function for the bank account command design pattern

#include <iostream>
#include <vector>
#include "Command.h"

using namespace std;

int main() {
    BankAccount ba1(1000);
    BankAccount ba2(1000);
    vector<BankAccountCommand> commands{
        BankAccountCommand(ba1, BankAccountCommand::Action::withdraw, 200),
        BankAccountCommand(ba2, BankAccountCommand::Action::deposit, 200)
    };
    for (auto& cmd : commands)
        cmd.execute();
    cout << ba1.GetBalance() << endl;
    cout << ba2.GetBalance() << endl;

    return 0;
}