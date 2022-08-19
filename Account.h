#pragma once
#include <cmath>
#include <string>

using namespace std;

class Account { //abstract account class declared

public:
	Account(string name, string address, string accountNumber, string accountType);
	virtual double getEndingBalance(int numberOfYears) = 0;
	virtual double getInterestEarned(int numberOfYears) = 0;
	string getName();
	string getAddress();
	string getAccountNumber();
	string getAccountType();



private:
	string name;
	string address;
	string accountNumber;
	string accountType;


};