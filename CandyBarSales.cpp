// Candy Bar Sales 
#include <iostream>
using namespace std;

int main()
{
	double candyBarsSold, profitPerCandyBar, earnings;

	// Get the number of candy bars sold.
	cout << "How many candy bars were sold?";
	cin >> candyBarsSold;
	
	// Get the amount of profit.
	cout << "\nHow much profit is generated from each candy bar sold?";
	cin >> profitPerCandyBar;

	// Calculate the profit.
	earnings = candyBarsSold * profitPerCandyBar;

	// Display the earnings.
	cout << "\nYou have earned $" << earnings << endl; 

	return 0;
}