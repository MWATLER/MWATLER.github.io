/*
 * Author: Daniel Pliszka
 * Contact: dpliszka@myseneca.ca
 * Title: DPS912 Lab 01
 * Date: July 10, 2020
 *
 */

#include <string>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main()
{
	// Scan every directory in /proc that represents a process
    std::string path = "/proc";
    for (const auto & entry : std::filesystem::directory_iterator(path)) // TODO: Only scan through dir starting with a number
    {
    	std::cout << entry.path() << std::endl;
    }


    // TODO: Open the file status

    // TODO: If VmRSS is greater than 10000 kB, then print out the process name, the process id and the memory used.

}
