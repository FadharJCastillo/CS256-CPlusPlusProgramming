/*Fadhar J.Castillo
CS 256 C++ Programming
ParkingTicketSimulator*/

#pragma once
#include "stdafx.h"
#include <string>
#include "ParkedCar.h"
#include "PoliceOfficer.h"
#include "ParkingMeter.h"
using namespace std;

class ParkingTicket
{
private:
	const static int baseFine;
	const static int hourlyFine;
	string _ticket;
public:
	ParkingTicket();
	ParkingTicket(ParkedCar &pc, PoliceOfficer &po, ParkingMeter &pm);
	
	void initializeTicket(ParkedCar &pc, ParkingMeter &pm, PoliceOfficer &of);
	string printTicket();
};

