/*	Fadhar J. Castillo
CS 256 C++ Programming
PreferredCustomer Class*/

#include "stdafx.h"
#include <string>
#include "PersonData.h"
using namespace std;
//Constructor
PersonData::PersonData() : _lastName(""), _firstName(""), _address(""), _city(""), _state(""),
_zip(0), _phone("") {}

PersonData::PersonData(string lastName, string firstName, string address, string city, string state, int zip, string phone)
	: _lastName(lastName), _firstName(firstName), _address(address), _city(city), _state(state), _zip(zip), _phone(phone){}

//Accessors
string PersonData::getLastName() { return _lastName; }
string PersonData::getFirstName() { return _firstName; }
string PersonData::getAddress() { return _address; }
string PersonData::getCity() { return _city; }
string PersonData::getState() { return _state; }
int PersonData::getZip() { return _zip; }
string PersonData::getPhone() { return _phone; }

//Mutators
void PersonData::setLastName(string lastName) { _lastName = lastName; }
void PersonData::setFirstName(string firstName) { _firstName = firstName; }
void PersonData::setAddress(string address) { _address = address; }
void PersonData::setCity(string city) { _city = city; }
void PersonData::setState(string state) { _state = state; }
void PersonData::setZip(int zip) { _zip = zip; }
void PersonData::setPhone(string phone) { _phone = phone; }
