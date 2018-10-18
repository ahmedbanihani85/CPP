#include<iostream>
#include<string>
using namespace std;
bool CheckString(string x,int n,int Index);
void main()
{
string x;
cin>>x;
cout<<boolalpha<<CheckString(x,0,x.length()-1 )<<"\n";

}

bool CheckString(string x,int FirstIndex,int LastIndex)
{
if(FirstIndex==x.length()/2)
return true;
string s1,s2;
s1=x.substr(FirstIndex,1);
s2=x.substr(LastIndex,1);
FirstIndex++;
LastIndex--;

if(!s1.compare( s2))
{


return CheckString(x,FirstIndex,LastIndex);

}
else
{
	
return false;
}

}