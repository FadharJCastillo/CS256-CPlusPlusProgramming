/*Fadhar J.Castillo
CS 256 C++ Programming
ParkingTicketSimulator*/

#pragma once
#include "stdafx.h"
#include "ParkingMeter.h"

ParkingMeter::ParkingMeter(int minutesToPurchase)
{
	_minutesPurchased = minutesToPurchase;
}
int ParkingMeter::getMinutesPurchased()
{
	return _minutesPurchased;
}
void ParkingMeter::purchaseAdditionalTime(int additionalMinutes)
{
	_minutesPurchased += additionalMinutes;
}