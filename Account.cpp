#include "Account.h"

Account::Account(string name, string address, string accountNumber, string accountType) //account constructor defined
{
	this->name = name;
	this->address = address;
	this->accountNumber = accountNumber;
	this->accountType = accountType;
}

string Account::getName() {
	return name;
}

string Account::getAddress() {
	return address;
}
string Account::getAccountNumber() {
	return accountNumber;
}
string Account::getAccountType() {
	return accountType;
}
