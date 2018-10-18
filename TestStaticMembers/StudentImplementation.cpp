#include<iostream>
#include<string>
#include "student.h"
using namespace std;
int Student::NumberOfHours=0;
Student::Student(string n,int num,Section & sec):Stname(n),stnumber(num),stsection(sec)
{


}
void Student::SET_STUDENT(string n,int num, Section & sec)
{
stnumber=num;
Stname=n;
stsection=sec;
}

void Student::print()
{
cout<<"Student Name:"<<Stname<<endl;
cout<<"Student Number:"<<stnumber<<endl;
stsection.print();
}

 void Student::INCREMENT3()
{
NumberOfHours+=3;
}
 int Student::getNumberOfHours()
{
return NumberOfHours;
}

