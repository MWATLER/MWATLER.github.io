//Toolbox.h - class for the tool box

#ifndef _TOOLBOX_H_
#define _TOOLBOX_H_

#include <vector>//std::vector
#include "Hammer.h"
#include "Screwdriver.h"

const int MAX_TOOLS = 4;

class Toolbox {
	std::string name;
	double totalCost;
//	ToolIf* item[MAX_TOOLS];
	std::vector<ToolIf*> item;
	int numItems;
public:
	Toolbox(std::string name) {
		this->name = name;
		numItems = 0;
		totalCost = 0.0;
	}
	bool AddTool(ToolIf& tool) {
		int ret = true;
		if (numItems < MAX_TOOLS) {
//			item[numItems] = &tool;
			item.push_back(&tool);
			++numItems;
			totalCost += tool.GetCost();
		}
		else {
			ret = false;
		}
		return ret;
	}
	void display(std::ostream& os) {
		os.setf(std::ios::fixed);
		os.precision(2);
		os << std::endl;
		os << name << " is a toolbox with the following items:" << std::endl;
		for (int i = 0; i < numItems; ++i) {//one can treat a vector similar to an array
			item[i]->display(os);
		}
		os << "The total cost of these items is $" << totalCost << std::endl << std::endl;
	}
};

std::ostream& operator<<(std::ostream& os, Toolbox& toolbox) {
	toolbox.display(os);
	return os;
}

#endif _TOOLBOX_H_
