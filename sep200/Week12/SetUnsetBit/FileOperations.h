//FileOperations.h - class declaration for file operations

#ifndef _FILEOPERATIONS_H_
#define _FILEOPERATIONS_H_

#include <iostream>
#include <fstream>
#include <string>

const unsigned short READ = 0x04;//00000100
const unsigned short WRITE = 0x02;//00000010
const unsigned short ACCESS = 0x01;//00000001
const unsigned short NONE = 0x00; //00000000

class FileOperations {
	std::ifstream ifile;
	std::ofstream ofile;
	unsigned short flags;//0000 0111 - read, write and access
public:
	FileOperations() {
		ifile.close();
		ofile.close();
		flags = NONE;
	}
	bool Open(std::string name) {
		bool ret = true;
		if (flags & ACCESS) {
			ifile.open(name);
			ofile.open(name);
			if (!ifile.is_open() || !ofile.is_open()) {
				if (ifile.is_open()) ifile.close();
				if (ofile.is_open()) ofile.close();
				ret = false;
			}
		}
		else {
			ret = false;
		}
		return ret;
	}
	bool Write(std::string msg) {
		bool ret = true;
		if ((flags & WRITE) && ofile.is_open()) {
			ofile << msg << std::endl;
		}
		else {
			ret = false;
		}
		return ret;
	}
	bool Read(std::string& msg) {
		bool ret = true;
		if ((flags & READ) && ifile.is_open()) {
			std::getline(ifile, msg);
		}
		else {
			ret = false;
		}
		return ret;
	}
	void Close() {
		ifile.close();
		ofile.close();
	}
	void SetFlags(unsigned short _flags) {
		flags = flags | _flags;
	}
	void UnsetFlags(unsigned short _flags) {
		flags = flags & ~_flags;
	}//0000 0101 - read, access
};


#endif// _FILEOPERATIONS_H_
