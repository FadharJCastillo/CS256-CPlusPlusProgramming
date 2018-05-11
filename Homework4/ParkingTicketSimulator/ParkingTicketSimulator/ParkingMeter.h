/*Fadhar J.Castillo
CS 256 C++ Programming
ParkingTicketSimulator*/

#pragma once
#include "stdafx.h"

class ParkingMeter {
	int _minutesPurchased;
	ParkingMeter();
public:
	
	ParkingMeter(int);
	int getMinutesPurchased();
	void purchaseAdditionalTime(int);
};
