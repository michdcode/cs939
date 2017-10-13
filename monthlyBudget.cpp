#include <iostream>
using namespace std; 

// Monthly Budget Structure
struct MonthlyBudget
{
	double housing;
	double utilities;
	double householdExpenses;
	double transportation;
	double food;
	double medical;
	double insurance;
	double entertainment;
	double clothing;
	double miscellaneous;
    
    MonthlyBudget(double h, double u, double hE, double t, double f, double m, double i, double e, double c, double misc)
    {
        housing = h;
        utilities = u;
        householdExpenses = hE;
        transportation = t;
        food = f;
        medical = m;
        insurance = i;
        entertainment = e;
        clothing = c;
        miscellaneous = m;
    };
};

// function prototypes for main 

double getTotal(const MonthlyBudget &, const MonthlyBudget &);
MonthlyBudget getActualExpenses(MonthlyBudget &);

int main()
{
	// Define variables
	
	double h, u, ho, c, e, he, i, f, cl, m;
	
	// Instantiate structure variable with budgeted amounts in problem
	MonthlyBudget budgeted(500.00, 150.00, 65.00, 50.00, 250.00, 30.00, 100.00, 150.00, 75.00, 50.00);
	
	// Figure out total amount over or under budget
	MonthlyBudget temp = getActualExpenses(budgeted);

	// Display results
	cout << "\n Here are the results of your budget for the month.\n";
	cout << "\n If a number is negative, then you spent more than budgeted.\n";
	h = budgeted.housing - temp.housing;
	cout << "Housing: $" << h << endl;
	u = budgeted.utilities - temp.utilities;
	cout << "Utilities: $" << u << endl;
	ho = budgeted.householdExpenses - temp.householdExpenses;
	cout << "Household Expenses: $" << ho << endl;
	c = budgeted.transportation - temp.transportation;
	cout << "Transportation: $" << c << endl;
	e = budgeted.food - temp.food;
	cout << "Food: $" << e << endl;
	he = budgeted.medical - temp.medical;
	cout << "Medical: $" << he << endl;
	i = budgeted.insurance - temp.insurance;
	cout << "Insurance: $" << i << endl;
	f = budgeted.entertainment - temp.entertainment;
	cout << "Entertainment: $" << f << endl;
	cl = budgeted.clothing - temp.clothing;
	cout << "Clothing: $" << cl << endl;
	m = budgeted.miscellaneous - temp.miscellaneous;
	cout << "Miscellaneous: $" << m << endl;
	cout << "*****************************************" << endl;
	cout << "Overall, the difference between budgeted & actual is: $" << getTotal(budgeted, temp) << endl; 


	return 0;
}
double getTotal(const MonthlyBudget &budgeted, const MonthlyBudget &temp)
	{
		double budTotal, actTotal, diff;
		budTotal = budgeted.housing + budgeted.utilities + budgeted.householdExpenses + budgeted.transportation + budgeted.food + budgeted.medical + budgeted.insurance + budgeted.entertainment + budgeted.clothing + budgeted.miscellaneous;
		actTotal = temp.housing + temp.utilities + temp.householdExpenses + temp.transportation + temp.food + temp.medical + temp.insurance + temp.entertainment + temp.clothing + temp.miscellaneous;
		diff = budTotal - actTotal;
		return diff;
	}

// Obtain user amount actually spent during past month
MonthlyBudget getActualExpenses(MonthlyBudget &budgeted)
{
    double house, utility, housExp, car, eat, health, ins, fun, clothes, miscell; 
    cout << "You will now enter the actual amounts that you spent in each category.\n"
         << "The category and budgeted amount will appear, and then you will be \n"
         << "Prompted to enter the actual amount spent.\n";
    cout << "Housing: 	Budgeted: $" << budgeted.housing << "Enter actual amount: $";
    cin  >> house;
    cout << "\nUtilities: 	Budgeted: $" << budgeted.utilities << "Enter actual amount: $";
    cin  >> utility;
    cout << "\nHousehold Expenses: 	Budgeted: $" << budgeted.householdExpenses << "Enter actual amount: $";
    cin  >> housExp;
    cout << "\nTransportation: 	Budgeted: $" << budgeted.transportation << "Enter actual amount: $";
    cin  >> car;
    cout << "\nFood: 	Budgeted: $" << budgeted.food << "Enter actual amount: $";
    cin  >> eat;
    cout << "\nMedical: 	Budgeted: $" << budgeted.medical << "Enter actual amount: $";
    cin  >> health;
    cout << "\nInsurance: 	Budgeted: $" << budgeted.insurance << "Enter actual amount: $";
    cin  >> ins;
    cout << "\nEntertainment: 	Budgeted: $" << budgeted.entertainment << "Enter actual amount: $";
    cin  >> fun;
    cout << "\nClothes: 	Budgeted: $" << budgeted.clothing << "Enter actual amount: $";
    cin  >> clothes;
    cout << "\nMiscellaneous: 	Budgeted: $" << budgeted.miscellaneous << "Enter actual amount: $";
    cin  >> miscell;
        // Instantiate structure variable with actual amounts entered by user
    MonthlyBudget actual(house, utility, housExp, car, eat, health, ins, fun, clothes, miscell);
    return actual;
}
