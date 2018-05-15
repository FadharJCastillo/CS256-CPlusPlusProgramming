#include "stdafx.h"
#include "BankAccount.h"

BankAccount::BankAccount(double accountBalance, double annualInterestRate)
	: _startingBalance(accountBalance), _balance(accountBalance), _annualInterestRate(annualInterestRate), _numberOfDeposits(0),
	_numberOfWithdrawals(0), _monthlyServiceCharges(12.0), _lastMonthServiceCharges(0), _interestEarned(0) {}
	
void BankAccount::deposit(double amount)
{
	_balance += amount;
	_numberOfDeposits++;
}

double BankAccount::withdraw(double amount)
{
	_balance -= amount;
	_numberOfWithdrawals++;
	return _balance;
}

void BankAccount::calculateInterest()
{
	double monthlyInterestRate = (_annualInterestRate / 12);
	_interestEarned = _balance * monthlyInterestRate;
	_balance += _interestEarned;
}

void BankAccount::monthlyProc()
{
	_lastMonthServiceCharges = _monthlyServiceCharges;
	_balance -= _monthlyServiceCharges;
	_numberOfDeposits = 0;
	_numberOfWithdrawals = 0;
	_monthlyServiceCharges = 0;
	calculateInterest();
}

double BankAccount::seeBalance()
{
	return _balance;
}

int BankAccount::getNumberOfDeposits()
{
	return _numberOfDeposits;
}
int BankAccount::getNumberOfWithdrawals()
{
	return _numberOfWithdrawals;
}
double BankAccount::getStartingBalance()
{
	return _startingBalance;
}
double BankAccount::getEarnedInterest()
{
	return _interestEarned;
}
double BankAccount::getServiceCharges()
{
	return _monthlyServiceCharges;
}
double BankAccount::getLastMonthServiceCharges()
{
	return _lastMonthServiceCharges;
}