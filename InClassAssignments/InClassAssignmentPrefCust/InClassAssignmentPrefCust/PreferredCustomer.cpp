/*	Fadhar J. Castillo
CS 256 C++ Programming
PreferredCustomer Class*/

#include "stdafx.h"
#include "PreferredCustomer.h"
PreferredCustomer::PreferredCustomer() : CustomerData(), _purchasesAmount(0.0) { setDiscountLevel(); }
PreferredCustomer::PreferredCustomer(string lastName, string firstName, string address, string city, string state,
	int zip, string phone, int customerNumber, bool mailingList, double purchaseAmount)
	: CustomerData(lastName, firstName, address, city, state, zip, phone, customerNumber, mailingList), _purchasesAmount(purchaseAmount) 
{
	_purchasesAmount = 0.0;
	_purchasesAmount += purchaseAmount; 
	setDiscountLevel();
}

double PreferredCustomer::getPurchasesAmount() { return _purchasesAmount; }
double PreferredCustomer::getDiscountLevel() { return _discountLevel; }

void PreferredCustomer::setPurchasesAmount(double purchasesAmount) 
{
	_purchasesAmount += purchasesAmount; 
	setDiscountLevel();
}
void PreferredCustomer::setDiscountLevel()
{
	if (_purchasesAmount < 500.0)
	{
		_discountLevel = 0.05;
	}
	else if (_purchasesAmount < 1000.0)
	{
		_discountLevel = 0.06;
	}
	else if (_purchasesAmount < 1500.0)
	{
		_discountLevel = 0.07;
	}
	else if (_purchasesAmount > 2000.0)
	{
		_discountLevel = 0.10;
	}
}