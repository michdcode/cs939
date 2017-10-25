#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


struct DrinkInfo
{
	const string DRINK_NAME;
	const double DRINK_COST;
	int drinkInventory; 
};


class Soda
{
	private:
		// function prototypes
		bool getInventory(string); // helper returns T/F if there is enough soda
		bool validateMoney(double, string); // helper returns T/F is enough money
		double returnMoney(); // helper returns all money paid
		bool checkDrinkType(string); // helper returns a valid drink choice
		void setInventory(string); // helper updates inventory of type of soda
		void setMoney(double); // helper updates total money collected
		string dailyReport();
		double inputMoney(double); 
		int sodaIndex; 


	public:
		// variables, constants, structures
		double totalCollected, iConsumerPaid;
		const int NUM_DRINKS = 5; 
		string iSodaChoice; 
		// Array of 5 structures initalized with drink data
		DrinkInfo drink[NUM_DRINKS] = {
			DrinkInfo('Cola', 1.00, 20), // drink[0]
			DrinkInfo('RootBeer', 1.00, 20), // drink[1]
			DrinkInfo('Orange', 1.00, 20), // drink[2]
			DrinkInfo('Grape', 1.00, 20), // drink[3]
			DrinkInfo('BottledWater', 1.50, 20) // drink[4]
		};
		// function prototypes
		string displayChoices();
		string buyDrink(string); // calls inputMoney

		// class constructor & destructor
		Soda();
		~Soda();
};

// member function implementation section
/************************************************************************************
*								Soda Default constructor							*
************************************************************************************/
Soda::Soda()
{

}

/************************************************************************************
*								Soda Deconstructor									*
************************************************************************************/
Soda::~Soda()
{
	dailyReport();
}

// private functions
/************************************************************************************
*								Soda::getInventory									*
* Helper function returns T/F if there is enough of the soda selected in inventory  *
************************************************************************************/
bool Soda::getInventory(string iSoChoice) // FIX THIS TO BE AN INDEX
{
	switch (iSoChoice;)
	{
		case 'Cola':
			sodaIndex = 0;
			break;
		case 'RootBeer':
			sodaIndex = 1;
			break;
		case 'Orange':
			sodaIndex = 2;
			break;
		case 'Grape':
			sodaIndex = 3;
			break; 
		case 'BottledWater':
			sodaIndex = 4; 
			break;
		deafult:
			cout << "Problem - no drink type exists."
	}

	if (drink[sodaIndex].inventory == 0)
		return false;
	else
		return true;
}

/************************************************************************************
*								Soda::validateMoney									*
* Helper function returns T/F if there is enough money paid 						*
************************************************************************************/
bool Soda::validateMoney(double iConsPaid, string iSoChoice)
{
	if (iSoChoice == 'BottledWater' && iConsPaid => 1.50)
		return true;
	else if(iConsPaid => 1.00 && iSoChoice == 'Cola' || iSoChoice == 'RootBeer' || iSoChoice == 'Orange' || iSoChoice == 'Grape')
		return true;
	else
		return false; 
}

/************************************************************************************
*								Soda::returnMoney									*
* Helper function that returns all of the money that the consumer paid				*
************************************************************************************/
double Soda::returnMoney()
{
	cout << "\nReturning all of the money you paid: $" << iConsumerPaid;
} 

/************************************************************************************
*								Soda::checkDrinkType								*
* Helper function to make sure that there is a soda in inventory for the type of	*
* soda the consumer selected.								 						*
************************************************************************************/
bool Soda::checkDrinkType(string iSodaChoice) 
{
	if (iSodaChoice == 'Cola' || iSodaChoice == 'RootBeer' || iSodaChoice == 'Orange' || iSodaChoice == 'Grape' || iSodaChoice =="BottledWater")
		return true;
	else 
	{ // make sure that when this is called, it goes back to the original point in program.
		cout << "\nThat is not a valid drink selection.";
		cout << "Please choose a valid drink selection.";
		displayChoices();
	}
}

/************************************************************************************
*								Soda::setInventory									*
* Helper function to update inventory for the type of soda the consumer selected.	*								 						*
************************************************************************************/
void Soda::setInventory(string iSodaChoice)
{
	drink[iSodaChoice].inventory--;
}

/************************************************************************************
*								Soda::setMoney										*
* Helper function to update total amount of money collected.						*
* need to check & make sure only adds actual amount needed for drink & not overage	*								 						*
************************************************************************************/
void Soda::setMoney(double iConsumerPaid)
{
	totalCollected = totalCollected + iConsumerPaid;
}

/************************************************************************************
*								Soda::dailyReport									*
* Lists total amount of money collected.											*								 						*
************************************************************************************/
void Soda::dailyReport()
{
	cout << "\nThe total amount of money collected is: $" << totalCollected;
	cout << "\nThe total remaining in inventory of each drink is: " << endl;
	for (int index = 0; index < NUM_DRINKS; index++)
	{
		cout << drink[index].DRINK_NAME << setw(7) << drink[index].drinkInventory << endl;
	}
}

/************************************************************************************
*								Soda::inputMoney									*
* Accept, validate & return the amount of money input								*								 						*
************************************************************************************/
double Soda::inputMoney()
{
	cout << "\nAll sodas are $1.00, and bottled water is $1.50";
	cout << "\nPlease enter the amount of money you are paying > $";
	cin >> iConsumerPaid; 
	validateMoney(iConsumerPaid, iSodaChoice); 

}



