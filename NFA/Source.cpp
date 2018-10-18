/*
Wayne State University			

Name: Ahmad Mohamad Bani Hani 
ID: 004398473
PhD Student, Department of Computer Science

Course: CSC 6500    Theory of Languages, Automata and Computation  
Home Work 3 Solution
09/29/2014


*/

#include<iostream>
#include<string>
#include <fstream>
using namespace std;
typedef enum NFAStates {State0,State1,State2,State3,State4,State5,State6,State7};
NFAStates CurrentNFAState;


//Transition Table.
static	NFAStates NFATransition[][26]={{State0,State5,State1,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0},//State0(q0)
									{State2,State5,State1,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0},//State1(q1)
									{State0,State4,State1,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State3,State0,State0,State0,State0,State0,State0},//State2(q2)
									{State3,State3,State3,State3,State3,State3,State3,State3,State3,State3,State3,State3,State3,State3,State3,State3,State3,State3,State3,State3,State3,State3,State3,State3,State3,State3},//State3(q3)
									{State4,State4,State4,State4,State4,State4,State4,State4,State4,State4,State4,State4,State4,State4,State4,State4,State4,State4,State4,State4,State4,State4,State4,State4,State4,State4},//State4(q4)
									{State6,State5,State1,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0},//State5(q5)
									{State0,State5,State1,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State0,State7,State0,State0,State0,State0,State0,State0},//State6(q6)
									{State7,State7,State7,State7,State7,State7,State7,State7,State7,State7,State7,State7,State7,State7,State7,State7,State7,State7,State7,State7,State7,State7,State7,State7,State7,State7}};//State7(q7)
int MapStateToIndex(NFAStates s)
{
return static_cast<int>(s);
}
int MapCharacterToIndex(char s)
{
return static_cast<int>(s)-static_cast<int>('a');
}
NFAStates  NextState(NFAStates & s,char c)
{
	int x=MapStateToIndex(s);
	int y=MapCharacterToIndex(c);

return ( NFATransition[x][y]);

}
void main()
{
	cout<<"***********************************";
	cout<<endl<<"Ahmad Bani Hani,ID: 004398473"<<endl;
	cout<<"***********************************"<<endl;
	char c;
	string InputChar;
	ifstream InputFile;
	int choice;
	cout<<"To read the file with the accepted strings enter1:"<<endl;
	cout<<"To read the file with the not accepted strings enter any number:"<<endl;
	cin>>choice;
	if(choice==1)
	InputFile.open("File1.txt");
	else
	{
		InputFile.open("File2.txt");
	}
	if(InputFile.is_open())
	while (!InputFile.eof())
	{

	InputFile>>InputChar;
	cout<<endl<<"Checking the input string:"<<InputChar<<endl;
	CurrentNFAState=State0;//Start State.


int i=0;
while(i < InputChar.length())
{
	c=InputChar[i];
	i++;
	CurrentNFAState=NextState(CurrentNFAState,c);
}
i=0;
if(CurrentNFAState==State3 || CurrentNFAState==State4||CurrentNFAState==State7)
	cout<<"Accepted String........."<<endl;
else
	cout<<"Not Accepted String........."<<endl;


}
InputFile.close();


}