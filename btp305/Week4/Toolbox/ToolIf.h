//ToolIf.h - abstract class for our tools

#ifndef _TOOLIF_H_
#define _TOOLIF_H_

#include <iostream>

class ToolIf {
public:
	virtual double GetCost() const = 0;
	virtual void display(std::ostream& os) = 0;
};

ToolIf* CreateTool();

#endif _TOOLIF_H_