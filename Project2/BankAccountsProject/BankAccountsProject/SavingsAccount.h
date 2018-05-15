#pragma once
#include "stdafx.h"
#include "BankAccount.h"

class SavingsAccount : public BankAccount
{
private:
	bool _status;
	static const double _inactivityThreshold;
	static const int _withdrawalsThreshold;
public:
	SavingsAccount(double accountBalance, double annualInterestRate);
	virtual double withdraw(double amount);
	virtual void deposit(double amount);
	virtual void monthlyProc();
};