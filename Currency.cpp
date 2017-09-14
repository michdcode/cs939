#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	// Initialize constants and variables.
	const float YEN_PER_DOLLAR = 110.49, EUROS_PER_DOLLAR = 0.84;
	float dollars, yen, euros; 
	
	// Obtain U.S. dollar amounts. 
	cout << "This is a currency converter.\n";
	cout << "It will convert U.S. dollars into Yen and Euros.\n";
	cout << "Enter the amount of U.S. dollars, do NOT type the dollar sign: ";
	cin >> dollars;
	cout << endl;

	// Conversion calculations
	yen = dollars * YEN_PER_DOLLAR;
	euros = dollars * EUROS_PER_DOLLAR;

	// Display the conversion results
	cout << "\nCurrency Converter\n";
	cout << "---------------------\n";
	cout << left << setw(10) << "Dollars: "
		 << right << "$" << fixed << showpoint << setprecision(2) << dollars << endl;
	cout << left << setw(10) << "Yen: " 
		 << right << "¥" << fixed << showpoint << setprecision(2) << yen << endl;
	cout << left << setw(10) << "Euros: " 
		 << right << "€" << fixed << showpoint << setprecision(2) << euros << endl;
	return 0; 
}
	