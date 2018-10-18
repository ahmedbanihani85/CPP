
#include <iostream>
#include <string>
using namespace std;

#ifndef Section_h
#define section_h

class Section
{
private:
int secNum;
string secName;
public:
Section(int, string);
void setSection(int,string);
void print()const;
};

#endif