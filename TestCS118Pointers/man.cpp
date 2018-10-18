#include<iostream>
using namespace std;

int CountEven(int*, int) ;
void main()
{

/*int x=10;
int &y=x;
int *z=&x;
cout<<x<<endl;
cout<<y<<endl;
cout<<z<<endl;
cout<<*z<<endl;
cout<<*&z<<endl;
*z=15;
cout<<x<<endl;
cout<<y<<endl;
cout<<&z<<endl;*/
	int x=2,y=8;
	int *p,*q;
	p=&x;
	q=&y;
	cout<<&x<<'\t'<<x<<endl;
	cout<<p<<'\t'<<*p<<endl;
	cout<<&y<<'\t'<<y<<endl;
	cout<<q<<'\t'<<*q<<endl;
	cout<<&p<<endl;
	cout<<&q<<endl;
	int size;
	cin>>size;
	int *arrptr=new int[size];
	arrptr[0]=10;
	delete arrptr;
}

int CountEven(int* array, int size)
{

int count=0;
for(int i=0;i<size;i++)
{
if(array[i]%2==0)
count++;
}
return count;

}