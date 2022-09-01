//DesignRules2Bad.h - A second set of code to demonstrate design rules

//Miguel Watler
//miguel.watler@senecacollege.ca
//1234567890
//Section: XXY

#ifndef _DESIGN_RULES2_H_
#define _DESIGN_RULES2_H_

#define MAXSTR 256

struct College {
	char name[MAXSTR];
	double tuition;
	double empsat;
};

int CollegeSat(struct College coll[], int size);


#endif //_DESIGN_RULES2_H_
