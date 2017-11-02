#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// Creates a Department class 
class Department
{	private:
		int departmentID;
		string departmentName, departmentHeadName;

	public:
		// constructors
		Department() //default
		{
			departmentID = 0;
			departmentName = "";
			departmentHeadName = "";
		} 
		Department(int userDeptID, string userDeptName, string userDeptHead)
		{
			setDeptID(userDeptID);
			setDeptName(userDeptName);
			setDeptHead(userDeptHead);
		}
		// Accessor functions - inline because they are short
		int getDepartmentID()
		{ 	return departmentID; }

		string getDepartmentName()
		{	return departmentName;	}

		string getDepartmentHeadName()
		{	return departmentHeadName;	}

		// Mutator functions definitions - inline because they are short
		void setDeptID(int interimDepartmentID)
		{	departmentID = interimDepartmentID;	}

		void setDeptName(string interimDeptName)
		{	departmentName = interimDeptName; }

		void setDeptHead(string interimDeptHead)
		{	departmentHeadName = interimDeptHead; }

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
		void setEmpID(int interimEmployeeID)
		{	employeeID = interimEmployeeID;	}

		void setEmpAge(int interimEmpAge)
		{	employeeAge = interimEmpAge; }

		void setEmpDeptID(int interimEmpDepID)
		{	employeeDepartmentID = interimEmpDepID; }

		void setEmpSal(double interimEmpSalary)
		{	employeeSalary = interimEmpSalary;	}	

		void setEmpName(string interimEmpName)
		{	employeeName = interimEmpName;	}

};

// function prototypes for main
int getChoice();
void displayMenu();
void getEmployeeData(int&, int&, int&, double&, string&, int, vector<int>&, vector<int>);
void getDepartmentData(int&, string&, string&, int, vector<int>&);
bool checkEmployeeID(int&, bool&, vector<int>);
bool checkDepartmentID(int&, bool&, vector<int>);
void writeDeptAndEmpArraysToFile(Department[], Employee[], int, int);
void readDeptAndEmpArraysFromFile(Department[], Employee[]);
void displayArraysAndSalaries(Department[], Employee[], int, int);


