// Fadhar Jared Castillo
// CS 256 C++ Programming
// In-Class Exercise: ExceptionProject
//

#pragma once
#include "stdafx.h"
#include "Employee.h"

class ProductionWorker : public Employee
{
private:
	int shift;
	double hourlyPayRate;
public:
	ProductionWorker();
	ProductionWorker(string name, int number, int month, int day, int year, int shift, double hourlyPayRate);
	int getShift();
	double getHourlyPayRate();
	void setShift(int shift);
	void setHourlyPayRate(double payRate);
	class InvalidShiftException {};
	class InvalidHourlyPayRateException {};
};