/*Fadhar J.Castillo
CS 256 C++ Programming
ParkingTicketSimulator*/

#pragma once
#include "stdafx.h"
#include <string>
using namespace std;

class ParkedCar
{
private:
	string _make, _model, _color, _licensePlate;
	int _minutesParked;

public:
	ParkedCar(string make, string model, string color, string licensePlate, int minutesParked);
	string getMake();
	string getModel ();
	string getColor();
	string getLicensePlate();
	int getMinutesParked();
	void setMake(string make);
	void setModel(string model);
	void setColor(string color);
	void setLicensePlate(string licensePlate);
	void setMinutesParked(int minutesParked);
};
