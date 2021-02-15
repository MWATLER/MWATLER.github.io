//TextBook.cpp - function definitions for a text book
//
// 15-Feb-21  M. Watler         Created.
#include <iostream>
#include <fstream>
#include <string>//std::getline()
#include "TextBook.h"

using namespace std;

TextBook::TextBook(std::string title) {
	this->title = title;
}

void TextBook::ImportBookByString(std::string filename) {
    ifstream fin(filename);
	if (fin.is_open()) {
		while (fin) {
			string line;
			fin >> line;
			content += line;
		}
	}

}


void TextBook::ImportBookByLine(std::string filename) {
	ifstream fin(filename);
	if (fin.is_open()) {
		while (fin) {
			string line;
			getline(fin, line);
			content += line+'\n';
		}
	}
}

void TextBook::ExportBook(std::string filename) const {
	ofstream fout(filename);
	if (fout.is_open()) {
		fout << content << endl;
	}
}

void TextBook::DisplayBook() const {
	cout << content << endl;
}
