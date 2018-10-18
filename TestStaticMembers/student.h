#include<iostream>
#include<string>
#include "section.h"
using namespace std;

#ifndef student_h
#define student_h
class Student
{
private:
string	Stname;
int stnumber;
Section stsection;
static int NumberOfHours;
public:
	Student(string n,int num,Section & sec);
	void SET_STUDENT(string n,int num,Section & sec);
	void print();
	static void INCREMENT3();
	static int getNumberOfHours();
};
#endif