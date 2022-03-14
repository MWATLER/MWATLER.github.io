//MapOfWords.cpp - main function for map of words
//See https://thispointer.com/stdmap-tutorial-part-1-usage-detail-with-examples/

#include <iostream>
#include <map>
#include <string>
#include <iterator>
int main()
{
    std::map<std::string, int> mapOfWords;//std::map<key, value> mapOfSomething;
    // Inserting data in std::map
    mapOfWords.insert(std::make_pair("earth", 1));
    mapOfWords.insert(std::make_pair("moon", 2));
    mapOfWords["sun"] = 3;
    // Will replace the value of already added key i.e. earth
    mapOfWords["earth"] = 4;
    // Iterate through all elements in std::map
    std::map<std::string, int>::iterator it = mapOfWords.begin();
    while (it != mapOfWords.end())
    {
        std::cout << it->first << " :: " << it->second << std::endl;//it->first is the key, it->second is the value
        it++;
    }
    // Check if insertion is successful or not
    if (mapOfWords.insert(std::make_pair("earth", 1)).second == false)
    {
        std::cout << "Element with key 'earth' not inserted because it already exists" << std::endl;
    }
    // Searching element in std::map by key.
    if (mapOfWords.find("sun") != mapOfWords.end())
        std::cout << "word 'sun' found" << std::endl;
    if (mapOfWords.find("mars") == mapOfWords.end())
        std::cout << "word 'mars' not found" << std::endl;

    // Get a value given a key
    std::cout << std::endl;
    std::cout << "Enter a key: ";
    std::string key;
    std::cin >> key;
    std::cout << "The value for key \"" << key << "\" is \"" << mapOfWords[key] << "\"." << std::endl;
    return 0;
}