//DesignRules2.h - A second set of code to demonstrate design rules

//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section: XXY

#ifndef _DESIGN_RULES2_H_
#define _DESIGN_RULES2_H_

#define MAX_STR 256//Separate words with a _

struct College {
	char name[MAX_STR];
	double tuition;
	double employerSatisfaction;//Choose a variable name that represents what it is
};

int BestDeal(struct College coll[], int size);//Choose a function name that represents what it does


#endif //_DESIGN_RULES2_H_
