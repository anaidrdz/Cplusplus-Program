#pragma once
#include "Account.h"

class InvestmentAccount : public Account { //declare child class of account

public:
	InvestmentAccount(string name, string address, string accountNumber, double initialAmount, double annualInterestRate);
	InvestmentAccount(string name, string address, string accountNumber, double initialAmount, double annualInterestRate, double monthlyDeposit);

	virtual double getEndingBalance(int numberOfYears);
	virtual double getInterestEarned(int numberOfYears);
	virtual string getAccountType();

	double getInitialAmount();
	double getMonthlyDeposit();
	double getAnnualInterestRate();
	string doubleToString(double number);

private:
	double initialAmount;
	double monthlyDeposit;
	double annualInterestRate;
};