/*Fadhar J.Castillo
CS 256 C++ Programming
ParkingTicketSimulator*/

#include "stdafx.h"
#include "ParkedCar.h"


ParkedCar::ParkedCar(string make, string model, string color, string licensePlate, int minutesParked)
	: _make(make), _model(model), _color(color), _licensePlate(licensePlate), _minutesParked(minutesParked) {}

string ParkedCar::getMake()
{
	return _make;
}
string ParkedCar::getModel()
{
	return _model;
}
string ParkedCar::getColor()
{
	return _color;
}
string ParkedCar::getLicensePlate()
{
	return _licensePlate;
}
int ParkedCar::getMinutesParked()
{
	return _minutesParked;
}

void ParkedCar::setMake(string make)
{
	_make = make;
}
void ParkedCar::setModel(string model)
{
	_model = model;
}
void ParkedCar::setColor(string color)
{
	_color = color;
}
void ParkedCar::setLicensePlate(string licensePlate)
{
	_licensePlate = licensePlate;
}
void ParkedCar::setMinutesParked(int minutesParked)
{
	_minutesParked = minutesParked;
}