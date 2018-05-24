// Fadhar Jared Castillo
// CS 256 C++ Programming
// In-Class Exercise: ExceptionProject
//

#include "stdafx.h"
#include "Employee.h"
Employee::Employee() : name(""), number(0) { setHireDate(1, 1, 2000); }

Employee::Employee(string name, int number, int month, int day, int year) 
	: name(name) 
{
	try
	{
		setEmployeeNumber(number);
	}
	catch (InvalidEmployeeNumberException)
	{
		throw;
	}
	setHireDate(month, day, year); 
}

string Employee::getName()
{
	return name;
}

int Employee::getEmployeeNumber()
{
	return number;
}

string Employee::getHireDate()
{
	return hireDate;
}

void Employee::setName(string name)
{
	this->name = name;
}

void Employee::setEmployeeNumber(int number)
{
	if (number < 0 || number > 9999)
	{
		throw InvalidEmployeeNumberException();
	}
	else
	{
		this->number = number;
	}
}

void Employee::setHireDate(int month, int day, int year)
{
	hireDate = to_string(month) + "/" + to_string(day) + "/" + to_string(year);
}