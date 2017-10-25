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
		string dailyReport();
		double inputMoney(double); 
		bool checkInventory(string); // helper returns T/F if there is enough soda
		bool validateMoney(double); // helper returns T/F is enough money
		double returnMoney(double); // helper returns all money paid
		string checkDrinkType(string); // helper returns a valid drink choice
		void updateInventory(string); // helper updates inventory of type of soda
		void updateMoney(double); // helper updates total money collected


	public:
		// variables, constants, structures
		double totalCollected, consumerPaid;
		const int NUM_DRINKS = 5; 
		// Array of 5 structures initalized with drink data
		DrinkInfo drink[NUM_DRINKS] = {
			DrinkInfo('Cola', 1.00, 20),
			DrinkInfo('RootBeer', 1.00, 20),
			DrinkInfo('Orange', 1.00, 20),
			DrinkInfo('Grape', 1.00, 20),
			DrinkInfo('BottledWater', 1.50, 20)
		};
		// function prototypes
		string displayChoices();
		string buyDrink(string);

};