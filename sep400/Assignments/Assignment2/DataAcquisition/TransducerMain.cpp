//TransducerMain.cpp - Main function for the transducer
//
// History:
// 03-May-22  M. Watler         Created.

#include "Transducer.h"

using namespace std;

int main() {
    int retVal=0;
    Transducer transducer;
    retVal = transducer.run();
    return retVal;
}
