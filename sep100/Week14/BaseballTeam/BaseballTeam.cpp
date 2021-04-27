//BaseballTeam.cpp - function definitions of a baseball team

#include "BaseballTeam.h"
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

BaseballTeam::BaseballTeam() {
	name = "";
	wins = 0;
	losses = 0;
	winningPercentage = 0.0;
	for (int i = 0; i < NUM; ++i) {
		player[i].name = "";
		player[i].atBats = 0;
		player[i].hits = 0;
		player[i].battingPercentage = 0.0;
		player[i].battingRank = 1;
		player[i].nameRank = 1;
	}
	dbFileName = "";
}

bool BaseballTeam::SetFileName(std::string dbFileName) {
	bool ret = false;
	if (dbFileName.size() > 0) {
		this->dbFileName = dbFileName;
		ret = true;
	}
	return ret;
}

BaseballTeam::BaseballTeam(std::string dbFileName) {//the database stores all team information
											 //the database fields are separated by a semicolon
	this->dbFileName = dbFileName;
	UtilReadFromFile();
}

bool BaseballTeam::UtilReadFromFile() {
	bool ret = false;
	ifstream file(dbFileName);
	if (file.is_open()) {
		ret = true;
		string data;
		getline(file, name, ';');
		getline(file, data, ';');
		wins = stoi(data);
		getline(file, data, ';');
		losses = stoi(data);
		getline(file, data, ';');
		winningPercentage = stod(data);
		for (int i = 0; i < NUM; ++i) {
			getline(file, player[i].name, ';');
			getline(file, data, ';');
			player[i].atBats = stoi(data);
			getline(file, data, ';');
			player[i].hits = stoi(data);
			getline(file, data, ';');
			player[i].battingPercentage = stod(data);
			getline(file, data, ';');
			player[i].battingRank = stoi(data);
			getline(file, data, ';');
			player[i].nameRank = stoi(data);
		}
		file.close();
	}
	return ret;
}


void BaseballTeam::OrderPlayers() {//by batting percentage and by name
	//initialize
	for (int i = 0; i < NUM; ++i) {
		player[i].battingRank = 1;
		player[i].nameRank = 1;
	}

	for (int i = 0; i < NUM - 1; ++i) {
		for (int j = i+1; j < NUM; ++j) {
			//by batting percentage
			if (player[i].battingPercentage > player[j].battingPercentage) {
				++player[j].battingRank;
			}
			else {
				++player[i].battingRank;
			}
			//by name
			if (player[i].name.compare(player[j].name) < 0) {
				++player[j].nameRank;
			}
			else {
				++player[i].nameRank;
			}
		}
	}
}

bool BaseballTeam::LoadStatsFromFile() {
	return UtilReadFromFile();
}

bool BaseballTeam::UpdateStatsFromKeyboard() {
	bool ret = true;
	char data;
	cout << "Did " << name << " win? [Y,N] ";
	cin >> data;
	if (data == 'y' || data == 'Y') {
		++wins;
	} else if (data == 'n' || data == 'N') {
		++losses;
	}
	else {
		cout << "Invalid entry, exiting..." << endl;
		ret = false;
	}
	if (ret) {
		winningPercentage = (double)wins / (wins + losses);//update winning percentage
		for (int i = 0; i < NUM && ret; ++i) {
			int data1, data2;
			cout << setw(20) << player[i].name << " At bats: ";
			cin >> data1;
			cout << setw(20) << " " << "Hits: ";
			cin >> data2;
			if (data1 < 0 || data2 < 0 || data1 < data2) {
				cout << "Invalid data for " << player[i].name;
				ret = false;
			}
			else {
				player[i].atBats += data1;
				player[i].hits += data2;
				player[i].battingPercentage = (double)player[i].hits / player[i].atBats;//update batting percentage
				cout << "Stats for " << player[i].name << " updated." << endl;
			}
		}
	}
	cout << endl;
	return ret;
}

void BaseballTeam::UtilDisplayHeaderStats(std::string category) const {
	cout.precision(3);
	cout.setf(ios::fixed);
	cout << name << " wins:" << wins << " losses:" << losses << " winning percencage:" << winningPercentage << endl;
	cout << "ROSTER " << category << endl;
}

void BaseballTeam::DisplayStats() const {
	UtilDisplayHeaderStats("");
	cout.setf(ios::left);
	for (int i = 0; i < NUM; ++i) {
		cout << setw(20) << player[i].name << " atBats:" << player[i].atBats << " hits:" << player[i].hits << " batting percentage:" << player[i].battingPercentage << endl;
	}
	cout << endl;
}

void BaseballTeam::DisplayStatsByBattingPercentage() const {
	UtilDisplayHeaderStats("(by batting percentage)");
	for (int rank = 1; rank <= NUM; ++rank) {
		bool found = false;
		for (int i = 0; i < NUM && !found; ++i) {
			if (player[i].battingRank == rank) {
				cout << setw(20) << player[i].name << " atBats:" << player[i].atBats << " hits:" << player[i].hits << " batting percentage:" << player[i].battingPercentage << endl;
				found = true;
			}
		}
	}
	cout << endl;
}

void BaseballTeam::DisplayStatsByName() const {
	UtilDisplayHeaderStats("(by name)");
	for (int rank = 1; rank <= NUM; ++rank) {
		bool found = false;
		for (int i = 0; i < NUM && !found; ++i) {
			if (player[i].nameRank == rank) {
				cout << setw(20) << player[i].name << " atBats:" << player[i].atBats << " hits:" << player[i].hits << " batting percentage:" << player[i].battingPercentage << endl;
				found = true;
			}
		}
	}
	cout << endl;
}

bool BaseballTeam::SaveStatsToFile() {
	bool ret = false;
	ofstream file(dbFileName);
	if (file.is_open()) {
		ret = true;
		file << name << ";" << wins << ";" << losses << ";" << winningPercentage << ";";
		for (int i = 0; i < NUM; ++i) {
			file << player[i].name << ";" << player[i].atBats << ";" << player[i].hits << ";" << player[i].battingPercentage << ";";
			file << player[i].battingRank << ";" << player[i].nameRank << ";";
		}
		file.close();
	}
	return ret;
}

bool BaseballTeam::SaveStatsToFileByBattingPercentage() {
	bool ret = false;
	ofstream file(dbFileName);
	if (file.is_open()) {
		ret = true;
		file << name << ";" << wins << ";" << losses << ";" << winningPercentage << ";";
		for (int rank = 1; rank <= NUM; ++rank) {
			bool found = false;
			for (int i = 0; i < NUM && !found; ++i) {
				if (player[i].battingRank == rank) {
					found = true;
					file << player[i].name << ";" << player[i].atBats << ";" << player[i].hits << ";" << player[i].battingPercentage << ";";
					file << player[i].battingRank << ";" << player[i].nameRank << ";";
				}
			}
		}
		file.close();
	}
	return ret;
}

bool BaseballTeam::SaveStatsToFileByName() {
	bool ret = false;
	ofstream file(dbFileName);
	if (file.is_open()) {
		ret = true;
		file << name << ";" << wins << ";" << losses << ";" << winningPercentage << ";";
		for (int rank = 1; rank <= NUM; ++rank) {
			bool found = false;
			for (int i = 0; i < NUM && !found; ++i) {
				if (player[i].nameRank == rank) {
					found = true;
					file << player[i].name << ";" << player[i].atBats << ";" << player[i].hits << ";" << player[i].battingPercentage << ";";
					file << player[i].battingRank << ";" << player[i].nameRank << ";";
				}
			}
		}
		file.close();
	}
	return ret;
}
