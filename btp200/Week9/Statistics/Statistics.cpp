//Statistics.cpp - function definitions for statistics
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include "Statistics.h"

using namespace std;

Statistics::Statistics(const char* filename, unsigned precision) {
	int len = strlen(filename);
	this->filename = new char[len+1];
	strcpy(this->filename, filename);
	this->precision = precision;
}

Statistics::Statistics(const Statistics& other) {
	if (other.filename!=nullptr) {
		int len = strlen(other.filename);
		filename = new char[len+1];
		strcpy(filename, other.filename);
		precision = other.precision;
		loadData();
	}
}

Statistics& Statistics::operator=(const Statistics& rhs) {
	if (this != &rhs && rhs.filename != nullptr) {
		delete[] filename;
		int len = strlen(rhs.filename);
		filename = new char[len+1];
		strcpy(filename, rhs.filename);
		precision = rhs.precision;
		loadData();

	}
	return *this;
}

void Statistics::loadData() {
	if (filename != nullptr) {
		getNumData();
		ifstream file(filename);
		if (data != nullptr) delete[]data;
		data = new double[numData];
		for(int i=0; i<numData; ++i) {
			file >> data[i];
			file.ignore(1000, 'a');
		}
	}
}

void Statistics::getNumData() {
	ifstream file(filename);
	numData = 0;
	while (file) {
		numData += (file.get() == 'a');
	}
	++numData;
}


double Statistics::GetAverage() {
	double runningTotal = 0;
	for (int i = 0; i < numData; ++i) {
		runningTotal += data[i];
	}
	average = runningTotal / numData;
	return average;
}

double Statistics::GetStandardDeviation() {
	GetAverage();
	double sum = 0;
	for (int i = 0; i < numData; ++i) {
		sum += (data[i] - average)*(data[i]-average);//sum += (data[i]-average)^2
	}
	sum /= numData;
	standardDeviation = sqrt(sum);
	return standardDeviation;
}

void Statistics::PrintReport() {
	cout.setf(ios::fixed);
	cout.precision(precision);
	cout << "The average is " << average << endl;
	cout << "The standard deviation is " << standardDeviation << endl <<endl;
	cout.unsetf(ios::fixed);
}

Statistics::~Statistics() {
	if (filename != nullptr) delete[] filename;
	if (data != nullptr) delete[] data;
}
