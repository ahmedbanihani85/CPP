#ifndef Employee_h
#define Employee_h
#include<iostream>
#include<string>

using namespace std;

class Employee
{
private:
string Name;
int ID;
float Salary;
string Department;
float Tax();

public:

	Employee(string name="Ali", float salary=550.0, int id=1, string dept="Services");
	void SetName(string n);
	void SetID(int id);
	void SetSalary(float s);
	void SetDepartment(string d);
	void SetAll(string name, float salary, int id, string dept);
	string GetName();
	string GetDepartment();
	int GetID();
	float GetSalary();
	float AnnualSalary();
	void Print();
	~Employee();
};


#endif