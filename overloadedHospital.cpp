#include <iostream>
using namespace std;

// List function prototypes
double checkValidity(double &number);
double totalCharges(double, double);
double totalCharges(double, double, double, double);


int main()
{
	// Initalize variables
	int stayType;
	double hospitalServ, medicationCharges, stayLength, dailyRate, total; 

	// Explain purpose of program
	cout << "This program will tally the total charges for an outpatient or inpatient\n"
	 	 << "hospital stay. \n";

	// Determine type of patient & validate input
	cout << "If you were an outpatient, please type 1. \n"
	 	 << "If you were an inpatient, please type 2. \n > ";
	cin >> stayType;

	while (stayType != 1 && stayType != 2)
	{
	 	cout << "\nPlease use a valid entry. Type 1 for outpatient \n"
	 		    "or type 2 for inpatient.";
	 	// cin.ignore();
	 	cin >> stayType;
	}

	// Get user information for hospital services & medication charges
	cout << "Please enter the charges for hospital services (lab tests, etc).\n"
		 << "Please do not enter the dollar sign. > ";
	cin >> hospitalServ;
	checkValidity(hospitalServ);

	cout << "Please enter the hospital medication charges.\n"
		 << "Please do not enter the dollar sign. > ";
	cin >> medicationCharges;
	checkValidity(medicationCharges);

	if (stayType == 2)
	{
		//If person is inpatient, collect number of days and daily rate
		cout << "\nPlease enter the number of days you were in the hospital?\n"
		 	 << "Please do not enter the dollar sign. > ";
		cin >> stayLength;
		checkValidity(stayLength);

		cout << "\nPlease enter the daily date.\n"
		 	 << "Please do not enter the dollar sign. > ";
		cin >> dailyRate;
		checkValidity(dailyRate);

	}

	//Calculate total charges with appropriate function
	if (stayType == 1)
		total = totalCharges(hospitalServ, medicationCharges); 
	else
		total = totalCharges(hospitalServ, medicationCharges, stayLength, dailyRate);


	//Display total cost

	cout << "\n The total cost is $ " << total;

	return 0;
}

// Checks that any inputed value is greater than zero
double checkValidity(double &number)
{
	while (number < 0)
	{
		cout << "The value must be greater than zero.\n"
			 << "Please enter a value greater than zero. \n >";
		cin >> number;
	}

	return number;
}

// Calculates total for outpatient stay
double totalCharges(double hospCost, double medCost)
{
	return hospCost + medCost;
}

// Calculates total for inpatient stay
double totalCharges(double hospCost, double medCost, double stay, double rate)
{
	return (stay * rate) + hospCost + medCost;
}


