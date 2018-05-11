
/*Fadhar J.Castillo
CS 256 C++ Programming
ParkingTicketSimulator*/

#include "stdafx.h"
#include "ParkingTicket.h"

const int ParkingTicket::baseFine = 25;
const int ParkingTicket::hourlyFine = 10;

ParkingTicket::ParkingTicket()
{
	_ticket = "";
}
ParkingTicket::ParkingTicket(ParkedCar &pc, PoliceOfficer &po, ParkingMeter &pm)
{
	initializeTicket(pc, pm, po);
}

void ParkingTicket::initializeTicket(ParkedCar &pc, ParkingMeter &pm, PoliceOfficer &of)
{
	_ticket += "      City Of Los Angeles Police Department       \n";
	_ticket += "Make: " + pc.getMake() + " Model: " + pc.getModel() + " Color: " + pc.getColor() + " License Plate: " + pc.getLicensePlate();

	int hoursParked = pc.getMinutesParked() / 60;
	int minutesOver = pc.getMinutesParked() % 60;
	int citationTotal = baseFine + hourlyFine * hoursParked;
	if (minutesOver > 0)
	{
		citationTotal += 10;
	}

		
	_ticket += "\nCitation Amount: $" + to_string(citationTotal);
	_ticket += "\nOfficer: " + of.getOfficerName() + "	Badge Number: " + of.getBadgeNumber();
}
string ParkingTicket::printTicket()
{
	return _ticket;
}