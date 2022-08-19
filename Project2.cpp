
#include "Account.h"
#include "InvestmentAccount.h"
#include <iostream>
#include <iomanip>



using namespace std;

void menu() { //print main menu
	cout << endl << "MENU" << endl;
	cout << "Please enter selection" << endl;
	cout << "1. Calculate an Investment-Compound account" << endl;
	cout << "2. Exit" << endl << endl;
}

void displayAccountInfo(InvestmentAccount account) {		//displays the account details from user input
	cout << "---------------------------------------------------------------------------------------------- " << endl << endl;
	cout << "Account Type:		" << account.getAccountType() << endl;
	cout << "ACCOUNT DETAILS:  Initial Amount: $" << account.getInitialAmount() << ".00, Annual Interest Rate: " << account.getAnnualInterestRate() << ".00%, Monthly Deposit: $" << account.getMonthlyDeposit() << endl << endl;
	
	cout << "NAME: " << account.getName() << "		||	";
	cout << "ADDRESS: " << account.getAddress() << "	||	";
	cout << "ACCOUNT NUMBER: " << account.getAccountNumber() << endl << endl;
	cout << setw(31) << right << "Interest Earned" << setw(20) << right << "Ending Balance" << endl << endl;
}

bool inputValidation(double input) { //validate number is positive
	if (input <= 0) {
		return false;
	}
	else if (input > 0) {
		return true;
	}
}
 

int main() {
	
	string accountName;
	string accountAddress;
	string accountNumber;
	double accountInitialAmount;
	double accountAnnualInterest;
	double accountMonthlyDeposit;
	int accountYears; 

	cout << "Name on Account: "; getline(cin, accountName);
	cout << "Address: "; getline(cin, accountAddress);				//user inputs account details
	cout << "Account Number: "; cin >> accountNumber;

	menu();
	string userInput;
	cin >> userInput;

	//main loop begins
	do {	
		if (userInput == "1") {

			//investment account information is inputted and validated to be posititve numbers
			do {
				cout << "Initial Deposit: "; cin >> accountInitialAmount;
			} while (inputValidation(accountInitialAmount) == false);
			
			do {
				cout << "Annual Interest Rate: "; cin >> accountAnnualInterest;					
			} while (inputValidation(accountAnnualInterest) == false);

			do {
				cout << "Monthly Deposit: "; cin >> accountMonthlyDeposit;
			} while (inputValidation(accountMonthlyDeposit) == false);

			do {
				cout << "Number of Years: "; cin >> accountYears;
			} while (inputValidation(accountYears) == false);
			
			//account without monthly deposit created
			InvestmentAccount account1 = InvestmentAccount(accountName, accountAddress, accountNumber, accountInitialAmount, accountAnnualInterest); 
			
			displayAccountInfo(account1); //display account details
			for (int i = 1; i <= accountYears * 12; i++) {		//output formatted account calculations
				if (i % 12 == 0) {
					cout << "Year: " << setw(10) << left << i / 12 << setw(15) << right << account1.doubleToString(account1.getInterestEarned(i / 12));
					cout << setw(20) << right << account1.doubleToString(account1.getEndingBalance(i / 12)) << endl << endl;
				}
			} cout << "---------------------------------------------------------------------------------------------- " << endl;
			

			//account with monthly deposit created
			InvestmentAccount account2 = InvestmentAccount(accountName, accountAddress, accountNumber, accountInitialAmount, accountAnnualInterest, accountMonthlyDeposit); 
			
			displayAccountInfo(account2); //display account details
			for (int i = 1; i <= accountYears * 12; i++) {		//output formatted account calculations
				if (i % 12 == 0) {
					cout << "Year: " << setw(10) << left << i / 12 << setw(15) << right << account2.doubleToString(account2.getInterestEarned(i / 12));
					cout << setw(20) << right << account2.doubleToString(account2.getEndingBalance(i / 12)) << endl << endl;
				}
			} cout << "---------------------------------------------------------------------------------------------- " << endl;
			
			menu();
			cin >> userInput;
		}

		else {	//handles invalid user input for menu
			cout << "Please input a valid selection" << endl << endl;
			menu();
			cin >> userInput;
		}

	} while (userInput != "2");		//loop continues until user input '2'
	
}
		