/*	Fadhar J. Castillo
CS 256 C++ Programming
PreferredCustomer Class*/

#pragma once
#include "stdafx.h"
#include "CustomerData.h"

class PreferredCustomer : public CustomerData
{
private:
	double _purchasesAmount;
	double _discountLevel;
public:
	//Constructors
	PreferredCustomer();
	PreferredCustomer(string lastName, string firstName, string address, string city, string state,
		int zip, string phone, int customerNumber, bool mailingList, double purchaseAmount);
	
	//Accesors
	double getPurchasesAmount();
	double getDiscountLevel();
	//Mutators
	void setPurchasesAmount(double purchaseAmount);
	void setDiscountLevel();
};