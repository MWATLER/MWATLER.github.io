//PicnicBasket.h - class declarations for a picnic basket

#include <iostream>
#include <vector>
#include <list>

int retVal;

struct FoodItem {
	std::string name;
	std::string additions;
	double price;
	std::string mode;
};

class Garnish {
	std::list<std::string&> m_mode;
	std::vector m_spices;
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
	PicnicBasket& operator+=(const FoodItem& foodItem) noexcept;
	void display();
};
