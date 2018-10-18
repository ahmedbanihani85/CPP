#include<iostream>
using namespace std;

class node
{
private:
	int data;
	node * next;
public:
	node *current,*head,*tail;
	
	node()
	{
	head=current=tail=next=NULL;
	data=0;
	}

	void Read()//create
	{
	head=tail=current=new node;
	cin>>current->data;

	int x;
	cin>>x;
	while(x!=-1)
	{
	current=new node;
	current->data=x;
	tail->next=current;
	tail=current;
	cin>>x;
	}
	}

	void Write()//Print
	{
		cout<<endl;
		cout<<endl;
		cout<<endl;
current=head;
while(current!=NULL)
{
	cout<<current->data<<"\t";
	current=current->next;

}

cout<<endl;
	}



void Insert()
{
	int max;
	for(current=head; current!=NULL; current=current->next)
		if(current->data>max)
			max=current->data;
		cout<<"Max is"<<max<<endl;


for(current=head; current->data!=max; current=current->next);
cout<<"Current Data is:"<<current->data<<endl;
node *ptr=new node;
ptr->data=1000;
ptr->next=current->next;
current->next=ptr;

}

void InsertAtBegin()
{
	node * ptr=new node;
	ptr->data=2000;
	ptr->next=head;
	head=ptr;
}

void InsertAtEnd()
{
	node * ptr=new node;
	ptr->data=3000;
	for(tail=head; tail->next!=NULL; tail=tail->next);
	ptr->next=NULL;
	tail->next=ptr;
	tail=ptr;



}
void Sort()
{
	tail=head;

	while(tail!=NULL)
	{
for(current=head; current->next!=NULL; current=current->next)
{
	int temp=0;
if( (current->data) > (current->next->data) )
{
temp=current->data;
current->data=current->next->data;
current->next->data=temp;
}
}
tail=tail->next;
}

}


void Del()
{
int max;
	for(current=head; current!=NULL; current=current->next)
		if(current->data>max)
			max=current->data;
		cout<<"Max is"<<max<<endl;


for(current=head; current->next->data!=max; current=current->next);
node * ptr=current->next;
current->next=ptr->next;
delete ptr;

}
void DelAtBegin()
{
node * ptr=head;
head=ptr->next;
delete ptr;
}
};
void main()
{
node LS;
LS.Read();
LS.Write();
//LS.Insert();
//LS.InsertAtBegin();
//LS.InsertAtEnd();
//LS.Sort();
//LS.Del();
LS.DelAtBegin();
LS.Write();

}