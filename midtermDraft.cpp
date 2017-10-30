#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>

using namespace std;


// Creates a Department class 
class Department
{	private:
		int DepartmentID;
		string Departmentname, DepartmentHeadName;

	public:
		// constructors
		Department() //default
		{
			DepartmentID = 0;
			Departmentname = "";
			DepartmentHeadName = "";
		} 
		Department(int userDeptID, string userDeptName, string userDeptHead)
		{
			setDeptID(userDeptID);
			setDeptName(userDeptName);
			setDeptHead(userDeptHead);
		}
		// Accessor functions
		int getDepartmentID()
		{ 	return DepartmentID; }

		// Mutator functions definitions - inline because they are shorter
		void setDeptID(int iID)
		{	
			DepartmentID = iID;
			deptIdNums.push_back(DepartmentID);
		}

		void setDeptName(string iDeptName)
		{	Departmentname = iDeptName; }

		void setCost(string iDeptHead)
		{	DepartmentHeadName = iDeptHead; }

		// vector to hold all of the department ID's
		vector<int> deptIdNums;
};


// Creates an Employee class
class Employee
{	private:
		int employeeID, employeeAge employeeDepartmentID;
		double employeeSalary; 
		string employeeName;

	public:
		// constructors
		Employee() //default
		{
			employeeID = 0;
			employeeAge = 0;
			employeeDepartmentID = 0;
			employeeSalary = 0.0;
			employeeName = "";
		} 
		Employee(int userEmpID, int userEmpAge, int userEmpDeptID, double userEmpSalary, string userEmpName)
		{
			setEmpID(userEmpID);
			setEmpAge(userEmpAge);
			setEmpDeptID(userEmpDeptID);
			setEmpSal(userEmpSalary);
			setEmpName(userEmpName);
		}
		// // Accessor functions
		// int getItemNumber()
		// { 	return itemNumber; }

		// Mutator functions definitions - inline because they are shorter
		void setEmpID(int iEID)
		{	employeeID = iEID; }

		void setEmpAge(int iEmpAge)
		{	employeeAge = iEmpAge; }

		void setEmpDeptID(int iEmpDepID)
		{	employeeDepartmentID = iEmpDepID; }

		void setEmpSal(double iEmpSal)
		{	employeeSalary = iEmpSal;	}

		void setEmpName(string iEmpName)
		{	employeeName = iEmpName;	}
};

// function prototypes for main
int getChoice();
void displayMenu();
void getEmployeeData(Employee &);
int checkEmployeeID(int);
int checkDepartmentID(int);



int main()
{
	// Create two arrays, one for employee with size 7, and one for department with size 3
	const int NUM_EMPS = 7;
	const int NUM_DEPT = 3;
	Employee myEmploys[NUM_EMPS];
	Department myDeparts[NUM_DEPT];

	// Constants and variables
	int choice;
	int empCount = 0;
	int cID;
	int cDID;

	cout << fixed << showpoint << setprecision(2); //set formatting for numeric output

	// Display menu items and get user selection	
	do
	{
		displayMenu();
		choice = getChoice();
		if (choice != 6) 
		{
			switch(choice)
			{
				case 1: // need to add this
						break;
				case 2: getEmployeeData(Employee &myEmploys[empCount], tID, tAge, tEDID, tSal, tName);
						break;
				case 3: // need to add this
						break;
				case 4: // need to add this
						break;
				case 5: // need to add this
						break;	
			}
		}
	} while (choice != 6);
	return 0;
}

/************************************************************************
*						displayMenu										*
*	This function displays the users menu choices.						*
************************************************************************/
void displayMenu()
{
	cout << "\nPlease make your selection from the menu below:\n\n";
	cout << "1. 	Create a New Department\n";
	cout << "2. 	Create a New Employee\n";
	cout << "3.		Write Data to the File\n";
	cout << "4.		Retrieve Data from File\n";
	cout << "5.		Display Report\n";
	cout << "6.		Quit the program\n\n";
}

/************************************************************************
*						getChoice										*
*	This function gets user choice, validate it and returns it.			*
************************************************************************/
int getChoice()
{
	int choice;
	cin >> choice;
	while (choice < 1 || choice > 6)
	{
		cout << "The only valid choices are 1-6. Please try again.";
		cin >> choice; 
	}
	return choice; 
}

/************************************************************************
*						getEmployeeData									*
*	This function gets data for an employee object.						*
************************************************************************/
void getEmployeeData(Employee &myEmploys[empCount], tID, tAge, tEDID, tSal, tName)
{
	if (empCount > 6) 
	{
		cout << "The array is full, you can not add any more Employees.";
	}
	else 
	{
		cout << "\nEnter the Employee's ID number: ";
		cin >> tID;
		checkEmployeeID(tID); // will ultimately return a valid ID number
		cout << "\nEnter the Employee's age: ";
		cin >> tAge;
		cout << "\nEnter the employee's Department ID: ";
		cin >> tEDID;
		checkDepartmentID(teDID); // will ultimately return a valid Dept
		cout >> "\nEnter the employee's salary: $ "; 
		cin >> tSal;
		cout >> "Enter the employee's name: ";
		cin.get();
		getline(cin, tName);
		myEmploys[empCount](tid, tAge, tEDID, tSal, tName);
		// if the line above doesn't create a new employee object in the array 
		// at the specified location, try setEmpID(myEmploys[empCount]) - p576
		// or myEmployes[empCount].setEmpID(tid)
		empCount ++;
	}
}

/************************************************************************
*						checkEmployeeID									*
*	This function makes sure employee ID's are unique					*
************************************************************************/

int checkEmployeeID(int cID);


/************************************************************************
*						checkDepartmentID								*
*	This function makes sure the Department ID exists.					*
************************************************************************/

int checkDepartmentID(int cDID)
{
	int numEID;
	int local; 
	numEID = deptIdNums.size();
	for (int i = 0; i < num; ++i)
	{
		local = deptIdNums.at(i);
		if (local == cDID)
			return cDID// if the ID exists already return it & continue
	}

	// need to do a function call to get a valid employee ID

	 
}










