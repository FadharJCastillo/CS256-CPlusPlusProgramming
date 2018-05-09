/*	Fadhar J. Castillo
CS 256 C++ Programming
PreferredCustomer Class*/

#pragma once
#include "stdafx.h"
#include "PersonData.h"

class CustomerData : public PersonData {
private:
	int _customerNumber;
	bool _mailingList;

public:
	//Constructors
	CustomerData();
	CustomerData(string lastName, string firstName, string address, string city, string state,
		int zip, string phone, int customerNumber, bool mailingList);
	//Accessors
	int getCustomerNumber();
	bool getMailingList();
	//Mutators
	void setCustomerNumber(int cn);
	void setMailingList(bool ml);
};