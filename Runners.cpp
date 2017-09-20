#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main ()
{
	//Initalize variables
	string runner1, runner2, runner3;
	double speed1, speed2, speed3;

	// Explain purpose of program
	cout << "This program takes the names of three runners,\n"
			"and the time it took each runner to finish a race.\n"
			"It will then list the first, second and third place finishers.\n";
	
	// Obtain user input for runner #1 & validate time
	cout << "Please enter the name of the first runner: ";
	getline(cin, runner1);
	cout << "Please enter the first runner's finish time: ";
	cin >> speed1;
	if !(speed1 > 0)
	{	cout << "\nThe finish time must be positive. "
			 "\nPlease enter a positive finish time: ";
		cin >> speed1;
	}

	// Obtain user input for runner #2 & validate time
	cout << "Please enter the name of the second runner: ";
	cin.ignore();
    getline(cin, runner2);
	cout << "Please enter the second runner's finish time: ";
	cin >> speed2;
	if !(speed2 > 0)
	{	cout << "\nThe finish time must be positive. "
			 "\nPlease enter a positive finish time: ";
		cin >> speed2;
	}

	// Obtain user input for runner #3 & validate time
	cout << "Please enter the name of the third runner: ";
	cin.ignore();
    getline(cin, runner3);
	cout << "Please enter the third runner's finish time: ";
	cin >> speed3;
	if !(speed3 > 0)
	{	cout << "\nThe finish time must be positive. "
			 "\nPlease enter a positive finish time: ";
		cin >> speed3;
	}
	//Test #1
	cout << "\nRunners names: " << runner1 << " " << runner2 << " " << runner3;
    cout << "\nRunners times: " << speed1 << " " << speed2 << " " << speed3; 

    
	return 0;
}