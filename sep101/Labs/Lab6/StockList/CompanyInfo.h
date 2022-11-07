//CompanyInfo.h - company information

#ifndef _COMPANYINFO_H_
#define _COMPANYINFO_H_

#define SIZE 128
struct CompanyInfo {
	char name[SIZE];
	char symbol[SIZE];
	double price;
	int volume;
};


#endif//_COMPANYINFO_H_