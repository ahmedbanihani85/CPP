#include<iostream>
#include<string>

using namespace std;

class Date
{
	friend void PrintDate2(Date &d);
private:
	int Day;
	int Year;
	int Month;
public:


	Date(int d=1,int m=1,int y=1900)
	{
	Day=d;
	Month=m;
	Year=y;
	cout<<"constructor for date"<<Day<<"/"<<Month<<"/"<<Year<<endl;
	
	}
	Date(Date & obj)
	{
	Day=obj.Day;
	Month=obj.Month;
	Year=obj.Year;
cout<<"Copy constructor for date"<<Day<<"/"<<Month<<"/"<<Year<<endl;
	}

~Date()
{
cout<<"Destructor for date"<<Day<<"/"<<Month<<"/"<<Year<<endl;
}

int GetDay()
{
return Day;
}

int GetMonth()
{
return Month;
}

int GetYaer()
{
return Year;
}
};



class Employee
{
private:

Date DateOfBirth;
Date DateOfHire;
string Name;
const int ID;
float Salary;
string Department;

public:


	Employee(Date & DofB,Date &DofH,int id,string name="Nkonwn", float salary=500.50f,  string dept="Unkown"):ID(id),DateOfBirth(DofB),DateOfHire(DofH)
	{
	Name=name;
	Salary=salary;
	Department=dept;
	cout<<"Constructor for Employee:"<<Name<<" " <<endl;
	}
	Employee(int d1,int m1,int y1,int d2,int m2,int y2 ,int id,string name="Nkonwn", float salary=500.50f,  string dept="Unkown"):ID(id),DateOfBirth(d1,m1,y1),DateOfHire(d2,m2,y2)
	{
	Name=name;
	Salary=salary;
	Department=dept;
	cout<<"Constructor for Employee:"<<Name<<" " <<endl;
	}
	void SetName(string n)
	{
	Name=n;
	}
	/*void SetID(int id)
	{
	ID=id;
	}*/
	void SetSalary(float s)
	{
	Salary=s;
	}
	void SetDepartment(string d)
	{
	Department=d;
	}
	void SetAll(string name, float salary, int id, string dept)
	{
	Name=name;
	Salary=salary;
//	ID=id;
	Department=dept;
	}
	string GetName()const
	{
	return Name;
	}
	string GetDepartment()const
	{
	return Department;
	}
	int GetID()
	{
	return ID;
	}
	float GetSalary()const
	{
	return Salary;
	}
	float AnnualSalary()const
	{
	return 12*Salary;
	}
	void Print()const
	{
	cout<<"Employee ID:"<<ID<<endl;
	cout<<"Employee Name:"<<GetName()<<endl;
	cout<<"Employee Salary:"<<GetSalary()<<endl;
	cout<<"Employee Annual Salary:"<<AnnualSalary()<<endl;
	cout<<"Employee Department:"<<GetDepartment()<<endl;
	}
	/**/

	~Employee()
	{
		cout<<"Destructor for Employee:"<<Name<<" " <<endl;
	}

};

void PrintDate(Date & d)//non-friend function must use get functions
{// the reference in the parameter list is to prevent  the copy constructor calls 
cout<<"From Print Function:"<<d.GetDay()<<"/"<<d.GetMonth()<<"/"<<d.GetYaer()<<endl;
}
void PrintDate2(Date & d)// friend function can access the private members.
{// the reference in the parameter list is to prevent  the copy constructor calls
cout<<"From friend Print Function:"<<d.Day<<"/"<<d.Month<<"/"<<d.Year<<endl;
}
void main()
{
//Date BD(1,1,1990);
Date HD (1,1,2010);
PrintDate(HD);
//PrintDate2(HD);
 //Employee e1(BD,HD,10001);//Uses copy constructor for date class
//e1.Print();
 //Employee e2(1,1,1995,1,1,2008,10002);//Uses default constructor for class date

}