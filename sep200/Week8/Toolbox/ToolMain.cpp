//ToolMain.cpp - main function for our tool box

#include "Toolbox.h"

using namespace std;

const int NUM_TOOLS = 2;

int main() {
	Toolbox toolbox("Data Processing Support");
	
	for (int i = 0; i < NUM_TOOLS; ++i) {
		ToolIf* tool = CreateTool();
		bool ret = toolbox.AddTool(*tool);
		if (!ret) cout << "Unable to add the tool!" << endl;
	}
	cout << toolbox;

	return 0;
}