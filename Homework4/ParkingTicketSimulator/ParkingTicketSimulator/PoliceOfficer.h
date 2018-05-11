/*Fadhar J.Castillo
CS 256 C++ Programming
ParkingTicketSimulator*/

#pragma once
#include "stdafx.h"
#include "ParkedCar.h"
#include "ParkingMeter.h"

#include <string>
using namespace std;

class PoliceOfficer
{
private:
	string _officerName, _badgeNumber;
public:
	PoliceOfficer(string officerName, string badgeNumber);
	string getOfficerName();
	string getBadgeNumber();
	void setOfficerName(string officerName);
	void setBadgeNumber(string badgeNumber);
	bool inspectParkedCar(ParkedCar &pc, ParkingMeter & pm);
};