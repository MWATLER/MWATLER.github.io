//Player.h - class declaration for a player

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <iostream>

enum class Level {
	Junior,
	Intermediate,
	Senior
};

class Player {
	std::string name;
	std::string position;
	int age;
public:
	Player(std::string _name, std::string _position, int _age) {
		name = _name;
		position = _position;
		age = _age;
	}
	void DisplayInfo(void) {
		std::cout << name << " plays " << position << " and is " << age << " years old." << std::endl;
	}
	int GetAge() const { return age; }
};

template<typename T>
std::vector<Player*> SelectSeniorPlayers(T level, std::vector<Player*> players) {
	std::vector<Player*> senior;
	for (auto it = players.begin(); it != players.end(); ++it) {
		if (level(*it) == Level::Senior) {
			senior.push_back(*it);
		}
	}
	return senior;
}

#endif// _PLAYER_H_
