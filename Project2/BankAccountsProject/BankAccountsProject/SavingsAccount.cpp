#include "stdafx.h"
#include "SavingsAccount.h"

const double SavingsAccount::_inactivityThreshold = 25.0;
const int SavingsAccount::_withdrawalsThreshold = 4;

SavingsAccount::SavingsAccount(double accountBalance, double annualInterestRate)
	: BankAccount(accountBalance, annualInterestRate) 
{
	if (_balance < _inactivityThreshold)
	{
		_status = false;
	}
}
double SavingsAccount::withdraw(double amount)
{
	if (_status)
	{
		double newBalance = BankAccount::withdraw(amount);
		if (newBalance < 25.0)
		{
			_status = !_status;
		}
		return newBalance;
	}
	else
	{
		return -1.0;
	}
}

void SavingsAccount::deposit(double amount)
{
	if (!_status && ((_balance + amount) > _inactivityThreshold))
	{
		_status = true;
	}
	BankAccount::deposit(amount);
}

void SavingsAccount::monthlyProc()
{
	if (_numberOfWithdrawals > _withdrawalsThreshold)
	{
		_monthlyServiceCharges++;
	}
	BankAccount::monthlyProc();
	if (_balance < _inactivityThreshold)
	{
		_status = false;
	}
}