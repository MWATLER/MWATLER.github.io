//PlayerYouth.h - class declaration for a youth card player

#ifndef _PLAYERYOUTH_H_
#define _PLAYERYOUTH_H_

#include<iostream>
#include "PlayerBase.h"

template<class T>
class PlayerYouth : public PlayerBase<T> {
	T* attackCard;
	int numAttackCards;
	void utilInit() {
		attackCard = nullptr;
		numAttackCards = 0;
	}
	void utilCopyYouthPlayer(const PlayerYouth& player) {
		numAttackCards = player.numAttackCards;
		if (numAttackCards > 0) {
			attackCard = new T[numAttackCards];
			for (int i = 0; i < numAttackCards; ++i) {
				attackCard[i] = player.attackCard[i];
			}
		}
	}
public:
	PlayerYouth() {
		utilInit();
	}
	PlayerYouth(std::string _name) : PlayerBase<T>(_name) {
		utilInit();
	}
	PlayerYouth(const PlayerYouth& player) : PlayerBase<T>(player) {
		utilCopyYouthPlayer(player);
	}
	PlayerYouth& operator=(const PlayerYouth& rhs) {
		if (this != &rhs) {
			PlayerBase::operator=(rhs);
			if (attackCard != nullptr) {
				delete[] attackCard;
				attackCard = nullptr;
			}
			utilCopyYouthPlayer(rhs);
		}
	}
	void AddAttackCards(int num) {
		if (attackCard != nullptr) {
			delete[] attackCard;
		}
		numAttackCards = num;
		attackCard = new T[numAttackCards];
		for (int i = 0; i < numAttackCards; ++i) {
			attackCard[i] = (T)(rand() % 10000)/1000 + 1;//generate a number between 1 and 10
		}
	}
	void AddAttackCard() {
		T* temp = new T[numAttackCards + 1];
		if (attackCard != nullptr) {
			for (int i = 0; i < numAttackCards; ++i) {
				temp[i] = attackCard[i];
			}
			delete[] attackCard;
		}
		else {
			numAttackCards = 0;
		}
		temp[numAttackCards] = (T)(rand() % 10000) / 1000 + 1;//add the card
		++numAttackCards;
		attackCard = temp;//set attackCard to the new array
	}
	T SumCards() const {
		T runningTotal = -(T)PlayerBase<T>::SumDependentCards();
		for (int i = 0; i < numAttackCards; ++i) {
			runningTotal += attackCard[i];
		}
		return runningTotal;
	}
	bool AddCash(double amt) {
		return PlayerBase::AddCash(amt);
	}
	~PlayerYouth() {
		if (attackCard != nullptr) {
			delete[] attackCard;
			attackCard = nullptr;
		}
	}
};

#endif// _PLAYERYOUTH_H_