/*Fadhar J.Castillo
CS 256 C++ Programming
ParkingTicketSimulator*/

#include "stdafx.h"
#include "PoliceOfficer.h"

PoliceOfficer::PoliceOfficer(string officerName, string badgeNumber)
	: _officerName(officerName), _badgeNumber(badgeNumber) {}

string PoliceOfficer::getOfficerName()
{
	return _officerName;
}

string PoliceOfficer::getBadgeNumber()
{
	return _badgeNumber;
}

void PoliceOfficer::setOfficerName(string officerName)
{
	_officerName = officerName;
}

void PoliceOfficer::setBadgeNumber(string badgeNumber)
{
	_badgeNumber = badgeNumber;
}

bool PoliceOfficer::inspectParkedCar(ParkedCar &pc, ParkingMeter & pm)
{
	if (pc.getMinutesParked() > pm.getMinutesPurchased())
		return true;
	else
		return false;
}