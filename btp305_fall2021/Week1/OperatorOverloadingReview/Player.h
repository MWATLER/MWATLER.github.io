//Player.h - class declaration for a card player
//
// 15-Feb-21  M. Watler         Created.

#include <iostream>

class Player {
	std::string name;
	int numTokens;
	int card;
public:
	Player();
	Player(std::string, int);
	void PlayCard();
	int GetCard() const;
	int GetTokens() const;
	void SetTokens(int num);
	void DisplayInfo() const;
	friend void operator>>(Player& p1, Player& p2);
};

void operator>>(Player& p1, Player& p2);//p1>>p2;
void operator<<(Player& p1, Player& p2);//p1<<p2;
bool operator>(Player p1, Player p2);//p1>p2
bool operator<(Player p1, Player p2);//p1<p2