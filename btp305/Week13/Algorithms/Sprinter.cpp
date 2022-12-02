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
		//http://www.cplusplus.com/reference/algorithm/for_each/
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
		//http://www.cplusplus.com/reference/algorithm/transform/
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
		//http://www.cplusplus.com/reference/algorithm/sort/
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
			cout << sp.name << " " << sp.age << " years old from " << sp.country;
			cout << " 100m: " << sp.time100 << "s 200m: " << sp.time200 << "s." << endl;
			});
	}

	//Task 10 - calculate the average 100m time
	{
		//https://www.cplusplus.com/reference/numeric/accumulate/
		auto sum = accumulate(sprinter.begin(), sprinter.end(), 0.0, [](double& sum, const Sprinter sp) {
			return sum += sp.time100;
			});
		if (sprinter.size() > 0) {
			cout << endl << "Average 100m time is " << sum / sprinter.size() << " seconds" << endl;
		}
		else {
			cout << endl << "Average 100m time is NaN." << endl;
		}
	}

	//Task 11 - calculate the average 200m time
	{
		//Why don't we get a variable redefinition error for sum?
		auto sum = accumulate(sprinter.begin(), sprinter.end(), 0.0, [](double& sum, const Sprinter sp) {
			return sum += sp.time200;
			});
		if (sprinter.size() > 0) {
			cout << endl << "Average 200m time is " << sum / sprinter.size() << " seconds" << endl;
		}
		else {
			cout << endl << "Average 200m time is NaN." << endl;
		}
	}

	//Task 12 - are any sprinters from outside North America? Print "yes" if true, "no" if false
	{
		//http://www.cplusplus.com/reference/algorithm/all_of/
		auto insideNA = all_of(sprinter.begin(), sprinter.end(), [](const Sprinter& sp) {
			return sp.country == "USA (North America)" || sp.country == "Jamaica (North America)" || sp.country == "Canada (North America)";
			});
		cout << endl << "Are there any sprinters from outside North America? " << (insideNA ? "no" : "yes") << endl;
	}

	//Task 13 - find the first sprinter in the vector that ran the 200m in over 21 seconds
	{
		//http://www.cplusplus.com/reference/algorithm/find_if/
		vector<Sprinter>::iterator sp21 = find_if(sprinter.begin(), sprinter.end(), [](const Sprinter& sp) {
			return sp.time200 > 21.00;
			});
		cout << endl << "THE FIRST SPRINTER IN THE VECTOR THAT RAN THE 200M IN OVER 21 SECONDS" << endl;
		cout << sp21->name << " " << sp21->age << " years old from " << sp21->country << " " << sp21->time200 << "s" << endl;
	}
	
	//Task 14 - remove any sprinters from the Soviet Union and return the new list of sprinters
	//http://www.cplusplus.com/reference/forward_list/
	forward_list<Sprinter> ret;
	{
		//The lambda returns true if the sprinter is not from the Soviet Union
		auto isNotSovietUnion = [](const Sprinter& sp) {
			return(sp.country != "Soviet Union (non-North America)");
		};
		//http://www.cplusplus.com/reference/algorithm/count_if/
		auto cnt = count_if(sprinter.begin(), sprinter.end(), isNotSovietUnion);
		forward_list<Sprinter> tmp(cnt);
		//http://www.cplusplus.com/reference/algorithm/copy_if/
		copy_if(sprinter.begin(), sprinter.end(), tmp.begin(), isNotSovietUnion);
		//ret contains all sprinters not from the Soviet Union
		ret = tmp;
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

	auto isYoung = [](const Sprinter& s)->bool {
		bool ret = false;
		if (s.age < 25 || s.country == "Jamaica") {
			ret = true;
		}
		return true;
	};

	int count = 0;
	auto total = std::accumulate(res.begin(), res.end(), 0.0, [&](double& sum, const Sprinter& s) {
		if (isYoung(s)) {
			sum += s.time100;
			++count;
		}
		return sum;
		});

	if (count > 0) {
		cout << endl << "The average 100m time for young sprinters is " << total / count << " seconds." << endl;
	}
	else {
		cout << endl << "There are no young sprinters." << endl;
	}

	return 0;
}