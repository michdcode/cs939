#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


struct DrinkInfo
{
	string drinkName;
	double drinkCost;
	int drinkInventory; 

	DrinkInfo(string n = "", double c = 1.00, int i = 20)
	{
		drinkName = n;
		drinkCost = c;
		drinkInventory = i;
	}
};


class Soda
{
	private:
		// function prototypes
		bool getInventory(string); // helper returns T/F if there is enough soda
		// bool validateMoney(double); // helper returns T/F is enough money
		double returnMoney(); // helper returns all money paid
		void updateInventory(); // helper updates inventory of type of soda
		void updateMoney(double); // helper updates total money collected
		void dailyReport();
		double inputMoney(); 

	public:
		// variables, constants, structures
		double totalCollected, iConsumerPaid;
		static const int NUM_DRINKS = 5; 
		string iSodaChoice; 
		int index, sodaIndex; 
		// Array of 5 structures initalized with drink data
		DrinkInfo drink[NUM_DRINKS] = {
			DrinkInfo("Cola", 1.00, 20), // drink[0]
			DrinkInfo("RootBeer", 1.00, 20), // drink[1]
			DrinkInfo("Orange", 1.00, 20), // drink[2]
			DrinkInfo("Grape", 1.00, 20), // drink[3]
			DrinkInfo("BottledWater", 1.50, 20) // drink[4]
		};
		// function prototypes
		void displayChoices();
		bool checkDrinkType(string); // helper returns a valid drink choice
		void buyDrink(string); // calls inputMoney

		// class constructor & destructor
		Soda();
		~Soda();
};

// member function implementation section
/************************************************************************************
*								Soda Default constructor							*
***********************************************************************************/
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
bool Soda::getInventory(string iSoChoice) // 
{
	{
	if (iSoChoice == "Cola")
		sodaIndex = 0;	
	else if (iSoChoice == "RootBeer")
		sodaIndex = 1;
	else if (iSoChoice == "Orange")
		sodaIndex = 2;
	else if (iSoChoice == "Grape")
		sodaIndex = 3;
	else if (iSoChoice == "BottledWater")		
		sodaIndex = 4;
	} 
	if (drink[sodaIndex].drinkInventory == 0)
		return false;
	else
		return true;
}

/************************************************************************************
*								Soda::validateMoney		 							*
* Helper function returns T/F if there is enough money paid 						*
************************************************************************************/
// // may have to add soda choice as a parameter
// bool Soda::validateMoney(double iConsPaid)
// {
// 	if (iSodaChoice == "BottledWater" && iConsPaid >= 1.50)
// 		return true;
// 	else if (iConsPaid >= 1.00 && (iSodaChoice == "Cola" || iSodaChoice == "RootBeer" || iSodaChoice == "Orange" || iSodaChoice == "Grape"))
// 		return true;
// 	else
// 		return false; 
// }

/************************************************************************************
*								Soda::returnMoney									*
* Helper function that returns all of the money that the consumer paid				*
************************************************************************************/
double Soda::returnMoney()
{
	cout << "\nReturning all of the money you paid: $" << iConsumerPaid;
} 

/************************************************************************************
*								Soda::updateInventory								*
* Helper function to update inventory for the type of soda the consumer selected.	*								 						
************************************************************************************/
void Soda::updateInventory()
{
	drink[sodaIndex].drinkInventory--;

}

/************************************************************************************
*								Soda::updateMoney									*
* Helper function to update total amount of money collected.						*
* need to check & make sure only adds actual amount needed for drink & not overage	*								 						
************************************************************************************/
void Soda::updateMoney(double iConsumerPaid)
{
	totalCollected = totalCollected + iConsumerPaid;
}

/************************************************************************************
*								Soda::dailyReport									*
* Lists total amount of money collected.											*								 						
************************************************************************************/
void Soda::dailyReport()
{
	cout << "\nThe total amount of money collected is: $" << totalCollected;
	cout << "\nThe total remaining in inventory of each drink is: " << endl;
	for (index = 0; index < NUM_DRINKS; index++)
	{
		cout << drink[index].drinkName << setw(7) << drink[index].drinkInventory << endl;
	}
}

