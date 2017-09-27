#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	// Initialize global variables
	double startingBal, annualIntRate, currentBal, monthlyIntRate, totalDeposits = 0, totalWithdrawls = 0, 
		   totalIntEarned = 0, monthlyStartingBal;
	
	// Explain program 
	cout << "This program tracks your savings account for three months.\n"
		 	"You will enter the starting balance and annual intrest rate.\n"
			"Then, you will enter deposits and withdrawls for the three months.\n"
			"The program will then display results for the three months.\n";
	
	// Gather & validate starting balance and annual interest rate
	cout << "Please enter the starting balance: $";
	cin >> startingBal;
	
	while (startingBal <= 0)
	{
		cout << "\nThe starting balance should not be negative!";
		cout << "\nPlease enter a starting balance greater than zero: $";
		// cin.ignore();
		cin >> startingBal;
	}

	cout << "\nPlease enter the Annual Interest Rate, do not enter the percentage sign: ";
	cin >> annualIntRate;
	
	while (annualIntRate <= 0)
	{
		cout << "\nThe annual interest rate must be positive!\n"
		        "Please enter an annual interest rate greater than zero,\n"
				"without the percentage sign: ";
		cin >> annualIntRate;
	}

	// Calculate the Monthly Interest Rate and set the current Balance
	monthlyIntRate = (annualIntRate / 12.00)/100;
	currentBal = startingBal;
	monthlyStartingBal = startingBal;
	cout << monthlyIntRate << endl;

	// Obtain monthly values
	for (int month = 1; month < 4; month++)
	{	// Gather & validate deposits, add to deposit totals & add to current balance
		double monthlyDeposit;
		cout << "\nHow much money was deposited in month " << month << "? $";
		cin >> monthlyDeposit;

		while (monthlyDeposit < 0)
		{
			cout << "\nThe monthly deposit must be greater than zero!\n"
				    "Please enter a monthly deposit greater than zero: $";
			cin >> monthlyDeposit;
		}
		totalDeposits = totalDeposits + monthlyDeposit;
		currentBal = currentBal + monthlyDeposit;

		// Gather & validate withdrawls, add to withdrawl totals & subtract from current balance
		double monthlyWithdrawl;
		cout << "\nHow much money was withdrawn in month " << month << "? $";
		cin >> monthlyWithdrawl;

		while (monthlyWithdrawl < 0 || monthlyWithdrawl > currentBal)
		{
			cout <<"\nThe monthly withdrawl cannot be less than zero or\n"
			       "greater than the balance available.\n"
			       "Please enter a monthly withdrawl greater than zero and\n"
			       "less than the balance available: $ ";
			cin >> monthlyWithdrawl;
		}
		totalWithdrawls = totalWithdrawls + monthlyWithdrawl;
		currentBal = currentBal - monthlyWithdrawl;

		// Calculate average balance, monthly interest, add to total interest & balance, reset monthlystart
		double averageBal, monthlyInterest;
		averageBal = (monthlyStartingBal + currentBal)/2;
		cout << averageBal << "Average Balance" << endl;
		monthlyInterest = (monthlyIntRate * averageBal);
		cout << monthlyInterest << "Monthly Interest " << endl;
		totalIntEarned = totalIntEarned + monthlyInterest;
		cout << totalIntEarned << "Total Interest Earned " << endl;
		currentBal = currentBal + monthlyInterest;
		monthlyStartingBal = currentBal;

	}
	// Create table to display results
	cout << endl;
	cout << left << setw(25) << "Starting Balance: "
		 << right << "$" << startingBal << endl;
	cout << left << setw(25) << "Total Deposits: "
		 << right << "$" << totalDeposits << endl;
	cout << left << setw(25) << "Total Withdrawls: "
		 << right << "$" <<totalWithdrawls << endl;
	cout << left << setw(25) << "Total Interest Earned: "
		 << right << "$" <<totalIntEarned << endl;
	cout << left << setw(25) << "Final Balance: "
		 << right << "$" <<currentBal << endl;

	return 0;
}