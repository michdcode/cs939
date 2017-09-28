#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main ()
{// Initialize variables
	ifstream inputFile;
	double rainfallSum, avgRainfall, rainfall;
	int months=0;
	string begMonth, endMonth;

	// Open the input file & determine if it works
	cout << "Attempting to open input file. \n";
	inputFile.open("rainfall.txt");
	if (inputFile) 
	{
		cout << "Success opening file. Reading months. \n";
		inputFile >> begMonth;
		inputFile >> endMonth;
		
		// loop to obtain the rainfall totals
		while(inputFile >> rainfall)
		{
			months++;
			rainfallSum = rainfallSum + rainfall;
		}
		cout <<"Done reading months. Will now close file.\n";
		inputFile.close();
		// Calculate the average rainfall
		avgRainfall = (rainfallSum / months);
		
		// Display results 
		cout <<"During the months of " << begMonth << " - "
			 << endMonth << " the total rainfall was "
			 << rainfallSum << " inches and the average\n"
			 << "monthly rainfall was " << avgRainfall 
			 << " inches.\n";
	}
	else
	{
		cout << "Error opening file.\n";
	}
	return 0;
}