/************************************************************************************
*								Soda::inputMoney									*
* Accept, validate & return the amount of money input.								*								 						
************************************************************************************/
double Soda::inputMoney()
{
	//accept money paid 
	cout << "\nAll sodas are $1.00, and bottled water is $1.50";
	cout << "\nPlease enter the amount of money you are paying."
		 << "\nPlease use the decimal point in your entry. > $";
	cin >> iConsumerPaid; 
	
	//validate amount paid & return amount paid 
	if (iSodaChoice == "BottledWater" && iConsumerPaid >= 1.50)
		return iConsumerPaid;
	else if (iConsumerPaid >= 1.00 && (iSodaChoice == "Cola" || iSodaChoice == "RootBeer" || iSodaChoice == "Orange" || iSodaChoice == "Grape"))
		return iConsumerPaid;
	else
	 {	while ((iSodaChoice == "BottledWater" && iConsumerPaid <= 1.50) || iConsumerPaid <= 1.00 && (iSodaChoice == "Cola" || iSodaChoice == "RootBeer" || iSodaChoice == "Orange" || iSodaChoice == "Grape"))
		{
			cout << "\nYou did not pay enough money.";
			cout << "\nAll sodas are $1.00, and bottled water is $1.50";
			cout << "\nPlease enter the TOTAL amount of money you are paying."
				 << "\nPlease use the decimal point in your entry. > $";
			cin >> iConsumerPaid;
	}
	return iConsumerPaid;
}
}

/************************************************************************************
*								Soda::displayChoices								*
* List the different types of drinks available.				 						*
************************************************************************************/
void Soda::displayChoices()
{
	for (index = 0; index < NUM_DRINKS; index++)
	{
		cout << setw(15) << drink[index].drinkName << " $" << showpoint << setprecision(3) << drink[index].drinkCost << endl;
	}
}

/************************************************************************************
*								Soda::checkDrinkType								*
* Helper function to make sure that there is a soda in inventory for the type of	*
* soda the consumer selected.								 						*
************************************************************************************/
bool Soda::checkDrinkType(string iSodaChoice) 
{
	if (iSodaChoice == "Cola" || iSodaChoice == "RootBeer" || iSodaChoice == "Orange" || iSodaChoice == "Grape" || iSodaChoice =="BottledWater")
		return true;
	else 
		{ 
			cout << "\nThat is not a valid drink selection." << endl;
			displayChoices();
			cout << "\nPlease choose a valid drink selection. >";
			cin >> iSodaChoice; // THIS IS NOT
			return true; 
		}
}
/************************************************************************************
*								Soda::buyDrink										*
* Calls inputMoney											 						*
************************************************************************************/
void Soda::buyDrink(string iSoChoice)
{
	string stillWant;
	double changeDue; 
	inputMoney(); // a double will come back from this function call 
	cout << "\nDo you still want to buy " << iSoChoice << "?" << endl;
	cout << "If so, please type YES  > ";
	cin >> stillWant;
	if (stillWant != "YES")
	{
		returnMoney();
	}
	else if (!(getInventory(iSoChoice)))
	{
		cout << "\nThere are no more of " << iSoChoice << " in inventory." << endl;
		cout << "I will return your money.";
		returnMoney();
	}
	else 
	{
		// money already validated during inputMoney function call
		updateInventory();
		updateMoney(drink[sodaIndex].drinkCost);
		changeDue = iConsumerPaid - drink[sodaIndex].drinkCost;
		if (changeDue > 0) 
			cout << "\nHere is your change: $" << changeDue;
		cout << "\nHere is your beverage.";
	}
}


int main()
{
	// instantiate a soda object 
	Soda consumer;
	int answer = 1; 
	int response; 

	// explain program & display drink options 
	cout << "\nThis program simulates a soda and water vending machine." << endl;
	while (answer == 1)
	{
		consumer.displayChoices();
		cout << "\nPlease type the name of the drink you would like. "
				"\nPlease use the exact name of the drink as shown above. > ";
		cin >> consumer.iSodaChoice;
		consumer.checkDrinkType(consumer.iSodaChoice);
		consumer.buyDrink(consumer.iSodaChoice);
		cout << "\nDo you want to purchase another drink?" 
			 << "\nType 1 to purchase another drink."
			 << "\nType anything else to exit. > ";
		cin >> response; 
		if (response != 1)
			break;
	}
	
	return 0; 
}
