//Player.cpp - function definitions for a card player
//
// 15-Feb-21  M. Watler         Created.

#include <iostream>
#include "Player.h"

using namespace std;

Player::Player() {
	name="";
	numTokens=0;
	card=0;
}

Player::Player(std::string nm, int tokens) {
	name = nm;
	numTokens = tokens;
	card = 0;
}

void Player::PlayCard() {
	if (numTokens > 0) {//21%10 -> 21/10 = 2 remainder 1. 1 is 21%10
		card = rand() % 10 + 1;//random number between 1 and 10
	}
	else {
		card = 0;
	}
	cout << name << " has played a " << card << endl;
}

int Player::GetCard() const {
	return card;
}

int Player::GetTokens() const {
	return numTokens;
}

void Player::SetTokens(int num) {
	numTokens = num;
}

void Player::DisplayInfo() const {
	cout << name << " has " << numTokens << " tokens." << endl;
}

void operator>>(Player& p1, Player& p2) {
/*	int tokens = p1.GetTokens();
	tokens += p2.GetTokens();
	p2.SetTokens(tokens);
	p1.SetTokens(0);*/
	if (&p1 != &p2) {
		int tokens = p1.numTokens;//operator>> is a friend to class Player
		tokens += p2.numTokens;   //and therefore has access to all the private
		p2.numTokens = tokens;    //members and functions of class Player
		p1.numTokens = 0;
	}
}

void operator<<(Player& p1, Player& p2) {
	if (&p1 != &p2) {
		int tokens = p2.GetTokens();
		tokens += p1.GetTokens();
		p1.SetTokens(tokens);
		p2.SetTokens(0);
	}
}

bool operator>(Player p1, Player p2) {
	bool ret = false;
	if (p1.GetCard() > p2.GetCard()) ret = true;
	return ret;
}

bool operator<(Player p1, Player p2) {
	bool ret = false;
	if (p1.GetCard() < p2.GetCard()) ret = true;
	return ret;
}