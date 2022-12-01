//Sprinter.cpp - main function for the sprinter, to exercise the knowledge of STL algorithms
//Documentation for STL algorithms can be found at: http://www.cplusplus.com/reference/algorithm/
//and https://www.cplusplus.com/reference/numeric/
//Documentation for STL containters can be fount at: http://www.cplusplus.com/reference/stl/
#include <algorithm>
#include <iostream>
#include <forward_list>
#include <numeric>//accumulate
#include <vector>
using namespace std;

struct Sprinter {
	std::string name;
	std::string country;
	int age;
	double time100;//100m time
	double time200;//200m time
	int year;
};
/*vector<Sprinter> sprinter({
	{"Eddie Tolan", "USA", 29, 10.30, 21.20, 1932},
	{"Jesse Owens", "USA", 26, 10.30, 20.70, 1936},
	{"Percy Williams", "Canada", 30, 10.80, 21.80, 1928},
	{"Bobby Joe Morrow", "USA", 21, 10.50, 20.60, 1956},
	{"Valery Borzov", "Soviet Union", 32, 10.14, 20.00, 1972},
	{"Ralph Craig", "USA", 25, 10.80, 21.70, 1912},
	{"Carl Lewis", "USA", 27, 9.99, 19.80, 1984},
	{"Archie Hahn", "USA", 22, 11.00, 21.60, 1904},
	{"Usain Bolt", "Jamaica", 24, 9.69, 19.30, 2008}
	});*/
std::forward_list<Sprinter> processSprinters(vector<Sprinter> sprinter) {
	//Task 1 - print out all North American sprinters
	{
		cout << endl << "ALL NORTH AMERICAN SPRINTERS:" << endl;

	}

	//Task 2 - print out all non-North American sprinters
	{
		cout << endl << "ALL NON-NORTH AMERICAN SPRINTERS:" << endl;

	}

	//Task 3 - append " (North America)" to the country of all North American sprinters and print them out
	{
		cout << endl << "APPEND NORTH AMERICA:" << endl;
		//http://www.cplusplus.com/reference/algorithm/transform/

	}

	//Task 4 - append "non-North America" to the country of all non-North American sprinters and print them out
	{
		cout << endl << "APPEND NON-NORTH AMERICA:" << endl;

	}

	//Task 5 - print out all sprinters with 100m below 10s
	{
		cout << endl << "TIME BELOW 10s (100M):" << endl;

	}

	//Task 6 - print out all sprinters with 200m below 20s
	{
		cout << endl << "TIME BELOW 20s (200M):" << endl;

	}

	//Task 7 - print out the sprinters sorted according to their 100m
	{
		cout << endl << "SORT BY 100m:" << endl;
		//http://www.cplusplus.com/reference/algorithm/sort/

	}

	//Task 8 - print out the sprinters sorted according to their 200m
	{
		cout << endl << "SORT BY 200m:" << endl;

	}

	//Task 9 - print out the sprinters sorted according to their age
	{
		cout << endl << "SORT BY age:" << endl;

	}

	//Task 10 - calculate the average 100m time and print it out
	{
		//https://www.cplusplus.com/reference/numeric/accumulate/
		cout << endl << "Average 100m time is ";

	}

	//Task 11 - calculate the average 200m time and print it out
	{
		cout << endl << "Average 200m time is ";

	}

	//Task 12 - are any sprinters from outside North America? Print "yes" if true, "no" if false
	{
		//http://www.cplusplus.com/reference/algorithm/all_of/
		cout << endl << "Are there any sprinters from outside North America? ";

	}

	//Task 13 - find the first sprinter in the vector that ran the 200m in over 21 seconds
	{
		//http://www.cplusplus.com/reference/algorithm/find_if/
		cout << endl << "THE FIRST SPRINTER IN THE VECTOR THAT RAN THE 200M IN OVER 21 SECONDS" << endl;

	}

	//Task 14 - remove any sprinters from the Soviet Union and return the new list of sprinters
	//http://www.cplusplus.com/reference/forward_list/
	forward_list<Sprinter> ret;
	{

	}


	return ret;
}

int main() {
	/*	struct Sprinter {
			std::string name;
			std::string country;
			int age;
			double time100;//100m time
			double time200;//200m time
			int year;
		};*/
		//Sprinters who set world records in both the 100m and 200m in the same year
	vector<Sprinter> sprinter({
		{"Eddie Tolan", "USA", 29, 10.30, 21.20, 1932},
		{"Jesse Owens", "USA", 26, 10.30, 20.70, 1936},
		{"Percy Williams", "Canada", 30, 10.80, 21.80, 1928},
		{"Bobby Joe Morrow", "USA", 21, 10.50, 20.60, 1956},
		{"Valery Borzov", "Soviet Union", 32, 10.14, 20.00, 1972},
		{"Ralph Craig", "USA", 25, 10.80, 21.70, 1912},
		{"Carl Lewis", "USA", 27, 9.99, 19.80, 1984},
		{"Archie Hahn", "USA", 22, 11.00, 21.60, 1904},
		{"Usain Bolt", "Jamaica", 24, 9.69, 19.30, 2008}
		});

	cout << endl << "MAIN LIST OF SPRINTERS:" << endl;
	for_each(sprinter.begin(), sprinter.end(), [](const Sprinter& sp) {
		cout << sp.name << " " << sp.age << " years old from " << sp.country << endl;
		});
	auto res = processSprinters(sprinter);
	cout << endl << "MAIN LIST OF PROCESSED SPRINTERS:" << endl;
	for_each(res.begin(), res.end(), [](const Sprinter& sp) {
		cout << sp.name << " " << sp.age << " years old from " << sp.country << endl;
		});

	//Create a lambda function isYoung that returns true if a sprinter is under 25 years old or is from Jamaica



	//Use an STL algorithm to calculate the average 100m time for young sprinters only


	//Print out the average 100m time for young sprinters
	//If there are no young sprinters, then printout "There are no young sprinters."

	return 0;
}