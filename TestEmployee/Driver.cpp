#include<iostream>
#include<string>
#include "Employee.h"

Employee global("static Global");
void Function();
void main()
{

Employee e1("auto Local main");
//e1.SetSalary(650);
static Employee e2("static local main");
//Objects Handels(Object Name,Object Refernce, Object Pointer)
/*Employee & e2ref=e2;
Employee * e2ptr=&e2;
cout<<e2ref.GetName()<<endl;
cout<<e2.GetName()<<endl;
cout<<e2ptr->GetName()<<endl;
cout<<(*e2ptr).GetName()<<endl;*/
Function();
}

void Function()
{
Employee e3("auto local function");

static Employee e4("static local function");

}