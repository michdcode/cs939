#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main ()
{
	//Initalize variables
	string runner1, runner2, runner3, first, second, third; 
	double speed1, speed2, speed3, firstt, secondt, thirdt; 

	// Explain purpose of program
	cout << "This program takes the names of three runners,\n"
			"and the time it took each runner to finish a race.\n"
			"It will then list the first, second and third place finishers.\n";
	
	// Obtain user input for runner #1 & validate time
	cout << "Please enter the name of the first runner: ";
	getline(cin, runner1);
	cout << "Please enter the first runner's finish time: ";
	cin >> speed1;
	if (speed1 <= 0)
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
	if (speed2 <= 0)
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
	if (speed3 <= 0)
	{	cout << "\nThe finish time must be positive. "
			 "\nPlease enter a positive finish time: ";
		cin >> speed3;
	}
	//Test #1
	// cout << "\nRunners names: " << runner1 << " " << runner2 << " " << runner3;
 	//cout << "\nRunners times: " << speed1 << " " << speed2 << " " << speed3; 

    // Determine rankings
    if ((speed1 < speed2) && (speed1 < speed3))
    {	if (speed2 < speed3)
		{	first = runner1;
			firstt = speed1;
			second = runner2;
			secondt = speed2;
			third = runner3;
			thirdt = speed3;
		}
		else
	  	{	first = runner1;
	    	firstt = speed1;
	    	second = runner3;
	    	secondt = speed3;
	    	third = runner2;
	    	thirdt = speed2;
    	}
    }
    else if ((speed2 < speed1) && (speed2 < speed3))
    {	if (speed1 < speed3)
    	{	first = runner2;
	    	firstt = speed2;
	    	second = runner1;
	    	secondt = speed1;
	    	third = runner3;
	    	thirdt = speed3;
    	}
    	else
    	{	first = runner2;
    		firstt = speed2;
    		second = runner3;
    		secondt = speed3;
    		third = runner1;
    		thirdt = speed1;
    	}
    }
	else if ((speed3 < speed1) && (speed3 < speed2))
    {	if (speed1 < speed2)
    	{	first = runner3;
    		firstt = speed3;
    		second = runner1;
    		secondt = speed1;
    		third = runner2;
    		thirdt = speed2;
    	}
    	else
    	{	first = runner3;
    		firstt = speed3;
    		second = runner2;
    		secondt = speed2;
    		third = runner1;
    		thirdt = speed1;
    	}
    }
    // Create table to display results
	
	cout << endl;
	cout << left << setw(37) << "First Place:"
		 << right << first << endl;
	cout << left << setw(37) << "First Place Time:"
		 << right << fixed << showpoint << firstt << endl;
	cout << left << setw(37) << "Second Place:"
		 << right << second << endl;
	cout << left << setw(37) << "Second Place Time:"
		 << right << fixed << showpoint << secondt << endl;
	cout << left << setw(37) << "Third Place:"	 
		 << right << third << endl;
	cout << left << setw(37) << "Third Place Time:"
		 << right << fixed << showpoint << thirdt << endl;
	
	return 0;
}