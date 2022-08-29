//PicnicBasket.h - class declarations for a picnic basket

#ifndef _PICNICBASKET_H_//Lacking header guards in PicnicBasket.h leads to redefinition
#define _PICNICBASKET_H_

#include <iostream>
#include <vector>
#include <list>

//int retVal;//redefinition of retVal

struct FoodItem {
	std::string name;
	std::string additions;
	double price;
	std::string mode;
};

class Garnish {
//	std::list<std::string&> m_mode;//Can not have containers of references
	std::list<std::string> m_mode;
//	std::vector m_spices;//Lacks templated param for vector
	std::vector<std::string> m_spices;
	static int timesGarnished;
public:
	Garnish(const std::string& modes, const std::string spices, int num);
	void operator()(std::list<FoodItem>& fItems);
	static int GarnishCount() {
		return timesGarnished;
	}
};

class PicnicBasket {
	std::list<FoodItem> foodItems;
public:
	void GarnishFood(Garnish g);
//	PicnicBasket& operator+=(const FoodItem& foodItem) noexcept;//+= operator throws an exception but noexcept is applied here
	PicnicBasket& operator+=(const FoodItem& foodItem);
	void display();
};

#endif// _PICNICBASKET_H_
