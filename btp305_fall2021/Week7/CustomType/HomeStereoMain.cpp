//HomeStereoMain.cpp - main function for home stereo

#include "HomeStereo.h"

using namespace std;

int main() {
    const int NUM = 3;
    Switch switch1;
    Switch switch2;
    Switch switch3;

    strcpy_s(switch1.name, 20, "Switch 1");
    switch1.sState.stateAsBool = true;
    switch1.sType = StateType::boolean;
    strcpy_s(switch2.name, 20, "Switch 2");
    switch2.sState.stateAsChar = 'O';
    switch2.sType = StateType::character;
    strcpy_s(switch3.name, 20, "Switch 3");
    switch3.sState.stateAsNum = 0;
    switch3.sType = StateType::number;

    const Switch* switches[NUM];
    switches[0] = &switch1;
    switches[1] = &switch2;
    switches[2] = &switch3;

    HomeStereo hs(switches, NUM);
    hs.displayOutputState(cout);

    return 0;
}
