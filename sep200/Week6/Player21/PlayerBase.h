//PlayerBase.h - base class declaration for card player

#ifndef _PLAYERBASE_H_
#define _PLAYERBASE_H_
#include<iostream>

template<class T>
class PlayerBase {
	std::string name;
	int* dependentCard;
	int numDepCards;
	double cash;
	void utilInit() {//utility function to initialize variables
		dependentCard = nullptr;
		numDepCards = 0;
		cash = 1000.00;//give each player $1000 to begin with
	}
	void utilCopyPlayer(const PlayerBase& player) {
		name = player.name;
		numDepCards = player.numDepCards;
		if (numDepCards > 0) {
			dependentCard = new int[numDepCards];
			for (int i = 0; i < numDepCards; ++i) {
				dependentCard[i] = player.dependentCard[i];
			}
		}
		cash = player.cash;
	}
public:
	virtual void AddAttackCards(int num) = 0;
	virtual void AddAttackCard() = 0;
	virtual T SumCards() const = 0;
	PlayerBase() {
		name = "";
		utilInit();
	}
	PlayerBase(std::string _name) {
		name = _name;
		utilInit();
	}
	PlayerBase(const PlayerBase& player) {
		utilCopyPlayer(player);
	}

	PlayerBase& operator=(const PlayerBase& rhs) {
		if (this != &rhs) {
			if (dependentCard != nullptr) {
				delete[] dependentCard;
				dependentCard = nullptr;
			}
			utilCopyPlayer(rhs);
		}
	}

	void SetName(const std::string _name) {
		name = _name;
	}

	std::string GetName() const {
		return name;
	}

	void AddDependentCards(int num) {
		if (dependentCard != nullptr) {
			delete[] dependentCard;
		}
		numDepCards = num;
		dependentCard = new int[numDepCards];
		for (int i = 0; i < numDepCards; ++i) {
			dependentCard[i] = rand() % 5 + 1;//generate a number between 1 and 5
		}
	}

	void AddDependentCard() {
		int* temp = new int[numDepCards + 1];
		if (dependentCard != nullptr) {
			for (int i = 0; i < numDepCards; ++i) {
				temp[i] = dependentCard[i];
			}
			delete[] dependentCard;
		}
		else {
			numDepCards = 0;
		}
		temp[numDepCards] = rand() % 5 + 1;//add the card
		++numDepCards;
		dependentCard = temp;//set dependentCard to the new array
	}

	int SumDependentCards() const {
		int runningTotal = 0;
		for (int i = 0; i < numDepCards; ++i) {
			runningTotal += dependentCard[i];
		}
		return runningTotal;
	}

	bool AddCash(double amt) {//amt could be negative
		bool ret = true;
		cash += amt;//
		if (cash < 0) {
			ret = false;
			std::cout << "Player " << name << " is out of the game." << std::endl;
		}
		return ret;
	}

	double GetCash() const {
		return cash;
	}

	~PlayerBase() {
		if (dependentCard != nullptr) {
			delete[] dependentCard;
			dependentCard = nullptr;
		}
	}

};

//Comparison operators
template<class T>
bool operator==(const PlayerBase<T>& p1, const PlayerBase<T>& p2) {
	bool ret;
	if (p1.SumCards() == p2.SumCards()) {
		ret = true;
	}
	else {
		ret = false;
	}
	return ret;
}

template<class T>
bool operator<(const PlayerBase<T>& p1, const PlayerBase<T>& p2) {
	bool ret;
	if (p1.SumCards() < p2.SumCards()) {
		ret = true;
	}
	else {
		ret = false;
	}
	return ret;
}

template<class T>
bool operator>(const PlayerBase<T>& p1, const PlayerBase<T>& p2) {
	bool ret;
	if (p1.SumCards() > p2.SumCards()) {
		ret = true;
	}
	else {
		ret = false;
	}
	return ret;
}

// Cash flow operators
template<class T>
void operator<<(PlayerBase<T>& an, double amt) { //add cash
	an.AddCash(amt);
}
template<class T>
void operator>>(PlayerBase<T>& an, double amt) {//remove cash
	an.AddCash(-amt);
}

#endif// _PLAYERBASE_H_