int main()
{
	// Create two arrays, one for employee with size 7, and one for department with size 3
	const int NUM_EMPS = 7;
	const int NUM_DEPT = 3;
	Employee employeeArray[NUM_EMPS];// array is employeeArray with type employee objects
	Department departmentArray[NUM_DEPT];// array is departmentArray with type department objects
	vector<int> deptIdNumsVector; // vector to hold all of the department ID's
	vector<int> empIdNumsVector; // vector to hold all of the employee ID's
	double tempSalary;
	string tempEmployeeName, tempDepartmentName, tempDepartmentHead, tempEmployeeDataFileName, tempDepartmentDataFileName;
	int deptCount = 0, empCount = 0; 
	int choice, tempEmployeeID, tempEmployeeAge, tempEmployeeDeptID, tempDepartmentID;

	// Display menu items and get user selection	
	do
	{
		displayMenu();
		choice = getChoice();
		if (choice != 6) 
		{
			switch(choice)
			{
				case 1: 
					{
						getDepartmentData(tempDepartmentID, tempDepartmentName, tempDepartmentHead, deptCount, deptIdNumsVector);
						Department newestDepartment(tempDepartmentID, tempDepartmentName, tempDepartmentHead); // create new department
						departmentArray[deptCount] = newestDepartment; // add employee to array
						deptIdNumsVector.push_back(tempDepartmentID); // add deptID to dept vector
						deptCount ++; // increase employee count 
					}
					break;
				case 2: 
					{
						getEmployeeData(tempEmployeeID, tempEmployeeAge, tempEmployeeDeptID, tempSalary, tempEmployeeName, empCount, empIdNumsVector, deptIdNumsVector);
						Employee newestEmployee(tempEmployeeID, tempEmployeeAge, tempEmployeeDeptID, tempSalary, tempEmployeeName);
						employeeArray[empCount] = newestEmployee;
						empIdNumsVector.push_back(tempEmployeeID);  
						empCount ++;// increase count of employees in array
					}
					break;
				case 3: 
					{
						writeDeptAndEmpArraysToFile(departmentArray, employeeArray, deptCount, empCount);
					}
					break;
				case 4: 
					{	
						readDeptAndEmpArraysFromFile(departmentArray, employeeArray);
					}	
					break;
				case 5: 
					{
						displayArraysAndSalaries(departmentArray, employeeArray, empCount, deptCount);
					}
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
	int funChoice;// may need to set choice to 0, add as param &choice
	cin >> funChoice;
	while (funChoice < 1 || funChoice > 6)
	{
		cout << "The only valid choices are 1-6. Please try again.";
		cin >> funChoice; 
	}
	return funChoice; 
}

/************************************************************************
*						getEmployeeData									*
*	This function gets data for an employee object.						*
************************************************************************/
void getEmployeeData(int &funEmployeeID, int &funEmployeeAge, int &funEmployeeDeptID, double &funSalary, string &funEmployeeName, int funEmployeeArrayCount, vector<int> &funEmployeeIdNumsVector, vector <int> funDepartmentIdNumsVector)
{
	bool funValidEmpId = false, funEmpDepartIdValid = false;
	funEmployeeAge = 0;
	funSalary = 0; 
	funEmployeeName = "";

	if (funEmployeeArrayCount > 6) 
		cout << "The array is full, you can not add any more Employees.";
	else 
	{
		// Get a valid Employee ID number
		while (funValidEmpId == false) 
		{
			cout << "\nEnter the Employee's ID number: ";
			cin >> funEmployeeID;
			checkEmployeeID(funEmployeeID, funValidEmpId, funEmployeeIdNumsVector);
		} 

		// Get a valid employee age
		while (funEmployeeAge < 18)
		{
			cout << "\nEnter the Employee's age: ";
			cin >> funEmployeeAge;
			if (funEmployeeAge < 18)
				cout << "Employees must be over 18 years old.";
		}

		// Get a valid Department ID		
		while (funEmpDepartIdValid == false)
		{
			cout << "\nEnter the employee's Department ID: ";
			cin >> funEmployeeDeptID;
			checkDepartmentID(funEmployeeDeptID, funEmpDepartIdValid, funDepartmentIdNumsVector);
		}

		// Get a valid salary
		while (funSalary == 0)
		{
			cout << "\nEnter the employee's salary: $ "; 
			cin >> funSalary;
			if (funSalary == 0)
				cout << "\nThe salary cannot be 0.";
		}
		
		// Get a valid name
		while (funEmployeeName == "")
		{
			cout << "\nEnter the employee's name: ";
			cin.get();
			getline(cin, funEmployeeName);
			if (funEmployeeName == "") 
				cout << "\nThe name cannot contain an empty string.";
		}
	}
}

/************************************************************************
*						checkEmployeeID									*
*	This function makes sure employee ID's are unique					*
************************************************************************/
bool checkEmployeeID(int &helperEmployeeId, bool &helperValidIdBoolean, vector<int> helperEmployeeIdVector)
{
	int sizeOfEmployeeIdVector;
	int local;
	sizeOfEmployeeIdVector = helperEmployeeIdVector.size();
	for (int i = 0; i < sizeOfEmployeeIdVector; i++)
	{
		local = helperEmployeeIdVector.at(i);
		if (local == helperEmployeeId)
			{
				cout << "\nThat employee ID is already in use. Please try again.";
				return helperValidIdBoolean;
			}
	}
	helperValidIdBoolean = true; 
	return helperValidIdBoolean; //change to true if issue
}

/************************************************************************
*						checkDepartmentID								*
*	This function makes sure the Department ID exists.					*
************************************************************************/
bool checkDepartmentID(int &helperEmployeeDeptId, bool &helperValidIdBoolean, vector<int> helperDepartmentIdNumsVector)
{
	int numberOfEmployeeIds;
	int local; 
	numberOfEmployeeIds = helperDepartmentIdNumsVector.size();
	for (int i = 0; i < numberOfEmployeeIds; i++)
	{
		local = helperDepartmentIdNumsVector.at(i);
		if (local == helperEmployeeDeptId)
			{
				helperValidIdBoolean = true;
				return helperValidIdBoolean; 
			}
	}
	cout << "\nThat department does not exist. Please try again.";
	return helperValidIdBoolean;
}

/************************************************************************
*						getDepartmentData								*
*	This function gets data for a department object.					*
************************************************************************/
void getDepartmentData(int &funDepartmentId, string &funDepartmentName, string &funDepartmentHeadName, int funDepartmentArrayCount, vector<int> funDepartmentIdNumsVector)
{
	bool funValidDeptId = false;
	funDepartmentName = "";
	funDepartmentHeadName = "";
	if (funDepartmentArrayCount > 3) 
	{
		cout << "The array is full, you can not add any more Departments.";
	}
	else 
	{
		// Get a valid Department ID		
		while (funValidDeptId == false)
		{
			cout << "\nEnter the Department ID: ";
			cin >> funDepartmentId;
			checkDepartmentID(funDepartmentId, funValidDeptId, funDepartmentIdNumsVector);
		}

		// Get a valid Department name
		while (funDepartmentName == "")
		{
			cout << "\nEnter the Department name: ";
			cin.get();
			getline(cin, funDepartmentName);
			if (funDepartmentName == "") 
				cout << "\nThe name cannot contain an empty string.";
		}

		// Get a valid Department head name
		while (funDepartmentHeadName == "")
		{
			cout << "\nEnter the Department head's name: ";
			cin.get();
			getline(cin, funDepartmentHeadName);
			if (funDepartmentHeadName == "") 
				cout << "\nThe Department head's name cannot contain an empty string.";
		}
	}
}

/************************************************************************
*					writeDeptAndEmpArraysToFile							*
*	This function writes each array to a separate File.					*
************************************************************************/
void writeDeptAndEmpArraysToFile(Department funDepartArray[], Employee funEmployeArray[], int funDepartArrayCount, int funEmployeArrayCount)
{
	// Instantiate File Stream Objects
	int i;
	ofstream DepArrFile; 
	ofstream EmpArrFile;
	//Write Department Array to a file
	cout << "\nFirst, save the Department array to a file.";
	DepArrFile.open("DepartmentArrayFile.txt");
	for (i = 0; i < funDepartArrayCount; i++)
		DepArrFile << funDepartArray[i].getDepartmentID();
		DepArrFile << funDepartArray[i].getDepartmentName();
		DepArrFile << funDepartArray[i].getDepartmentHeadName() << endl;
	DepArrFile.close();
	cout << "\nThe Department array has been saved to a file."
		 << "\nThe name of the file is DepartmentArrayFile.txt";

	//Write Employee Array to a file
	cout << "\nNext, save the Employee array to a file.";
	EmpArrFile.open("EmployeeArrayFile.txt");
	for (i = 0; i < funEmployeArrayCount; i++)
		EmpArrFile << funEmployeArray[i].getEmpID();
		EmpArrFile << funEmployeArray[i].getEmployeeAge();
		EmpArrFile << funEmployeArray[i].getEmployeeDepartmentID();
		EmpArrFile << funEmployeArray[i].getEmployeeSalary();
		EmpArrFile << funEmployeArray[i].getEmployeeName();

	EmpArrFile.close();
	cout << "\nThe Employee array has been saved to a file."
		 << "\nThe name of the file is EmployeeArrayFile.txt";
}

/************************************************************************
*			readDeptAndEmpArraysFromFile								*
*	This function reads data from two files into two arrays. 			*
************************************************************************/
void readDeptAndEmpArraysFromFile(Department funDepartmentArray[], Employee funEmployeeArray[])
{
	string tempEmployeeDataFileName, tempDepartmentDataFileName;
	int count = 0;
	ifstream dataInDept;
	ifstream dataInEmp;

	// Obtain filenames
	cout << "\nPlease enter the complete name of the file with the Employee data." << endl;
	cout << "\nPlease be sure to enter the file extension." <<endl;
	cout << "\nEnter the file name: > ";
	// cin.get();
	cin >> tempEmployeeDataFileName;
	cout << "\nPlease enter the complete name of the file with the Department data." << endl;
	cout << "\nPlease be sure to enter the file extension." <<endl;
	cout << "\nEnter the file name: > ";
	// cin.get();
	cin >> tempDepartmentDataFileName;

	//Read Department data from file into an array
	cout << "\nReading the Department information file into an array.";
	dataInDept.open(tempDepartmentDataFileName.c_str());
	if (!dataInDept)
		cout << "\nError opening data file.";
	else 
	{
		while (count < 3 && tempDepartmentDataFileName.c_str() >> funDepartmentArray[count].getDepartmentID())
			tempDepartmentDataFileName.c_str() >> funDepartmentArray[count].getDepartmentName()
			tempDepartmentDataFileName.c_str() >> funDepartmentArray[count].getDepartmentHeadName()
			count ++;
		dataInDept.close();
	}
	// Read Employee data from file into an array
	count = 0;
	cout << "\nNext, read the Employee information file into an array.";
	dataInEmp.open(tempEmployeeDataFileName.c_str()); 
	if (!dataInEmp)
		cout << "\nError opening data file.";
	else 
	{
		while (count < 7 && tempEmployeeDataFileName.c_str() >> funEmployeeArray[count].getEmpID())
			tempEmployeeDataFileName.c_str() >> funEmployeeArray[count].getEmployeeAge()
			tempEmployeeDataFileName.c_str() >> funEmployeeArray[count].getEmployeeDepartmentID()
			tempEmployeeDataFileName.c_str() >> funEmployeeArray[count].getEmployeeSalary()
			tempEmployeeDataFileName.c_str() >> funEmployeeArray[count].getEmployeeName()
			count ++;
		dataInEmp.close();
	}
	cout << "\nDone reading data from both files into the arrays.";
}

/************************************************************************
*					displayArraysAndSalaries							*
*	This function displays the arrays & salary by department.			*
************************************************************************/
void displayArraysAndSalaries(Department depArray[], Employee empArray[], int nemps, int ndept)
{
	// initialize a few variables
	int j, i, u;
	double sal = 0.0;
	
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
	// Display Salary Information by Department
	for (i = 0; i < ndept; i++)
	{
		u = depArray[i].getDepartmentID();
		for (j = 0; j < nemps; j++)
				{
					if (empArray[j].getEmployeeDepartmentID() == u)
						sal = sal + empArray[j].getEmployeeSalary();
				}
				cout << "The total salary for Department ID number " << u << "is $" << sal;
	}
}


