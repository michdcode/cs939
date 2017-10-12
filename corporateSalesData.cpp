#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct CorpData
{
	string divisionName;
	double q1Sales, q2Sales, q3Sales, q4Sales;

	//Constructor prototypes
	CorpData(); // Default constructor
	CorpData(string divName, double Q1, double Q2, double Q3, double Q4);// Constructor with parameters
};
//Constructor Implementations
CorpData::CorpData(){} // Default
CorpData::CorpData(string divName, double Q1, double Q2, double Q3, double Q4)
{
	divisionName = divName;
	q1Sales = Q1;
	q2Sales = Q2;
	q3Sales = Q3;
	q4Sales = Q4;
}

// Function prototypes for main 
void showCorpData(const CorpData &);

int main()
{
	CorpData east("East", 15, 20, 25, 30);
	CorpData west("West", 150, 200, 250, 300);
	CorpData north("North", 15.58, 135.51, 25.36, 2647.27);
	CorpData south("South", 1671.27, 116.73, 1688.48, 172.45);

	showCorpData(east);
	showCorpData(west);
	showCorpData(north);
	showCorpData(south);

	return 0;
}

void showCorpData(const CorpData &data)
{
	double salesTotal, averageSales; 
	cout << fixed << showpoint << setprecision(2) << endl; 
	cout << "\nFor the " << data.divisionName << " sales are as follows: " << endl;
	salesTotal = data.q1Sales + data.q2Sales + data.q3Sales + data.q4Sales;
	cout << "The total annual sales are $" << salesTotal << endl;
	averageSales = salesTotal / 4;
	cout << "The total average sales are $" << averageSales << endl;
}

