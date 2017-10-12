#include <iostream>
#include "budget.h"
using namespace std; 


double getTotal(MonthlyBudget, MonthlyBudget);
void getActualExpenses();


int main()
{
	// Define variables
	double house, utility, housExp, car, eat, health, ins, fun, clothes, miscell; 
	double h, u, ho, c, e, he, i, f, cl, m;
	
	// Instantiate structure variable with budgeted amounts in problem
	MonthlyBudget budgeted(500.00, 150.00, 65.00, 50.00, 250.00, 30.00, 100.00, 150.00, 75.00, 50.00);
	
	// Figure out total amount over or under budget
	double getTotal(const MonthlyBudget &, const MonthlyBudget &)
	{
		double budTotal, actTotal, diff;
		budTotal = bud.housing + bud.utilities + bud.householdExpenses + bud.transportation + bud.food + bud.medical + bud.insurance + bud.entertainment + bud.clothing + bud.miscellaneous;
		actTotal = act.housing + act.utilities + act.householdExpenses + act.transportation + act.food + act.medical + act.insurance + act.entertainment + act.clothing + act.miscellaneous;
		diff = budTotal - actTotal;
		return diff;
	}

	// Obtain user amount actually spent during past month
	void getActualExpenses()
	{
		cout << "You will now enter the actual amounts that you spent in each category.\n"
			 << "The category and budgeted amount will appear, and then you will be \n"
			 << "Prompted to enter the actual amount spent.\n";
		cout << "Housing: 	Budgeted: $" << budgeted.housing << "Enter actual amount: $"
		cin  >> house;
		cout << "\nUtilities: 	Budgeted: $" << budgeted.utilities << "Enter actual amount: $"
		cin  >> utility;
		cout << "\nHousehold Expenses: 	Budgeted: $" << budgeted.householdExpenses << "Enter actual amount: $"
		cin  >> housExp;
		cout << "\nTransportation: 	Budgeted: $" << budgeted.transportation << "Enter actual amount: $"
		cin  >> car;
		cout << "\nFood: 	Budgeted: $" << budgeted.food << "Enter actual amount: $"
		cin  >> eat;
		cout << "\nMedical: 	Budgeted: $" << budgeted.medical << "Enter actual amount: $"
		cin  >> health;
		cout << "\nInsurance: 	Budgeted: $" << budgeted.insurance << "Enter actual amount: $"
		cin  >> ins;
		cout << "\nEntertainment: 	Budgeted: $" << budgeted.entertainment << "Enter actual amount: $"
		cin  >> fun;
		cout << "\nClothes: 	Budgeted: $" << budgeted.clothing << "Enter actual amount: $"
		cin  >> clothes;
		cout << "\nMiscellaneous: 	Budgeted: $" << budgeted.miscellaneous << "Enter actual amount: $"
		cin  >> miscell;
	}

	// Instantiate structure variable with actual amounts entered by user
	MonthlyBudget actual(house, utility, housExp, car, eat, health, ins, fun, clothes, miscell);

	// Display results
	cout << "\n Here are the results of your budget for the month.\n";
	cout << "\n If a number is negative, then you spent more than budgeted.\n";
	h = budgeted.housing - actual.housing;
	cout << "Housing: $" << h << endl;
	u = budgeted.utilities - actual.utilities;
	cout << "Utilities: $" << u << endl;
	ho = budgeted.householdExpenses - actual.householdExpenses;
	cout << "Household Expenses: $" << ho << endl;
	c = budgeted.transportation - actual.transportation;
	cout << "Transportation: $" << c << endl;
	e = budgeted.food - actual.food;
	cout << "Food: $" << e << endl;
	he = budgeted.medical - actual.medical;
	cout << "Medical: $" << he << endl;
	i = budgeted.insurance - actual.insurance;
	cout << "Insurance: $" << i << endl;
	f = budgeted.entertainment - actual.entertainment;
	cout << "Entertainment: $" << f << endl;
	cl = budgeted.clothing - actual.clothing;
	cout << "Clothing: $" << cl << endl;
	m = budgeted.miscellaneous - actual.miscellaneous;
	cout << "Miscellaneous: $" << m << endl;
	cout << "*****************************************" << endl;
	cout << "Overall, the difference between budgeted & actual is: $" << getTotal(budgeted, actual) << endl; 


	return 0;
}




