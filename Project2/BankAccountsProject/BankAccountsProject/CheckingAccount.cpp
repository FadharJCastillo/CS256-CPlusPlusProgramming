#include "stdafx.h"
#include "CheckingAccount.h"

const double CheckingAccount::_monthlyFee = 5.0;
const double CheckingAccount::_overDraftProtectionFee = 15.0;
const double CheckingAccount::_withdrawalFee = 0.10;

CheckingAccount::CheckingAccount(double accountBalance, double annualInterestRate)
	: BankAccount(accountBalance, annualInterestRate) {}

double CheckingAccount::withdraw(double amount)
{
	if (_balance - amount < 0)
	{
		_balance -= _overDraftProtectionFee;
		return _balance;
	}
	else
	{
		return BankAccount::withdraw(amount);
	}
}

void CheckingAccount::monthlyProc()
{
	_monthlyServiceCharges += _monthlyFee + (_withdrawalFee * _numberOfWithdrawals);
	BankAccount::monthlyProc();
}