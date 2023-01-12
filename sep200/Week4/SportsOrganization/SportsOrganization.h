//SportsOrganization.h - class declaration for a sports organization

#ifndef _SPORTSORGANIZATION_H_
#define _SPORTSORGANIZATION_H_

#include <iostream>

struct Sponsor {
	std::string name;
	double amount;//millions of dollars
};

class SportsOrganization {
	std::string address = "";
	Sponsor* sponsor = nullptr;//a resource
	int numSponsors = 0;
protected:
	std::string name = "";//not good programming practice, better to use GetName()
public:
	SportsOrganization();
	SportsOrganization(std::string name, std::string address);
	//The rule of 5: a custom copy constructor, copy assignment, move constructor, move assignment, destructor
	SportsOrganization(const SportsOrganization& sportsOrg);//copy constructor
	SportsOrganization(SportsOrganization&& sportsOrg) noexcept;//move constructor
	SportsOrganization& operator=(const SportsOrganization& sportsOrg);//copy assignment
	SportsOrganization& operator=(SportsOrganization&& sportsOrg) noexcept;//move assignment
	~SportsOrganization();

	void SetName(std::string name);
	void SetAddress(std::string address);
	void SetSponsors(const Sponsor* sponsorList, int num);
	double GetSponsorWorth() const;
	void display(std::ostream& os) const;
};

#endif// _SPORTSORGANIZATION_H_
