//ToolMain.cpp - main function for our tool box

#include "Toolbox.h"

using namespace std;

const int NUM_TOOLS = 3;

int main() {
	bool ret;
	Toolbox toolbox("Data Processing Support");
	
	for (int i = 0; i < NUM_TOOLS; ++i) {
		ToolIf* tool = CreateTool();
		ret = toolbox.AddTool(*tool);
		if (!ret) cout << "Unable to add the tool!" << endl;
	}
	//display the tools
	cout << toolbox;
	cout << endl;

	//remove a tool
	cout << "Enter the name of a tool to remove: ";
	string name;
	cin >> name;
	ret = toolbox.RemoveTool(name);
	if (!ret) cout << "Unable to remove the tool!" << endl;
	//display the tools again
	cout << toolbox;

	return 0;
}