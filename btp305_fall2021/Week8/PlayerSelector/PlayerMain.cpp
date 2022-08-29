//PlayerMain.cpp - main function for a player

#include <vector>
#include "Player.h"

using namespace std;

int main() {
	const int NUM = 5;
	Player* player[NUM];
	player[0] = new Player("Bobby Hull", "left wing", 82);
	player[1] = new Player("Hayley Wickenheiser", "center", 43);
	player[2] = new Player("Manek Khan", "right defence", 16);
	player[3] = new Player("Marcel Dionne", "center", 70);
	player[4] = new Player("Guy Lafleur", "right wing", 70);

	vector<Player*> players;
	for(int i=0; i<NUM; ++i) players.push_back(player[i]);

	auto selectLevel = [](const Player* v) {
		Level ret;
		if (v->GetAge() <= 18) ret = Level::Junior;
		else if (v->GetAge() <= 65) ret = Level::Intermediate;
		else ret = Level::Senior;
		return ret;
	};

	//http://www.vishalchovatiya.com/learn-lambda-function-in-cpp-with-example/
	//http://www.vishalchovatiya.com/learn-lambda-function-in-cpp-with-example/#Passing_Lambda_as_Parameter
	vector<Player*> seniorPlayers = SelectSeniorPlayers(selectLevel, players);
	cout << "List of Senior Players:" << endl;
	for(int i=0; i<seniorPlayers.size(); ++i) seniorPlayers[i]->DisplayInfo();

	while (!players.empty()) {
		delete players.back();
		players.pop_back();
	}

	return 0;
}