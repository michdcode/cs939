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

		string getDepartmentName()
		{	return Departmentname;	}

		string getDepartmentHeadName()
		{	return DepartmentHeadName;	}

		// Mutator functions definitions - inline because they are short
		void setDeptID(int iID)
		{	DepartmentID = iID;	}

		void setDeptName(string iDeptName)
		{	Departmentname = iDeptName; }

		void setDeptHead(string iDeptHead)
		{	DepartmentHeadName = iDeptHead; }

};


// Creates an Employee class
class Employee
{	private:
		int employeeID;
		int employeeAge;
		int employeeDepartmentID;
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
			setEmpAge(userEmpAge);
			setEmpDeptID(userEmpDeptID);
			setEmpSal(userEmpSalary);
			setEmpName(userEmpName);
		}
		// Accessor functions
		int getEmpID()
		{ 	return employeeID; }

		int getEmployeeAge()
		{ 	return employeeAge; }

		int getEmployeeDepartmentID()
		{ 	return employeeDepartmentID; }

		double getEmployeeSalary()
		{	return employeeSalary;	}

		string getEmployeeName()
		{	return employeeName;	}

		// Mutator functions definitions - inline because they are shorter
		void setEmpID(int iEID)
		{	employeeID = iEID;	}

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
void getEmployeeData(int&, int&, int&, double&, string&, int, vector<int>&, vector<int>);
void getDepartmentData(int&, string&, string&, int, vector<int>&);
bool checkEmployeeID(int&, bool&, vector<int>);
bool checkDepartmentID(int&, bool&, vector<int>);
void writeDeptAndEmpArraysToFile(Department[], Employee[], ofstream&, ofstream&, int, int);
void readDeptAndEmpArraysFromFile(Department[], Employee[], ifstream&, ifstream&, string, string, int, int);
void displayArraysAndSalaries(Department[], Employee[], int, int);


int main()
{
	// Create two arrays, one for employee with size 7, and one for department with size 3
	const int NUM_EMPS = 7;
	const int NUM_DEPT = 3;
	Employee myEmploys[NUM_EMPS];// array is myEmploys with type employees objects
	Department myDeparts[NUM_DEPT];// array is myDepartment with type department objects
	vector<int> deptIdNums; // vector to hold all of the department ID's
	vector<int> empIdNums; // vector to hold all of the employee ID's
	double tSal;
	string tName, tDN, tDHN, dDI, eDI;
	ofstream deptArrayFile;
	ofstream empArrayFile;
	ifstream deptDataIn;
	ifstream empDataIn;
	int deptCount = 0, empCount = 0; 
	int choice, tID, tAge, tEDID, tDID;

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
						Department newestDepartment(tDID, tDN, tDHN); // create new department
						myDeparts[deptCount] = newestDepartment; // add employee to array
						deptIdNums.push_back(tDID); // add deptID to dept vector
						deptCount ++; // increase employee count 
						break;
				case 2: getEmployeeData(tID, tAge, tEDID, tSal, tName, empCount, empIdNums, deptIdNums);
						Employee newestEmployee(tID, tAge, tEDID, tSal, tName);
						myEmploys[empCount] = newestEmployee;
						empIdNums.push_back(tID);  
						empCount ++;// increase count of employees in array
						break;
				case 3: writeDeptAndEmpArraysToFile(myDeparts, myEmploys, deptArrayFile, empArrayFile, deptCount, empCount);
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
				case 5: displayArraysAndSalaries(myDeparts, myEmploys, empCount, deptCount);
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
void getEmployeeData(int &fID, int &fAge, int &fEDID, double &fSal, string &fName, int numb, vector<int> &fEmpIdNums, vector <int> fDeptIdNums)
{
	bool Evalid = false, EDvalid = false;
	fAge = 0;
	fSal = 0; 
	fName = "";

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
			cout << "\nEnter the employee's salary: $ "; 
			cin >> fSal;
			if (fSal == 0)
				cout << "\nThe salary cannot be 0.";
		}
		
		// Get a valid name
		while (fName == "")
		{
			cout << "\nEnter the employee's name: ";
			cin.get();
			getline(cin, fName);
			if (fName == "") 
				cout << "\nThe name cannot contain an empty string.";
		}
	}
}

