// Budget structure function implementation file
#include "Budget.h"

// Constructor Implementations
// Constructor Prototypes
MonthlyBudget::MonthlyBudget(){}; // Default constructor
MonthlyBudget::MonthlyBudget(double h, double u, double hE, double t, double f, double m, double i, double e, double c, double misc)
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
}