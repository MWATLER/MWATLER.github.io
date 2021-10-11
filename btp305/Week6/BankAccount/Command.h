//Command.h - class declarations for command structures

#pragma once//same as the header guard, but not portable to all compilers

class BankAccount {
	int m_balance;
public:
	BankAccount(int balance) { m_balance = balance; }
	int GetBalance(void) const { return m_balance; }
	void deposit(int amount) { m_balance += amount; }
	void withdraw(int amount) { m_balance -= amount; }
};

class Command {//in this example a base class is not needed
public:
	virtual void execute() = 0;
};

class BankAccountCommand :public Command {
public:
	enum class Action : bool { deposit, withdraw };
private:
	BankAccount& m_ac;
	Action m_action;
	int m_amount;
public:
	BankAccountCommand(BankAccount& ac, Action a, int amnt) : m_ac(ac), m_action(a), m_amount(amnt) {}
	void execute() {
		switch (m_action) {
		case Action::deposit:
			m_ac.deposit(m_amount);
			break;
		case Action::withdraw:
			m_ac.withdraw(m_amount);
			break;
		default://do nothing
			;
		}
	}
};