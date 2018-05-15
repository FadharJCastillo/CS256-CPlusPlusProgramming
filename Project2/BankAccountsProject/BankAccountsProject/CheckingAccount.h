#pragma once
#include "stdafx.h"
#include "BankAccount.h"

class CheckingAccount : public BankAccount
{
private:
	static const double _monthlyFee;
	static const double _overDraftProtectionFee;
	static const double _withdrawalFee;
public:
	CheckingAccount(double accountBalance, double annualInterestRate);
	virtual double withdraw(double amount);
	virtual void monthlyProc();
};