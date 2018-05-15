#pragma once
#include "stdafx.h"

class BankAccount
{
protected:
	double _startingBalance, _balance, _annualInterestRate, _lastMonthServiceCharges,_monthlyServiceCharges, _interestEarned;
	int _numberOfDeposits, _numberOfWithdrawals;
	
public:
	/*Constructor instantiates a new BankAccount with starting specified
		balance and annual interst rate*/
	BankAccount(double accountBalance, double annualInterestRate);
	
	/*deposit function increases the balance of the account
		by the amout specified*/
	virtual void deposit(double amount);
	
	/*withdraw subtracts the amount specified from the account
		and returns the remaining account balance*/
	virtual double withdraw(double amount);
	
	/*calculateInterest calculates the monthly interest that is
		owed to the account, increases the account balance by the 
		monthly interest gained*/
	virtual void calculateInterest();
	
	/*monthlyProc subtracts the monthly service charges from the balance*/
	virtual void monthlyProc();
	
	/*seeBalance returns the account balance*/
	virtual double seeBalance();

	virtual int getNumberOfDeposits();
	virtual int getNumberOfWithdrawals();
	virtual double getStartingBalance();
	virtual double getEarnedInterest();
	virtual double getServiceCharges();
	virtual double getLastMonthServiceCharges();
};