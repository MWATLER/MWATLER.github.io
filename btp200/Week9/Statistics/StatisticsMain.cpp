//StatisticsMain.cpp - main program for statistics

#include <iostream>
#include "Statistics.h"

using namespace std;

int main() {
	Statistics statistics1("data.txt");
	Statistics statistics2("data2.txt");

	cout << "statistics1:" << endl;
	statistics1.loadData();
	statistics1.GetAverage();
	statistics1.GetStandardDeviation();
	statistics1.PrintReport();

	cout << "statistics2:" << endl;
	statistics2.loadData();
	statistics2.GetAverage();
	statistics2.GetStandardDeviation();
	statistics2.PrintReport();

	Statistics statistics3(statistics2);
	cout << "statistics3:" << endl;
	statistics3.loadData();
	statistics3.GetAverage();
	statistics3.GetStandardDeviation();
	statistics3.PrintReport();

	statistics2 = statistics1;
	cout << "statistics2:" << endl;
	statistics2.loadData();
	statistics2.GetAverage();
	statistics2.GetStandardDeviation();
	statistics2.PrintReport();

	return 0;
}