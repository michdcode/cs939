#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

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
		{	DepartmentID = iID; }

		void setDeptName(string iDeptName)
		{	Departmentname = iDeptName; }

		void setCost(string iDeptHead)
		{	DepartmentHeadName = iDeptHead; }
};

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
		Employee(int userDeptID, string userDeptName, string userDeptHead)
		{
			setDeptID(userDeptID);
			setDeptName(userDeptName);
			setDeptHead(userDeptHead);
		}
		// // Accessor functions
		// int getItemNumber()
		// { 	return itemNumber; }

		// Mutator functions definitions - inline because they are shorter
		void setDeptID(int iID)
		{	DepartmentID = iID; }

		void setDeptName(string iDeptName)
		{	Departmentname = iDeptName; }

		void setCost(string iDeptHead)
		{	DepartmentHeadName = iDeptHead; }
};