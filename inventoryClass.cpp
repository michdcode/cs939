// Inventory Class - Question 7

#include <iostream>
#include <iomanip>
using namespace std;

//Inventory Class declaration
class Inventory
{	private:
		int itemNumber;
		int quantity;
		double cost;

	public:
		// constructors
		Inventory() //default
		{
			itemNumber = 0;
			quantity = 0;
			cost = 0.0;
		} 
		Inventory(int userItemNumber, int userQuantity, double userCost)
		{
			setItemNumber(userItemNumber);
			setQuantity(userQuantity);
			setCost(userCost);
			getTotalCost();
		}
		// Function definitions -- inline because they are all short 
		// Accessor functions
		int getItemNumber()
		{ 	return itemNumber; }

		int getQuantity()
		{	return quantity; }

		double getCost()
		{	return cost; }

		double getTotalCost()
		{	return cost * quantity; }

		// Mutator functions
		void setItemNumber(int iNumber)
		{	itemNumber = iNumber; }

		void setQuantity(int iQuantity)
		{	quantity = iQuantity; }

		void setCost(double iCost)
		{	cost = iCost; }
};

//function prototypes for main
double checkDoubleValidity(double &number);
int checkValidity(int &number);

int main()
{
	// initialize variables
	int uItem, uQuantity;
	double uCost;

	// Explain purpose of program
	cout << "This program will take an item number, quantity & cost as \n"
		 << "part of an inventory system.\n";
	
	// Obtain user inputs & validate
	cout << "\nPlease enter the Item Number: ";
	cin >> uItem;
	checkValidity(uItem);

	cout << "\nPlease enter the Quantity: ";
	cin >> uQuantity;
	checkValidity(uQuantity);

	cout << "\nPlease enter the Cost, but do not enter the dollar sign: $";
	cin >> uCost;
	checkDoubleValidity(uCost);

	// Create object & Display values:
	Inventory newItem(uItem, uQuantity, uCost);
	cout << fixed << showpoint << setprecision(2) << endl; 
	cout << "\nThe item number is: " << newItem.getItemNumber() << endl;
	cout << "\nThe quantity is: " << newItem.getQuantity() << endl;
	cout << "\nThe item cost is: " << newItem.getCost () << endl;
	cout << "\nThe total cost is: $" << newItem.getTotalCost() << endl; 

	return 0;
}

// Checks that any int input value is greater than zero
	int checkValidity(int &number)
	{
		while (number < 0)
		{
			cout << "The value must be greater than zero.\n"
				 << "Please enter a value greater than zero. \n >";
			cin >> number;
		}

		return number;
	}

	// Checks that any double input value is greater than zero
	double checkDoubleValidity(double &number)
	{
		while (number < 0)
		{
			cout << "The value must be greater than zero.\n"
				 << "Please enter a value greater than zero. \n >";
			cin >> number;
		}

		return number;
	}
