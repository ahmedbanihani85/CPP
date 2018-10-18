#include<iostream>
#include<string>
#include "Employee.h"

Employee e5("Mohamad",550.6f,51,"IT");
void Function();
void main()
{

Employee e1;
e1.SetSalary(650);
static Employee e2("Salim");
//Objects Handels(Object Name,Object Refernce, Object Pointer)
Employee & e2ref=e2;
Employee * e2ptr=&e2;
cout<<e2ref.GetName()<<endl;
cout<<e2.GetName()<<endl;
cout<<e2ptr->GetName()<<endl;
cout<<(*e2ptr).GetName()<<endl;

}

void Function()
{
Employee e3("Khalid",400.2f);

static Employee e4("Ahmad",450.6f,50);

}