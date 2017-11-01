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
			
		}

		void setDeptName(string iDeptName)
		{	Departmentname = iDeptName; }

		void setCost(string iDeptHead)
		{	DepartmentHeadName = iDeptHead; }

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
			setEmpID(userEmpID);	// Constants and variables
	int choice, tID, tAge, tEDID, tDID, tDN;
	double tSal; 

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
			
		}

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
void getEmployeeData(int&, int&, int&, double&, string&, int, vector&, vector);
void getDepartmentData(int&, string&, string&, int, vector&);
bool checkEmployeeID(int&, bool&, vector);
bool checkDepartmentID(int&, bool&, vector);
void writeDeptAndEmpArraysToFile(Department, Employee, ofstream&, ofstream&, int, int);
void readDeptAndEmpArraysFromFile(Department, Employee, ifstream&, ifstream&, string, string, int, int);



int main()
{
	// Create two arrays, one for employee with size 7, and one for department with size 3
	const int NUM_EMPS = 7;
	const int NUM_DEPT = 3;
	Employee myEmploys[NUM_EMPS];
	Department myDeparts[NUM_DEPT];
	vector<int> deptIdNums; // vector to hold all of the department ID's
	// vector to hold all of the employee ID's & employee salaries
	vector<int> empIdNums;
	vector<int> salaryData;

	int tDID, tID, tAge, tEDID;
	double tSal;
	string tName, tDN, tDHN, dDI, eDI;
	ofstream deptArrayFile;
	ofstream empArrayFile;
	ifstream deptDataIn;
	ifstream empDataIn;
	int deptCount = 0, empCount = 0; 

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
				case 1: getDepartmentData(tDID, tDN, tDHN, deptCount, deptIdNums);
						myDeparts[deptCount](tDID, tDN, tDHN);
						deptIdNums.push_back(tDID); 
						deptCount ++;
						break;
				case 2: getEmployeeData(tID, tAge, tEDID, tSal, tName, empCount, empIdNums, deptIdNums);
						// add employee to employee array
						// if the line above doesn't create a new employee object in the array 
						// at the specified location, try setEmpID(myEmploys[empCount]) - p576
						// or myEmploys[empCount].setEmpID(tid)
						myEmploys[empCount](tid, tAge, tEDID, tSal, tName);
						empIdNums.push_back(tid);  
						salaryData.push_back(tSal);
						// increase count of employees in array
						empCount ++;
						break;
				case 3: writeDeptAndEmpArraysToFile(myDeparts, myEmploys, deptArrayFileFull, empArrayFileFull, deptCount, empCount);
						break;
				case 4: cout << "\nPlease enter the complete name of the file with the Employee data." << endl;
						cout << "\nPlease make sure to enter the file extension. For example: " <<endl;
						cout << "\nMyEmployeeData.txt -- Enter the file name: >";
						// cin.get();
						getline(cin, dDI);
						cout << "\nPlease enter the complete name of the file with the Department data." << endl;
						cout << "\nPlease make sure to enter the file extension. For example: " <<endl;
						cout << "\nMyDepartmentData.txt -- Enter the file name: >";
						// cin.get();
						getline(cin, eDI);
						readDeptAndEmpArraysFromFile(myDeparts, myEmploys, deptDataIn, empDataIn, dDI, eDI, NUM_EMPS, NUM_DEPT);
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
void getEmployeeData(int &fID, int &fAge, int &fEDID, double &fSal, string &fName, int numb, vector &fEmpIdNums, vector fDeptIdNums)
{
	bool Evalid = false, EDvalid = false;
	fAge = 0;
	fSal = 0; 
	fName = ""

	if (numb > 6) 
		cout << "The array is full, you can not add any more Employees.";
	else 
	{
		// Get a valid Employee ID number
		while (Evalid == false) 
		{
			cout << "\nEnter the Employee's ID number: ";
			cin >> fID;
			checkEmployeeID(fID, Evalid, fEmpIdNums);
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
			checkDepartmentID(fEDID, EDvalid, fDeptIdNums);
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
bool checkEmployeeID(int &cID, bool &EID, vector empIDN)
{
	int numcID;
	int local;
	numcID = empIDN.size();
	for (int i = 0; i < numcID; i++)
	{
		local = empIDN.at(i);
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
bool checkDepartmentID(int &cDID, bool &ED, vector fDepIdNums)
{
	int numEID;
	int local; 
	numEID = fDepIdNums.size();
	for (int i = 0; i < numEID; i++)
	{
		local = fDepIdNums.at(i);
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
void getDepartmentData(int &fDID, string &fDN, string &fDHN, int num, vector fDeIdNums)
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
			checkDepartmentID(tDID, EDvalid, fDeIdNums);
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

/************************************************************************
*			readDeptAndEmpArraysFromFile								*
*	This function reads data from two files into two arrays. 			*
************************************************************************/
void readDeptAndEmpArraysFromFile(Department fDeparts, Employee fEmploys, ifstream &fDepFile, ifstream &fEmpFile, fEmpFileName, fDeptFileName, int fDcount, int fEcount)
{
	int count = 0;
	//Read Department data from file into an array
	cout << "\nFirst, read the Department information file into an array.";
	fDepFile.open(fDeptFileName);
	if (!fDepFile)
		cout << "\nError opening data file.";
	else 
	{
		while (count < fDcount && fDepFile >> fDeparts[count])
			count ++;
		fDepFile.close();
	}
	// Read Employee data from file into an array
	count = 0;
	cout << "\nNext, read the Employee information file into an array.";
	fEmpFile.open(fEmpFileName);
	if (!fEmpFile)
		cout << "\nError opening data file.";
	else 
	{
		while (count < fEcount && fEmpFile >> fEmploys[count])
			count ++;
		fEmpFile.close();
	}
	cout << "Done reading data from both files into the arrays.";
}





