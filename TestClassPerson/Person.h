#include<iostream>
#include<string>
using std::string;

class Person
{

private:
int Age;
string Name;
string EyeColor;
string HairColor;
double Weight;
double Hight;

public:

Person();
Person(int age,string name,string eyecolor,string haircolor,double weight,double hight);

void SetAge(int age);
void SetName(string name);
void SetEyeColor(string color);
void SetHairColor(string color);
void SetWeight(double weight);
void SetHight(double hight);

int GetAge();
string GetName();
string GetEyeColor();
string GetHairColor();
double GetWeight();
double GetHight();

void PrintInfo();



};