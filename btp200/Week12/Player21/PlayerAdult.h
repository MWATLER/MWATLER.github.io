//PlayerAdult.h - class declaration for a adult card player

#ifndef _PLAYERADULT_H_
#define _PLAYERADULT_H_

#include<iostream>
#include "PlayerBase.h"

template<class T>
class PlayerAdult : public PlayerBase<T> {
	T* attackCard;
	int numAttackCards;
	void utilInit() {
		attackCard = nullptr;
		numAttackCards = 0;
	}
	void utilCopyAdultPlayer(const PlayerAdult& player) {
		numAttackCards = player.numAttackCards;
		if (numAttackCards > 0) {
			attackCard = new T[numAttackCards];
			for (int i = 0; i < numAttackCards; ++i) {
				attackCard[i] = player.attackCard[i];
			}
		}
	}
public:
	PlayerAdult() {
		utilInit();
	}
	PlayerAdult(std::string _name) : PlayerBase<T>(_name) {
		utilInit();
	}
	PlayerAdult(const PlayerAdult& player) : PlayerBase(player) {
		utilCopyAdultPlayer(player);
	}
	PlayerAdult& operator=(const PlayerAdult& rhs) {
		if (this != &rhs) {
			PlayerBase::operator=(rhs);
			if (attackCard != nullptr) {
				delete[] attackCard;
				attackCard = nullptr;
			}
			utilCopyAdultPlayer(rhs);
		}
	}
	void AddAttackCards(int num) {
		if (attackCard != nullptr) {
			delete[] attackCard;
		}
		numAttackCards = num;
		attackCard = new T[numAttackCards];
		for (int i = 0; i < numAttackCards; ++i) {
			attackCard[i] = (T)(rand() % 15000) / 1000 + 1;//generate a number between 1 and 15
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
		temp[numAttackCards] = (T)(rand() % 15000) / 1000 + 1;//add the card
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
	~PlayerAdult() {
		if (attackCard != nullptr) {
			delete[] attackCard;
			attackCard = nullptr;
		}
	}
};

#endif// _PLAYERADULT_H_