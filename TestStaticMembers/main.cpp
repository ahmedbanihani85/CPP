#include<iostream>
#include<string>
#include "student.h"
using namespace std;

void main()
{
	cout<<Student::getNumberOfHours()<<endl;
	Student::INCREMENT3();
	cout<<Student::getNumberOfHours()<<endl;
	Section S(1,"SSS");
	Student St("Ahmad",2012458,S);
	St.INCREMENT3();
	cout<<St.getNumberOfHours()<<endl;
	St.SET_STUDENT("Bani Hani",20125355,S);
	St.print();

}