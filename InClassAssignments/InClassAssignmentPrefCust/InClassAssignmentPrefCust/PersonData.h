/*	Fadhar J. Castillo
CS 256 C++ Programming
PreferredCustomer Class*/

#pragma once
#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;
class PersonData {
private:
	string _lastName, _firstName, _address, _city, _state, _phone;
	int _zip;
public:
	//Constructors
	PersonData();
	PersonData(string lastName, string firstName, string address, string city, string state,
		int zip, string phone);
	//Accessors
	string getLastName();
	string getFirstName();
	string getAddress();
	string getCity();
	string getState();
	int getZip();
	string getPhone();

	//Mutators
	void setLastName(string lastName);
	void setFirstName(string firstName);
	void setAddress(string address);
	void setCity(string city);
	void setState(string state);
	void setZip(int zip);
	void setPhone(string phone);
};