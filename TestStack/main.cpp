#include<iostream>
using namespace std;

class Stack
{
private:
	int data;
	Stack *next;

public:
	Stack *head,*current,*tail;

	Stack()
	{
	data=0;
	head=current=tail=next=NULL;
	}

	void Create()
	{
		head=tail=current=new Stack;
		cin>>current->data;
		int x;
		cin>>x;
		while(x!=-1)
		{
		current=new Stack;
		current->data=x;
		current->next=head;
		head=current;
		cin>>x;

		}
	}


	void Print()
	{
	current=head;
	while(current!=NULL)
	{
	cout<<current->data<<"\t";
	current=current->next;
	
	}
	cout<<endl;
	}
	void Push()
	{
	current=new Stack;
	cin>>current->data;
	current->next=head;
	head=current;
	
	}
	void Pop()
	{
	current=head;
	cout<<current->data<<endl;
	head=head->next;
	delete current;
	
	}

};


void main()
{
Stack S;
S.Create();
S.Print();
//S.Push();
S.Pop();
S.Print();

}