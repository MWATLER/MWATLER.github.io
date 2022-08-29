//HomeStereo.cpp - function definitions for a home stereo

#include <iomanip>
#include "HomeStereo.h"

using namespace std;

HomeStereo::HomeStereo(const Switch* theSwitches[], int num) {
	switches = new const Switch* [num];
	for (int i = 0; i < num; ++i) {
		switches[i] = theSwitches[i];
	}
	numSwitches = num;
}

ostream& HomeStereo::displayOutputState(ostream& os){
	for (int i = 0; i < numSwitches; ++i) {
		string state = "off";
		switch (switches[i]->sType) {
		case StateType::boolean:
			if (switches[i]->sState.stateAsBool == true) {
				state = "on";
			}
			break;
		case StateType::character:
			if (switches[i]->sState.stateAsChar== 'O') {
				state = "on";
			}
			break;
		case StateType::number:
			if (switches[i]->sState.stateAsNum == 1) {
				state = "on";
			}
			break;
		}
		os << "Channel Name: " << setw(6) << switches[i]->name << " - State " << setw(3) << state << endl;
	}

	return os;
}
