// Budget.h contains the structure for the budget items
#ifndef MONTHLYBUDGET_H
#define MONTHLYBUDGET_H

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

	// Constructor Prototypes
	MonthlyBudget(); // Default constructor 
	MonthlyBudget(double h, double u, double hE, double t, double f, double m, double i, double e, double c, double misc);
};
#endif