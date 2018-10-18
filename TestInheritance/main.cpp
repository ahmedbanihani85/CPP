#include<iostream>
#include<string>
using namespace std;
class Person
{
private:
	int ID;
	string Name;
public:
Person(int id=0,string n="Unknown")
{
ID=id;
Name=n;
}
void Print()
{
cout<<"ID:"<<ID<<endl;
cout<<"Name:"<<Name<<endl;
}

	void SetID(int id)
	{
	ID=id;
	}
	void SetName(string n)
	{
	Name=n;
	}
	int GetID()
	{return ID;}
	string GetName()
	{return Name;}

};
class Employee:public Person
{
private:
	string Position;
public:
	Employee(int id=0,string n="Unknown",string p="Unknown"):Person(id,n)
	{
		Position=p;
	}
	void SetPosition(string p)
	{
	Position=p;
	}

	string GetPosition()
	{return Position;}
	void Print()
	{
		Person::Print();
		cout<<"Position:"<<Position<<endl;
	}

};

void main()
{
Employee e1;
e1.Print();


}