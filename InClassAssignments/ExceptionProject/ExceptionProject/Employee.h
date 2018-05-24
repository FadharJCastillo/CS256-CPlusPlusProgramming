// Fadhar Jared Castillo
// CS 256 C++ Programming
// In-Class Exercise: ExceptionProject
//

#pragma once
#include "stdafx.h"
#include <string>
using namespace std;
class Employee
{
private:
	string name, hireDate;
	int number;
	
public:
	Employee();
	Employee(string name, int number, int month, int day, int year);
	string getName();
	int getEmployeeNumber();
	string getHireDate();
	void setName(string name);
	void setEmployeeNumber(int number);
	void setHireDate(int month, int day, int year);
	class InvalidEmployeeNumberException {};
};