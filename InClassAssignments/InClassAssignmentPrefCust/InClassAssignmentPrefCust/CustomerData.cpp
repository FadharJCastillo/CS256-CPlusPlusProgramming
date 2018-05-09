/*	Fadhar J. Castillo
CS 256 C++ Programming
PreferredCustomer Class*/

#include "stdafx.h"
#include "CustomerData.h"
CustomerData::CustomerData() : PersonData(), _customerNumber(0), _mailingList(false) {}

CustomerData::CustomerData(string lastName, string firstName, string address, string city, string state,
	int zip, string phone, int customerNumber, bool mailingList) : PersonData(lastName, firstName, address, city, state,
		zip, phone), _customerNumber(customerNumber), _mailingList(mailingList) {}

int CustomerData::getCustomerNumber() { return _customerNumber; }
bool CustomerData::getMailingList() { return _mailingList; }

void CustomerData::setCustomerNumber(int customerNumber) { _customerNumber = customerNumber; }
void CustomerData::setMailingList(bool mailingList) { _mailingList = mailingList; }