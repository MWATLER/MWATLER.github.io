//PicnicMain.cpp - main function for the picnic basket

#include <iostream>
#include <string>
#include <thread>
#include <memory>
#include "PicnicBasket.h"

void processFoodItem(PicnicBasket& p, Garnish g) {
    p.GarnishFood(g);
}

//int retVal = 0;//move retVal to main() where it is used

int main() {
    int retVal = 0;
    FoodItem foodItems[]{
    {"Sandwich", "", 8.99, "Spicy" },
    {"Lemon Pie", "", 12.99, "Sweet" },
    {"Coca-Cola", "", 3.99, "None" },
    {"Chicken", "", 11.99, "Salty" },
    {"Turkey", "", 40.00, "Salty" },
    {"Potato Salad", "", 15.99, "Spicy" },
    {"Cole Slaw", "", 5.99, "None" },
    };

//  std::shared_ptr<PicnicBasket> pBasket = new PicnicBasket();//Smart pointer constructor is explicit
    std::shared_ptr<PicnicBasket> pBasket(new PicnicBasket());
//  std::unique_ptr<PicnicBasket> pBasket2 = pBasket;//Copy semantics are deleted for unique_ptr
    try {
        ((*pBasket += foodItems[0]) += foodItems[1]);
    }
//  catch (int& msg) {//There is no catch case for the throw in the += operator which throws a std::string
    catch (std::string& msg) {
        std::cout << msg << std::endl;
        retVal = -1;
    }

    Garnish g("Spicy,Sweet,Salty,None", { "Pepper,Sugar,Salt," }, 4);

    std::thread t1;
//  t1.join();//Calling join on a nonjoinable thread
//  t1 = std::thread(processFoodItem, *pBasket, g);//processFoodItem expects an Rvalue but pBasket is passed as an Lvalue
    t1 = std::thread(processFoodItem, std::ref(*pBasket), g);
    t1.join();//Lack of join on threads
    pBasket->display();
    int rc = g.GarnishCount();
    std::cout << "Garnished #" << rc << " food items." << std::endl;

//  delete pBasket;//Do not delete a smart pointer
    return retVal;
}