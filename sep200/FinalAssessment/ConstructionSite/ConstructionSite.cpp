//ConstructionSite.cpp - code for a construction site

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <numeric>
using namespace std;

enum class workerType {
    electrician, plumber, carpenter
};

struct ConstructionSite {
    string siteName;
    workerType worker;
    bool available;
    double cost;
};

std::vector<ConstructionSite> informationUpdates(std::list<ConstructionSite> site) {


    // Task 1 - go through all construction sites and determine the total cost of the electricians and plumbers using STL an algorithm. 
    //          Name your variable "cost"
    {

        cout << "The total cost of the electricians and plumbers are: $" << cost << endl;
    }
    // Task 2 - go through all construction sites and determine the number of non-available construction sites using an STL algorithm. 
    //          Name your variable "nonavail"
    {

        cout << "The number of non-available Construction sites are: " << nonavail << endl;
    }

    // Task 3 - go through all constructions sites and make the following change: if the construction site is not available and the worker is
    //          a plumber or an electrician, add $50 to the cost and make the construction site available. Do this using an STL algorithm
    {

    }
    std::vector<ConstructionSite> ret;

    // Task 4 - go through all construction sites and push all sites with electricians or carpenters into the variable "ret" using an STL algorithm.
    {

    }

    //Task 5 - go through the vector "ret" and remove all construction sites which are not available. Be sure to resize "ret"
    {

    }

    return ret;
}


int main() {
    std::list<ConstructionSite> construction({
        { "House", workerType::carpenter, true, 130.85 },
        { "Building", workerType::plumber, false, 99.89 },
        { "Bungalow", workerType::carpenter, false, 189.55 },
        { "TownHouse", workerType::carpenter, true, 125.65 },
        { "StackHouse", workerType::plumber, true, 90.78 },
        { "CaveHouse", workerType::electrician, true, 223.35 },
        { "Castle", workerType::electrician, false, 500.00 },
        });

    // The resulting selected seats
    auto sites = informationUpdates(construction);

    void(*selectionFunc[3])() = {
      []() { cout << "Electrician"; },
      []() { cout << "Plumber"; },
      []() { cout << "Carpenter"; }
    };

    cout << "\nUpdated Information on Construction Sites" << endl;
    for (auto& x : sites) {
        cout << x.siteName << " | ";
        selectionFunc[(int)x.worker]();
        cout << " | " << x.available << " | " << x.cost << endl;
    }

    return 0;
}
