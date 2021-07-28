#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
const int NAME_LEN = 32;

class Athlete {
    unsigned int age; char name[NAME_LEN + 1];
public:
    Athlete() { name[0] = '\0'; };
    Athlete(const char*, unsigned int);
};

class SoccerPlayer : public Athlete {
    int age_limit; char* address;
public:
    SoccerPlayer() { age_limit = 0; address = nullptr; };
    ~SoccerPlayer();
    SoccerPlayer(const char*, int, unsigned int, const char*);
    SoccerPlayer(const SoccerPlayer&);
    void display();
};

Athlete::Athlete(const char* name_, unsigned int _age) {
    strncpy(name, name_, NAME_LEN);
    name[NAME_LEN] = '\0';
    age = _age;
}

SoccerPlayer::~SoccerPlayer() {}

SoccerPlayer::SoccerPlayer(const SoccerPlayer& obj) : Athlete(obj.name, obj.age) {
    if (obj.address == nullptr || obj.age_limit <= 0) {
        address = nullptr;
    }
    else {
        age_limit = obj.age_limit;
        int len = strlen(obj.address);
        address = new char[len + 1];
        strcpy(address, obj.address);
    }

}

SoccerPlayer::SoccerPlayer(const char* address_, int limit, unsigned int _age, const char* name) : Athlete(name, _age) {
    if (limit > 0 && address != nullptr) {
        age_limit = limit;
        int len = strlen(address);
        address = new char[len + 1];
        strcpy(address, address_);
    }
    else {
        address = nullptr;
        *this = SoccerPlayer();
    }
}

void SoccerPlayer::display() {
    cout << name << " " << age << " years, lives at " << address << endl;
}

int main() {
    string address = "34 Brentwood Terrace, Jamaica, WI";
    char name[NAME_LEN + 1] = "Rodriquez";
    unsigned int age = 32;
    int age_limit = 35;
    char* adrs = new char[address.length() + 1];
    strcpy(adrs, address.c_str());
    SoccerPlayer player1(adrs, age_limit, age, name);
    SoccerPlayer player2(player1);
    player1.display();
    player2.display();
    return 0;
}



















/* ANSWER */
/* name and age in Athlete need to be public. */
/* For the default constructor for Athlete, age should be initialized. */
/* address should be deleted in the destructor for SoccerPlayer. */
/* In the four parameter constructor for SoccerPlayer, the variable address is used in some places instead of address_. */