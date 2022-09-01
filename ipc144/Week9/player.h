//player.h - Structure and function declarations for player information

//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section XXY

//Structure declarations
struct Name {
	char firstName[33];
	char lastName[33];
};

struct PlayerInfo {
	struct Name name;
	char position[17];
	unsigned int goals;
	unsigned int assists;
	unsigned int points;
};

//Function declarations
int GetName(struct Name* name);
int GetPosition(char* pos);
int GetStats(struct PlayerInfo* player);
