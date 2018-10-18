#include <iostream>
#include <string>
#include "section.h"
using namespace std;


Section::Section(int Snumber, string Sname)
{
secNum=Snumber;
secName=Sname;

}
void Section::setSection(int Snumber,string Sname)
{
secNum=Snumber;
secName=Sname;
}

void Section::print()const
{
cout<<"Section Number:"<<secNum<<endl;
cout<<"Section Name:"<<secName<<endl;

}