//Passenger.h - data structures and function prototypes for a passenger

#define MAX_STR 64
#define MAX_BAGGAGE 4

struct Ticket {
	//QUESTION 11: What character is used to terminate a string?
	char origin[MAX_STR];
	char destination[MAX_STR];
	double price;//dollars and cents
};

struct Baggage {
	int numberOfPieces;
	double weight[MAX_BAGGAGE];//kg
	double totalWeight;//kg
};

struct Passenger {
	char name[MAX_STR];
	int age;//years
	struct Ticket ticket;
	struct Baggage baggage;
};

int determineTotalWeight(struct Passenger* passenger);
int isOverweight(struct Passenger passenger);
double determineFine(struct Passenger passenger);
void PrintTicket(struct Passenger passenger);