//PicnicBasket.cpp - function definitions for a picnic basket
#include "PicnicBasket.h"

Garnish::Garnish(const std::string& modes, const std::string spices, int num) {
	int modeStartIdx = 0;
	int spiceStartIdx = 0;
	for (int i = 0; i < num; ++i) {
		int modeEndIdx = modes.find_first_of(',', modeStartIdx);
		m_mode.push_back(modes.substr(modeStartIdx, modeEndIdx - modeStartIdx));
		modeStartIdx = modeEndIdx + 1;

		int spiceEndIdx = spices.find_first_of(',', spiceStartIdx);
		m_spices.push_back(spices.substr(spiceStartIdx, spiceEndIdx - spiceStartIdx));
		spiceStartIdx = spiceEndIdx + 1;
	}
}

void Garnish::operator()(std::list<FoodItem>& fItems) {
	auto findGarnishForFoodItem = [](const FoodItem& f) {
		std::string theGarnish;
		int index = 0;
		for (size_t i = 0; i < m_mode.size(); ++i) {
			if (f.mode == m_mode[i]) {
				theGarnish = m_spices[index];
				timesGarnished++;
			}
		}
		for (auto i = m_mode.begin(); i != m_mode.end() && theGarnish.empty(); i++) {
			if (f.mode == *i) {
				theGarnish = m_spices[index];
				timesGarnished++;
			}
			++index;
		}
		return theGarnish;
	};
	std::list<FoodItem>::const_iterator itr;
	for (itr = fItems.begin(); itr != fItems.end(); ++itr) {
		(*itr).additions = findGarnishForFoodItem(*itr);
	}
}

void PicnicBasket::GarnishFood(Garnish garnish) {
	garnish(foodItems);
}

PicnicBasket& PicnicBasket::operator+=(const FoodItem& foodItem) noexcept {
	auto priceCheck = [](const FoodItem& foodItem) {
		const double max = 30.00;
		bool ret = true;
		if (foodItem.price > max) ret = false;
		return ret;
	};

	if (priceCheck(foodItem))
		foodItems.push_back(foodItem);
	else
		throw "Price too high: ";

/*	std::sort(foodItems.begin(), foodItems.end(), [](FoodItem& c1, FoodItem& c2) {
		return c1.name > c2.name;
		});*/
	return *this;
}

void PicnicBasket::display() {
	std::cout << "The contents of the picnic basket" << std::endl;
	for (auto& f : foodItems) {
		std::cout << f.name << ", " << f.additions << ", " << f.price << std::endl;
	}
}
