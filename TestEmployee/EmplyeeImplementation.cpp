#include<iostream>
#include"Employee.h"

void Employee::SetName(string n)
{
Name=n;

}

void Employee::SetID(int id)
{
ID=id;

}

void Employee::SetSalary(float s)
{
Salary=s;
}

void Employee::SetDepartment(string d)
{
Department=d;
}

string Employee::GetName()
{
return Name;
}

string Employee::GetDepartment()
{

return Department;
}

int Employee::GetID()
{
return ID;
}

Employee::Employee(string name,float salary,int id,string dept)
{

	SetName(name);
	SetSalary(salary);
	SetID(id);
	SetDepartment(dept);
	cout<<"Constructor for Employee "<<Name<<endl;
}

Employee::~Employee()
{
cout<<"Destructor for Employee "<<Name<<endl;
}