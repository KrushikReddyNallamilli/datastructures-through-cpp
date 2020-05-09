	/* Program for Queue operations using arrays  */
#include<iostream>
#include<conio.h>
using namespace std;
class QUEUE
{
private:
int Queue[50];
int MaxCapacity;
int front,rear;
public:
QUEUE( )
	{ MaxCapacity= 5; front=rear=-1;}
void front_of_queue(void);
void Delete(void );
void insert(void);
void display(void);
};

void QUEUE::insert(void)
{
	int x;
	if(rear==MaxCapacity-1)
	cout<< "Queue is full";
	else
	{
		cout<< "Enter the item:";
		cin>>x;
		if(rear==-1)
		  front=rear=0;
		else
		rear=rear+1;
		Queue[rear]=x;
	}

}
void QUEUE:: Delete(void)
{
	if(front<0)
	cout<<"Q is  empty";
	else
	{
		cout<<" The Dleted element is "<<Queue[front];
		front=front+1;
	}
}
void QUEUE::display(void)
{
	int i;
	if(front<0)
	cout<< "Queue is empty";
	else
	{
		cout<<" Queue contents from front to rear:";
		for(i=front;i<=rear;i++)
		cout<<"\t"<<Queue[i];
	}
}
void QUEUE::front_of_queue(void)
{
	if(front<0)
	cout<< "Queue is empty";
	else
	cout<< "Front element is "<<Queue[front];
}
int main( )
{
QUEUE Q;
int ch;
 cout<<"\n 1.INSERT \n 2.DELETE \n 3.DISPLAY ";
	cout<<" \n 4.FROUNT_OF_QUEUE";
	cout<<" \n 5.EXIT";
		while(1)
	{
		cout<<"\n Enter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:	Q.insert();
				break;
			case 2: Q.Delete();
				break;
			case 3: Q.display();
				break;
			case 4: Q.front_of_queue();
				break;
			case 5: exit(1);
				break;
			defualt: cout<<"\nIt is wrong choice";
				break;
		}
	}
	getch();
}
