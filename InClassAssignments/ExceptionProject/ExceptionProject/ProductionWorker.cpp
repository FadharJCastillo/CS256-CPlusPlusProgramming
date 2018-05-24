// Fadhar Jared Castillo
// CS 256 C++ Programming
// In-Class Exercise: ExceptionProject
//

#include "stdafx.h"
#include "ProductionWorker.h"

ProductionWorker::ProductionWorker() : Employee()
{
	setShift(1);
	setHourlyPayRate(0);
}

ProductionWorker::ProductionWorker(string name, int number, int month, int day, int year, int shift, double hourlyPayRate)
	: Employee(name, number, month, day, year)
{
	try
	{
		setShift(shift);
	}
	catch (InvalidShiftException)
	{
		throw;
	}
	try
	{
		setHourlyPayRate(hourlyPayRate);
	}
	catch (InvalidHourlyPayRateException)
	{
		throw;
	}
}
int ProductionWorker::getShift()
{
	return shift;
}
double ProductionWorker::getHourlyPayRate()
{
	return hourlyPayRate;
}
void ProductionWorker::setShift(int shift)
{
	if (shift == 1 || shift == 2)
	{
		this->shift = shift;
	}
	else
	{
		throw InvalidShiftException();
	}
}

void ProductionWorker::setHourlyPayRate(double payRate)
{
	if (payRate < 0)
	{
		throw InvalidHourlyPayRateException();
	}
	else
	{
		hourlyPayRate = payRate;
	}
}