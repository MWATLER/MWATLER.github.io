//Toolbox.h - class for the tool box

#ifndef _TOOLBOX_H_
#define _TOOLBOX_H_

#include <list>//std::list, a doubly linked list. std::forward_list is a singly linked list.
			   //With a singly linked list you can only push to the front and pop from the front
			   //With a doubly linked list you can push to the front and pop from the front or the back
#include "Hammer.h"
#include "Screwdriver.h"

const int MAX_TOOLS = 4;

class Toolbox {
	std::string name;
	double totalCost;
//	ToolIf* item[MAX_TOOLS];
	std::list<ToolIf*> item;
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
			item.push_back(&tool);//list is a doubly linked list. I could push to the front of the list instead
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
/*		for (int i = 0; i < numItems; ++i) {
			item[i]->display(os);
		}*/
		//I could declare my iterator outside the loop, but it is common practice to take advantage of the "auto" data type and declare the iterator inside the loop
//		std::list<ToolIf*>::iterator it;
//		for (it = item.begin(); it != item.end(); ++it) {
		for (auto it = item.begin(); it != item.end(); ++it) {//"it" takes on the type std::list<ToolIf*>::iterator
				(*it)->display(os);
		}
		os << "The total cost of these items is $" << totalCost << std::endl << std::endl;
	}
	bool RemoveTool(std::string name) {
		int found = false;
		std::list<ToolIf*>::iterator itemIterator;//we cannot directly call erase() from within a for-loop since calling it invalidates the iterator
		                                          //we want to set itemIterator to "it" in the loop, since we want to have access to this iterator after the for-loop has terminated
		for (auto it = item.begin(); it != item.end() && !found; ++it) {
			if ((*it)->GetName() == name) {
				found = true;//We found the pointer to the item we wish to erase, but we must do this outside the for-loop
				itemIterator = it;
			}
		}
		if (found) item.erase(itemIterator);//Erase the pointer to the item here if it has been found
		return found;
	}
};

std::ostream& operator<<(std::ostream& os, Toolbox& toolbox) {
	toolbox.display(os);
	return os;
}

#endif _TOOLBOX_H_
