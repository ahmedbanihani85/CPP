#include<iostream>
#include<string>
#include"Person.h"
using std::cout;
using std::cin;
using std::getline;
using std::string;
using std::endl;


Person::Person()
{
Age=0;
Name="";
EyeColor="";
HairColor="";
Weight=0.0;
Hight=0.0;

}

Person::Person(int age,string name,string eyecolor,string haircolor,double weight,double hight)
{
Age=age;
Name=name;
EyeColor=eyecolor;
HairColor=haircolor;
Weight=weight;
Hight=hight;
}

void Person::SetAge(int age)
{
Age=age;
}

void Person::SetEyeColor(string color)
{
EyeColor=color;
}

void Person::SetHairColor(string color)
{
HairColor=color;
}

void Person::SetWeight(double weight)
{
Weight=weight;
}

void Person::SetHight(double hight)
{
Hight=hight;
}

void Person::SetName(string name)
{
Name=name;
}

int Person::GetAge()
{
return Age;
}
string Person::GetName()
{
return Name;
}

string Person::GetEyeColor()
{
return EyeColor;
}

string Person::GetHairColor()
{
return HairColor;
}

double Person::GetWeight()
{
return Weight;
}

double Person::GetHight()
{
return Hight;
}

void Person::PrintInfo()
{
cout<<"***********Person Informations***********"<<endl;
cout<<"The Person Name is: "<<Name<<endl;
cout<<"The Person Age  is: "<<Age<<endl;
cout<<"The Person Eye Color is: "<<EyeColor<<endl;
cout<<"The Person Hair Color is: "<<HairColor<<endl;
cout<<"The Person Weight is: "<<Weight<<" KG"<<endl;
cout<<"The Person Hight is: "<<Hight<<" CM"<<endl;
cout<<"***********The Information End***********"<<endl<<endl;


}


