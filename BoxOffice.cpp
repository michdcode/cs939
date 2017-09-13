#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	// Initialize constants and variables.
	const int ADULT_TICKET_PRICE = 6.00, CHILD_TICKET_PRICE = 3.00;
	// char oQuote, cQuote;
	// oQuote = 34;
	// cQuote = 211;
	string movieName;
	int adultTicketsSold, childTicketsSold;
	float gross, net, distributorPay;

	// Obtain movie and ticket information.
	cout << "What is the name of the movie? ";
	getline(cin, movieName);
	cout << "\nHow many adult tickets were sold? ";
	cin >> adultTicketsSold;
	cout << "\nHow many child tickets were sold? ";
	cin >> childTicketsSold;
	cout << endl;

	// Calculate gross profit, net profit, and amount to pay distributor
	gross = (ADULT_TICKET_PRICE * adultTicketsSold) + (CHILD_TICKET_PRICE * childTicketsSold);
	net = gross * .20;
	distributorPay = gross - net;

	// Create table to display report
	cout << left << setw(37) << "Movie Name:"
		 << right << "\"" << movieName << "\"" << endl;
	cout << left << setw(37) << "Adult Tickets Sold:"
		 << right << adultTicketsSold << endl;
	cout << left << setw(37) << "Child Tickets Sold:"
		 << right << childTicketsSold << endl;
	cout << left << setw(37) << "Gross Box Office Profit:"
		 << right << "$" << fixed << showpoint << setprecision(2) << gross << endl;
	cout << left << setw(37) << "Amount Paid to Distributor:"
		 << right << "$" << fixed << showpoint << setprecision(2) << distributorPay << endl;
	cout << left << setw(37) << "Net Box Office Profit:"
		 << right << "$" << fixed << showpoint << setprecision(2) << net << endl; 

	return 0; 
}
