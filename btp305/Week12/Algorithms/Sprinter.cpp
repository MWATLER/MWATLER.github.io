//Sprinter.cpp - main function for the sprinter, to exercise the knowledge of STL algorithms

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

std::forward_list<Sprinter> processSprinters(vector<Sprinter> sprinter) {
    //Task 1 - print out all North American sprinters
	{
		cout << endl << "ALL NORTH AMERICAN SPRINTERS:" << endl;
		for_each(sprinter.begin(), sprinter.end(), [](const Sprinter& sp) {
			if (sp.country == "USA" || sp.country == "Jamaica" || sp.country == "Canada") {
				cout << sp.name << " " << sp.age << " years old from " << sp.country << endl;
			}
			});
	}

	//Task 2 - print out all non-North American sprinters
	{
		cout << endl << "ALL NON-NORTH AMERICAN SPRINTERS:" << endl;
		for_each(sprinter.begin(), sprinter.end(), [](const Sprinter& sp) {
			if (sp.country != "USA" && sp.country != "Jamaica" && sp.country != "Canada") {
				cout << sp.name << " " << sp.age << " years old from " << sp.country << endl;
			}
			});
	}

	//Task 3 - append " (North America)" to the country of all North American sprinters
	{
		transform(sprinter.begin(), sprinter.end(), sprinter.begin(), [](Sprinter& sp)
			{
				if (sp.country == "USA" || sp.country == "Jamaica" || sp.country == "Canada") {
					sp.country += " (North America)";
				}
				return sp;
			});
		cout << endl << "APPEND NORTH AMERICA:" << endl;
		for_each(sprinter.begin(), sprinter.end(), [](const Sprinter& sp) {
			cout << sp.name << " " << sp.age << " years old from " << sp.country << endl;
			});
	}

	//Task 4 - append "non-North America" to the country of all non-North American sprinters
	{
		transform(sprinter.begin(), sprinter.end(), sprinter.begin(), [](Sprinter& sp)
			{
				if (sp.country != "USA (North America)" && sp.country != "Jamaica (North America)" && sp.country != "Canada (North America)") {
					sp.country += " (non-North America)";
				}
				return sp;
			});
		cout << endl << "APPEND NON-NORTH AMERICA:" << endl;
		for_each(sprinter.begin(), sprinter.end(), [](const Sprinter& sp) {
			cout << sp.name << " " << sp.age << " years old from " << sp.country << endl;
			});
	}

	//Task 5 - print out all sprinters with 100m below 10s
	{
		cout << endl << "TIME BELOW 10s (100M):" << endl;
		for_each(sprinter.begin(), sprinter.end(), [](const Sprinter& sp) {
			if (sp.time100 < 10.0) {
				cout << sp.name << " " << sp.age << " years old from " << sp.country << " " << sp.time100 << "s." << endl;
			}
			});
	}

	//Task 6 - print out all sprinters with 200m below 20s
	{
		cout << endl << "TIME BELOW 20s (200M):" << endl;
		for_each(sprinter.begin(), sprinter.end(), [](const Sprinter& sp) {
			if (sp.time200 < 20.0) {
				cout << sp.name << " " << sp.age << " years old from " << sp.country << " " << sp.time200 << "s." << endl;
			}
			});
	}

	//Task 7 - sort sprinters according to their 100m
	{
		sort(sprinter.begin(), sprinter.end(), [](const Sprinter& a, const Sprinter& b) {
			return a.time100 < b.time100;
			});
		cout << endl << "SORT BY 100m:" << endl;
		for_each(sprinter.begin(), sprinter.end(), [](const Sprinter& sp) {
			cout << sp.name << " " << sp.age << " years old from " << sp.country << " " << sp.time100 << "s." << endl;
			});
	}

	//Task 8 - sort sprinters according to their 200m
	{
		sort(sprinter.begin(), sprinter.end(), [](const Sprinter& a, const Sprinter& b) {
			return a.time200 < b.time200;
			});
		cout << endl << "SORT BY 200m:" << endl;
		for_each(sprinter.begin(), sprinter.end(), [](const Sprinter& sp) {
			cout << sp.name << " " << sp.age << " years old from " << sp.country << " " << sp.time200 << "s." << endl;
			});
	}

	//Task 9 - sort sprinters according to their age
	{
		sort(sprinter.begin(), sprinter.end(), [](const Sprinter& a, const Sprinter& b) {
			return a.age > b.age;
			});
		cout << endl << "SORT BY age:" << endl;
		for_each(sprinter.begin(), sprinter.end(), [](const Sprinter& sp) {
			cout << sp.name << " " << sp.age << " years old from " << sp.country << endl;
			});
	}

	//Task 10 - calculate the average 100m time
	{
		auto sum = accumulate(sprinter.begin(), sprinter.end(), 0.0, [](double& sum, const Sprinter sp) {
			return sum += sp.time100;
			});
		if (sprinter.size() > 0) {
			cout << endl << "Average 100ms time is " << sum / sprinter.size() << " seconds" << endl;
		}
		else {
			cout << endl << "Average 100ms time is NaN." << endl;
		}
	}

	//Task 11 - calculate the average 200m time
	{
		auto sum = accumulate(sprinter.begin(), sprinter.end(), 0.0, [](double& sum, const Sprinter sp) {
			return sum += sp.time200;
			});
		if (sprinter.size() > 0) {
			cout << endl << "Average 200ms time is " << sum / sprinter.size() << " seconds" << endl;
		}
		else {
			cout << endl << "Average 200ms time is NaN." << endl;
		}
	}

	//Task 12 - are any sprinters from outside North America? Print "yes" if true, "no" if false
	{
		auto insideNA = all_of(sprinter.begin(), sprinter.end(), [](const Sprinter& sp) {
			return sp.country == "USA (North America)" || sp.country == "Jamaica (North America)" || sp.country == "Canada (North America)";
			});
		cout << endl << "Are there any sprinters from outside North America? " << (insideNA ? "no" : "yes") << endl;
	}

	//Task 13 - remove any sprinters from the Soviet Union and print the new list of sprinters
	forward_list<Sprinter> ret;
	{
		auto isNotSovietUnion = [](const Sprinter& sp) {
			return(sp.country != "Soviet Union (non-North America)");
		};
		auto cnt = count_if(sprinter.begin(), sprinter.end(), isNotSovietUnion);
		forward_list<Sprinter> tmp(cnt);
		copy_if(sprinter.begin(), sprinter.end(), tmp.begin(), isNotSovietUnion);
		ret = tmp;
	}

	//Task 14 - find any sprinters that ran the 200m in over 21 seconds
	{
		vector<Sprinter>::iterator sp21 = find_if(sprinter.begin(), sprinter.end(), [](const Sprinter& sp) {
			return sp.time200 > 21.00;
			});
		int count = count_if(sprinter.begin(), sprinter.end(), [](const Sprinter& sp) {
			return sp.time200 > 21.00;
			});
		cout << endl << "SPRINTERS THAT RAN THE 200M IN OVER 21 SECONDS" << endl;
		for_each(sp21, sp21+count, [](const Sprinter& sp) {
			cout << sp.name << " " << sp.age << " years old from " << sp.country << " " << sp.time200 << "s" << endl;
			});

	}

	return ret;
}

int main() {
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

	return 0;
}