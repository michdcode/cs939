#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

// Payroll class declaration
class Payroll
{	
	public:
		double hours;
		double hourlyRate;
		Payroll(double hoursWorked, double payRate) // Constructor with two parameters
		{	
			hours = hoursWorked;
			hourlyRate = payRate;
		}

		Payroll() // Default constructor
		{	hours = 0.0;
			hourlyRate = 0.0;
		}

		double totalGrossPay()
		{	double grossPay = hours*hourlyRate; 
			return grossPay;
		}
};

int main()
{	// Declare constants & variables
	const int NUM_EMPS = 7;
	ifstream dataIn;
	Payroll employeeInfo[NUM_EMPS];
	int index;
	double pay;

	// Open data file
	dataIn.open("payroll.dat");
	if (!dataIn)
		cout << "Error opening file.\n";
	else
	{	// Fill in array with data from file
		for (index = 0; index < NUM_EMPS; index++)
		{
			dataIn >> employeeInfo[index].hours;
			dataIn >> employeeInfo[index].hourlyRate;
		}
		dataIn.close();
	}

	// Display each employee's gross pay
	cout << "\nHere is the gross pay for each employee:\n";
	cout << fixed << showpoint << setprecision(2);
	for (index = 0; index < NUM_EMPS; index++)
	{
		cout << "Employee #" << (index + 1);
		cout << ": $" << setw(7) << employeeInfo[index].totalGrossPay() << endl;
	}
}