//SportsMain.cpp - main program for sports organizations

#include "HockeyTeam.h"
#include "BaseballTeam.h"

using namespace std;

int main() {
	HockeyTeam hockey("Toronto Maple Leafs", "Maple Leaf Square, 15 York St, Toronto, ON M5J 0A3", 33, 45, 4);
	const int NUM_SPONSORS = 5;
	Sponsor sponsor[NUM_SPONSORS] = {
		{"Labatt", 5.6 },
		{"Tim Hortons", 11.2},
		{"Kia", 3.3},
		{"Sobeys", 4.8},
		{"The Keg",1.1}
	};
	const int NUM_PLAYERS = 5;
	HockeyPlayer hockeyPlayer[NUM_PLAYERS] = {
		{"Gordie Howe", 34, 43},
		{"Darryl Sittler", 41, 56},
		{"Errol Thompson", 45, 31},
		{"Borje Salming", 15, 45},
		{"Ian Turnbull", 12, 25},
	};
	hockey.SetSponsors(sponsor, NUM_SPONSORS);
	hockey.SetPlayers(hockeyPlayer, NUM_PLAYERS);

	cout << hockey;

	BaseballTeam baseball("Toronto Blue Jays", "Maple Leaf Square, 15 York St, Toronto, ON M5J 0A3", 95, 67);
	BaseballPlayer baseballPlayer[NUM_PLAYERS] = {
		{"Lloyd Moseby", 32, 112},
		{"Roberto Alomar", 41, 122},
		{"Tony Fernandez", 23, 98},
		{"Paul Molitor", 43, 119},
		{"John Olerud", 31, 119},
	};
	baseball.SetSponsors(sponsor, NUM_SPONSORS);
	baseball.SetPlayers(baseballPlayer, NUM_PLAYERS);

	cout << baseball;

	//create a fantasy hockey team
	HockeyTeam fantasyHockey(hockey);

	cout << "COPY CONSTRUCTOR:" << endl;
	cout << fantasyHockey;

	//Move the Blue Jays to Montreal
	BaseballTeam baseball2(std::move(baseball));
	baseball2.SetName("Montreal Expos");
	baseball2.SetAddress("4549 Av Pierre-de Coubert, Montreal, QC, H1V 3N7");

	cout << "MOVE CONSTRUCTOR:" << endl;
	cout << baseball;//baseball is now in an empty state
	cout << baseball2;//baseball2 has all the information from baseball1, with a changed name and address


	return 0;
}