/************************************************************************
*						checkEmployeeID									*
*	This function makes sure employee ID's are unique					*
************************************************************************/
bool checkEmployeeID(int &cID, bool &EID, vector<int> empIDN)
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
bool checkDepartmentID(int &cDID, bool &ED, vector<int> fDepIdNums)
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
void getDepartmentData(int &fDID, string &fDN, string &fDHN, int num, vector<int> fDeIdNums)
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
			cin >> fDID;
			checkDepartmentID(fDID, EDvalid, fDeIdNums);
		}

		// Get a valid Department name
		while (fDN == "")
		{
			cout << "\nEnter the Department name: ";
			cin.get();
			getline(cin, fDN);
			if (fDN == "") 
				cout << "\nThe name cannot contain an empty string.";
		}

		// Get a valid Department head name
		while (fDHN == "")
		{
			cout << "\nEnter the Department head's name: ";
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
void writeDeptAndEmpArraysToFile(fDeparts[], fEmploys[], ofstream &fDepArrFile, ofstream &fEmpArrFile, int fDcount, int fEcount)
{
	//Write Department Array to a file
	cout << "\nFirst, save the Department array to a file.";
	fDepArrFile.open("DepartmentArray.txt");
	for (int i = 0; i < fDcount; i++)
		fDepArrFile << fDeparts[i]; //fDeparts is an int? 
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
void readDeptAndEmpArraysFromFile(fDeparts[], fEmploys[], ifstream &fDepFile, ifstream &fEmpFile, string fEmpFileName, string fDeptFileName, int fDcount, int fEcount)
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
		fDepFile.close(fDeptFileName);
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
		fEmpFile.close(fEmpFileName);
	}
	cout << "Done reading data from both files into the arrays.";
}

/************************************************************************
*					displayArraysAndSalaries							*
*	This function displays the arrays & salary by department.			*
************************************************************************/
void displayArraysAndSalaries(depArray[], empArray[], int nemps, int ndept)
{
	// initialize a few variables
	int dept1 = -1, dept2 = -1, dept3 = -1, j = 1, i;
	double sal1 = 0.0, sal2 = 0.0, sal3 = 0.0;
	const int PAIRS = 7;
	double deptSalaryPairs[PAIRS][PAIRS];

	// Display Employee Array
	if (nemps == 0)
		cout << "\nThe Employee Array is empty.";
	else
	{
		cout << "\nHere is the content of the Employee Array";
		for (i = 0; i < nemps; i++)
			{
				cout << "\nEmployee Array item number " << i << endl;
				cout << "Employee ID number: " << empArray[i].getEmpID() << endl;
				cout << "Employee Age: " << empArray[i].getEmployeeAge() << endl;
				cout << "Employee Department ID: " << empArray[i].getEmployeeDepartmentID() << endl;
				cout << "Employee Salary: " << empArray[i].getEmployeeSalary() << endl;
				cout << "Employee Name: " << empArray[i].getEmployeeName() << endl;
			}
	}
	// Display Department Array 
	if (ndept == 0) 
		cout << "\nThe Department Array is empty.";
	else 
	{
		cout << "\nHere is the content of the Departments Array";
		for (i = 0; i < ndept; i++)
			{
				cout << "\nDepartment Array item number " << i << endl;
				cout << "Department ID number: " << depArray[i].getDepartmentID() << endl;
				cout << "Department Name: " << depArray[i].getDepartmentName() << endl;
				cout << "Department Head Name: " << depArray[i].getDepartmentHeadName() << endl;
			}	
	}
	// Gather department information
	for (i = 0; i < ndept; i++)
		{
			deptArray[j] = depArray[i].getDepartmentID; //set variable dept1 = first department ID number
			j++;
		}
	// Put employee department and salary into pairs
	j = 0; 
	for (i = 0; i < nemps; i++)
		{
			deptSalaryPairs[i][j] = empArray[i].getEmployeeDepartmentID();
			deptSalaryPairs[i][j + 1] = empArray[i].getEmployeeSalary();
			j++; 
		}
	// Loop through employee array pairs, and total salaries by department
	for (i = 0; i < nemps; i ++)
		{
			if (dept1 == deptSalaryPairs[i][j])
				sal1 = sal1 + deptSalaryPairs[i][j + 1];
			else if (dept2 == deptSalaryPairs[i][j])
				sal2 = sal2 + deptSalaryPairs[i][j + 1];
			else
				sal3 = sal3 + deptSalaryPairs[i][j + 1];
		}
	// Display salaries by department
	cout << "\nFor department number " << dept1 << " The total salaries are: $" << sal1;
	cout << "\nFor department number " << dept2 << " The total salaries are: $" << sal2;
	cout << "\nFor department number " << dept3 << " The total salaries are: $" << sal3;
}





