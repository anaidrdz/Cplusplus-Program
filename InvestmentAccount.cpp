#include "InvestmentAccount.h"


using namespace std;


//define constructor without a monthly deposit
InvestmentAccount::InvestmentAccount(string name, string address, string accountNumber, double initialAmount, double annualInterestRate) : Account (name, address,accountNumber, "Investment-Compound Monthly, WITHOUT Monthly Deposit")
{
	this->initialAmount = initialAmount;
	this->annualInterestRate = annualInterestRate;
	this->monthlyDeposit = 0;
}

//define constructor with a monthly deposit
InvestmentAccount::InvestmentAccount(string name, string address, string accountNumber, double initialAmount, double annualInterestRate, double monthlyDeposit) : Account(name, address, accountNumber, "Investment-Compount Monthly, WITH Monthly Deposit")
{
	this->initialAmount = initialAmount;
	this->annualInterestRate = annualInterestRate;
	this->monthlyDeposit = monthlyDeposit;
}

double InvestmentAccount::getEndingBalance(int numberOfYears)	//calculate and return the total balance and the end of each year
{
	double openingAmount = initialAmount;
	double totalYearInterest = 0;
	double monthInterest;
	for (int month = 1; month <= numberOfYears * 12; month++) {
		monthInterest = (openingAmount + monthlyDeposit) * ((annualInterestRate / 100.0) / 12.0);
		totalYearInterest = totalYearInterest + monthInterest;
		openingAmount = (openingAmount + monthlyDeposit) + monthInterest;
	}
	return ceil(openingAmount * 100.0) / 100.0;
}

double InvestmentAccount::getInterestEarned(int numberOfYears) //calculate and return the interest earned each year
{
	double openingAmount = initialAmount;
	double totalYearInterest = 0;
	double monthInterest;
	double yearlyInterest = 0;
	double accumulatedInterest = 0;

	for (int month = 1; month <= numberOfYears * 12; month++) {
		monthInterest = (openingAmount + monthlyDeposit) * ((annualInterestRate/100.0)/12.0);
		totalYearInterest = totalYearInterest + monthInterest;
		if (month % 12 == 0) {
			yearlyInterest = totalYearInterest - accumulatedInterest;
			accumulatedInterest = accumulatedInterest + yearlyInterest;
		}
		openingAmount = (openingAmount + monthlyDeposit) + monthInterest;
	}
	return floor(yearlyInterest * 100.0) / 100.0;
}

string InvestmentAccount::getAccountType()
{
	return Account::getAccountType();
}

double InvestmentAccount::getInitialAmount()
{
	return initialAmount;
}

double InvestmentAccount::getMonthlyDeposit()
{
	return monthlyDeposit;
}

double InvestmentAccount::getAnnualInterestRate()
{
	return annualInterestRate;
}

string InvestmentAccount::doubleToString(double number)	//method used to format output and add a dollar sign
{
	string numberToString = to_string(number);
	for (int i = 0; i <= 3; i++) {
		numberToString.pop_back();
	}
	numberToString.insert(0, "$");
	return numberToString;
}



