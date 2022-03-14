//MapOfWords3.cpp - a third main function for map of words
//See https://thispointer.com/stdmap-tutorial-part-1-usage-detail-with-examples/

//Erase by iterator: void erase(iterator position);
//Erase by key:      size_type erase(const key_type& k);
//Erase by range:    void erase(iterator first, iterator last);

#include <iostream>
#include <map>
#include <string>
#include <iterator>
int main()
{
    std::map<std::string, int> mapOfWords;
    mapOfWords.insert(std::make_pair("earth", 1));
    mapOfWords.insert(std::make_pair("moon", 2));
    mapOfWords["sun"] = 3;
    //print out the map
    std::map<std::string, int>::iterator it = mapOfWords.begin();
    while (it != mapOfWords.end())
    {
        std::cout << it->first << " :: " << it->second << std::endl;
        it++;
    }
    std::cout << std::endl;

    // Erasing By iterator
    it = mapOfWords.find("moon");
    mapOfWords.erase(it);
    //print out the map
    it = mapOfWords.begin();
    while (it != mapOfWords.end())
    {
        std::cout << it->first << " :: " << it->second << std::endl;
        it++;
    }
    std::cout << std::endl;

    // Erasing By Key
    mapOfWords.erase("earth");
    //print out the map
    it = mapOfWords.begin();
    while (it != mapOfWords.end())
    {
        std::cout << it->first << " :: " << it->second << std::endl;
        it++;
    }
    return 0;
}