//StoogeMain.cpp - main program for the three stooges

#include "Stooge.h"
#include "Curly.h"
#include "Moe.h"
#include "Larry.h"

using namespace std;

int main() {
	Larry role1;
	Moe role2;
	Curly role3;

	role1.entertain();
	role2.entertain();
	role3.entertain();

	return 0;
}