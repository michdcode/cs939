#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main ()
{
	//Initalize variables
	string name, date1, date2, date3, firstDate, secondDate, thirdDate; 
	double height1, height2, height3, first, second, third; 

	// Explain purpose of program
	cout << "This program takes the name of one pole vaulter,\n"
			"and the dates and heights of three jumps.\n"
			"It will then list the first, second, and third place jumps.\n";
	
	// Obtain the name of the pole vaulter
	cout << "Please enter the name of the pole vaulter: ";
	getline(cin, name);
    cout << endl;
	
	// Obtain the date & height of the first pole vault & validate height
	cout << "Please enter the date of the first pole vault: ";
	getline(cin, date1);
	cout << "\nPlease enter the height of the first pole vault in meters: ";
	cin >> height1;
	if ((height1 < 2) || (height1 > 5)) 	
	{	cout << "\nThe height cannot be less than 2 meters or greater than 5 meters"
			 "\nPlease enter a conforming height: ";
		cin >> height1;
	}

	// Obtain the date & height of the second pole vault & validate height
	cout << "\nPlease enter the date of the second pole vault: ";
	cin.ignore();
    getline(cin, date2);
	cout << "\nPlease enter the height of the second pole vault in meters: ";
	cin >> height2;
	if ((height2 < 2) || (height2 > 5)) 	
	{	cout << "\nThe height cannot be less than 2 meters or greater than 5 meters"
			 "\nPlease enter a conforming height: ";
		cin >> height2;
	}

	// Obtain the date & height of the third pole vault & validate height
	cout << "\nPlease enter the date of the third pole vault: ";
	cin.ignore();
    getline(cin, date3);
	cout << "\nPlease enter the height of the third pole vault in meters: ";
	cin >> height3;
	if ((height3 < 2) || (height3 > 5)) 	
	{	cout << "\nThe height cannot be less than 2 meters or greater than 5 meters"
			 "\nPlease enter a conforming height: ";
		cin >> height3;
	}

    // Determine rankings
    if ((height1 > height2) && (height1 > height3))
    {	if (height2 > height3)
		{	first = height1;
			firstDate = date1;
			second = height2;
			secondDate = date2;
			third = height3;
			thirdDate = date3;
		}
		else
	  	{	first = height1;
	    	firstDate = date1;
	    	second = height3;
	    	secondDate = date3;
	    	third = height2;
	    	thirdDate = date2;
    	}
    }
    else if ((height2 > height1) && (height2 > height3))
    {	if (height1 > height3)
    	{	first = height2;
	    	firstDate = date2;
	    	second = height1;
	    	secondDate = date1;
	    	third = height3;
	    	thirdDate = date3;
    	}
    	else
    	{	first = height2;
    		firstDate = date2;
    		second = height3;
    		secondDate = date3;
    		third = height1;
    		thirdDate = date1;
    	}
    }
	else if ((height3 > height1) && (height3 > height2))
    {	if (height1 > height2)
    	{	first = height3;
    		firstDate = date3;
    		second = height1;
    		secondDate = date1;
    		third = height2;
    		thirdDate = date2;
    	}
    	else
    	{	first = height3;
    		firstDate = date3;
    		second = height2;
    		secondDate = date2;
    		third = height1;
    		thirdDate = date1;
    	}
    }
    // Create table to display results
	
	cout << endl;
	cout << left << setw(45) << "Name of Pole Vaulter: "
		 << right << name << endl;
	cout << left << setw(45) << "Height of First Place (Best) Pole Vault:"
		 << right << fixed << showpoint << first << " meters" << endl;
	cout << left << setw(45) << "Date of Best Pole Vault:"
		 << right << firstDate << endl;
	cout << left << setw(45) << "Height of Second Place Pole Vault:"
		 << right << fixed << showpoint << second << " meters" << endl;
	cout << left << setw(45) << "Date of Second Place Pole Vault:"
		 << right << secondDate << endl;
	cout << left << setw(45) << "Height of Third Place (Worst) Pole Vault:"
		 << right << fixed << showpoint << third << " meters" << endl;
	cout << left << setw(45) << "Date of Third Place (Worse) Pole Vault:"
		 << right << thirdDate << endl;

	return 0;
}