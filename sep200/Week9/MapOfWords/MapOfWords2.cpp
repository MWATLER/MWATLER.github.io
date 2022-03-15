//MapOfWords2.cpp - another main function for map of words
//See https://thispointer.com/stdmap-tutorial-part-1-usage-detail-with-examples/

#include <iostream>
#include <map>
#include <string>
#include <iterator>
std::map<std::string, int>::iterator searchByValue(std::map<std::string, int>& mapOfWords, int val)
{
    // Iterate through all elements in std::map and search for the passed element
    bool found = false;
    std::map<std::string, int>::iterator it = mapOfWords.begin();
    while (it != mapOfWords.end() && !found)
    {
        if (it->second == val) found = true;//look for the element that has a value of val (in this case 3)
        else it++;
    }
    return it;
}
int main()
{
    std::map<std::string, int> mapOfWords;
    // Inserting data in std::map
    mapOfWords.insert(std::make_pair("earth", 1));
    mapOfWords.insert(std::make_pair("moon", 2));
    mapOfWords["sun"] = 3;
    std::map<std::string, int>::iterator it = searchByValue(mapOfWords, 4);
	if (it != mapOfWords.end())
		std::cout << it->first << " :: " << it->second << std::endl;
	else
		std::cout << "no such element in our map." << std::endl;
    return 0;
}