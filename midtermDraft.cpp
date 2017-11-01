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
		{	
			employeeID = iEID
			empIdNums.push_back(employeeID); 
		}

		void setEmpAge(int iEmpAge)
		{	employeeAge = iEmpAge; }

		void setEmpDeptID(int iEmpDepID)
		{	employeeDepartmentID = iEmpDepID; }

		void setEmpSal(double iEmpSal)
		{	employeeSalary = iEmpSal;	}

		void setEmpName(string iEmpName)
		{	employeeName = iEmpName;	}

		// vector to hold all of the employee ID's
		vector<int> empIdNums;
};

// function prototypes for main
int getChoice();
void displayMenu();
void getEmployeeData(int&, int&, int&, double&, string&);
void getDepartmentData(int&, string&, string&, int);
bool checkEmployeeID(int&, bool&);
bool checkDepartmentID(int&);
void writeDeptAndEmpArraysToFile(Department, Employee, ofstream&, ofstream&, int, int);



int main()
{
	// Create two arrays, one for employee with size 7, and one for department with size 3
	const int NUM_EMPS = 7;
	const int NUM_DEPT = 3;
	Employee myEmploys[NUM_EMPS];
	Department myDeparts[NUM_DEPT];

	// Constants and variables
	int deptCount = 0;
	int empCount = 0;
	int choice, tID, tAge, tEDID, tDID, tDN;
	double tSal; 
	string tName, tDN, tDHN;
	ofstream deptArrayFile;
	ofstream empArrayFile; 



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
				case 1: getDepartmentData(tDID, tDN, tDHN, deptCount);
						myDeparts[deptCount](tDID, tDN, tDHN);
						deptCount ++;
						break;
				case 2: getEmployeeData(tID, tAge, tEDID, tSal, tName, empCount);
						// add employee to employee array
						// if the line above doesn't create a new employee object in the array 
						// at the specified location, try setEmpID(myEmploys[empCount]) - p576
						// or myEmploys[empCount].setEmpID(tid)
						myEmploys[empCount](tid, tAge, tEDID, tSal, tName);
						// increase count of employees in array
						empCount ++;
						break;
				case 3: writeDeptAndEmpArraysToFile(myDeparts, myEmploys, deptArrayFile, empArrayFile&, deptCount, empCount);
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
	int choice;// may need to set choice to 0, add as param &choice
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
void getEmployeeData(int &fID, int &fAge, int &fEDID, double &fSal, string &fName, int numb)
{
	bool Evalid = false, EDvalid = false;
	fAge = 0;
	fSal = 0; 
	fName = ""

	if (numb > 6) 
	{
		cout << "The array is full, you can not add any more Employees.";
	}
	else 
	{
		// Get a valid Employee ID number
		while (Evalid == false) 
		{
			cout << "\nEnter the Employee's ID number: ";
			cin >> fID;
			checkEmployeeID(fID, Evalid);
		} 

		// Get a valid employee age
		while (fAge < 18)
		{
			cout << "\nEnter the Employee's age: ";
			cin >> fAge;
			if (fAge < 18)
				cout << "Employees must be over 18 years old.";
		}

		// Get a valid Department ID		
		while (EDvalid == false)
		{
			cout << "\nEnter the employee's Department ID: ";
			cin >> fEDID;
			checkDepartmentID(fEDID, EDvalid);
		}

		// Get a valid salary
		while (fSal == 0)
		{
			cout >> "\nEnter the employee's salary: $ "; 
			cin >> fSal;
			if (fSal == 0)
				cout << "\nThe salary cannot be 0.";
		}
		
		// Get a valid name
		while (fName == "")
		{
			cout >> "\nEnter the employee's name: ";
			cin.get();
			getline(cin, fName);
			if (tName == "") 
				cout << "\nThe name cannot contain an empty string.";
		}
	}
}

/************************************************************************
*						checkEmployeeID									*
*	This function makes sure employee ID's are unique					*
************************************************************************/
bool checkEmployeeID(int &cID, bool &EID)
{
	int numcID;
	int local;
	numcID = empIdNums.size();
	for (int i = 0; i < numcID; i++)
	{
		local = empIdNums.at(i);
		if (local == cID)
			{
				cout << "\nThat employee ID is already in use. Please try again.";
				return EID;
			}
	}
	EID = true; 
	return EID; //change to true if issue
}

/************************************************************************
*						checkDepartmentID								*
*	This function makes sure the Department ID exists.					*
************************************************************************/
bool checkDepartmentID(int &cDID, bool &ED)
{
	int numEID;
	int local; 
	numEID = deptIdNums.size();
	for (int i = 0; i < numEID; i++)
	{
		local = deptIdNums.at(i);
		if (local == cDID)
			{
				ED = true;
				return ED; 
			}
	}
	cout << "\nThat department does not exist. Please try again.";
	return ED; // ?return ED valid which is equal to a bool
}

/************************************************************************
*						getDepartmentData								*
*	This function gets data for a department object.					*
************************************************************************/
void getDepartmentData(int &fDID, string &fDN, string &fDHN, int num)
{
	bool EDvalid = false;
	fDN = "";
	fDHN = "";
	if (num > 3) 
	{
		cout << "The array is full, you can not add any more Departments.";
	}
	else 
	{
		// Get a valid Department ID		
		while (EDvalid == false)
		{
			cout << "\nEnter the Department ID: ";
			cin >> tDID;
			checkDepartmentID(tDID, EDvalid);
		}

		// Get a valid Department name
		while (fDN == "")
		{
			cout >> "\nEnter the Department name: ";
			cin.get();
			getline(cin, fDN);
			if (fDN == "") 
				cout << "\nThe name cannot contain an empty string.";
		}

		// Get a valid Department head name
		while (fDHN == "")
		{
			cout >> "\nEnter the Department head's name: ";
			cin.get();
			getline(cin, fDHN);
			if (fDHN == "") 
				cout << "\nThe Department head's name cannot contain an empty string.";
		}
	}
}

/************************************************************************
*					writeDeptAndEmpArraysToFile							*
*	This function writes each array to a separate File.					*
************************************************************************/
void writeDeptAndEmpArraysToFile(Department fDeparts, Employee fEmploys, ofstream &fDepArrFile, ofstream &fEmpArrFile, int fDcount, int fEcount)
{
	//Write Department Array to a file
	cout << "\nFirst, save the Department array to a file.";
	fDepArrFile.open("DepartmentArray.txt");
	for (int i = 0; i < fDcount; i++)
		fDepArrFile << fDeparts[i];
	fDepArrFile.close();
	cout << "\nThe Department array has been saved to a file."
		 << "\nThe name of the file is DepartmentArray.txt";

	//Write Employee Array to a file
	cout << "\nNext, save the Employee array to a file.";
	fEmpArrFile.open("EmployeeArray.txt");
	for (int i = 0; i < fEcount; i++)
		fEmpArrFile << fEmploys[i];
	fEmpArrFile.close();
	cout << "\nThe Employee array has been saved to a file."
		 << "\nThe name of the file is EmployeeArray.txt";
}







