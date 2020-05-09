	/*  Program for stack operations using arrays  */
#include<iostream>
#include<conio.h>
using namespace std;
class STACK
{
private:
int Stack[50];
int MaxCapacity;
int top;
public:
STACK( )
	{ MaxCapacity= 5; top=-1;}
void top_of_stack(void);
void pop(void );
void push(void);
void display(void);
};

void STACK::push(void)
{
	int x;
	if(top==MaxCapacity-1)
	cout<< "Stack is overflow";
	else
	{
		cout<< "Enter the item:";
		cin>>x;
		top=top+1;
		Stack[top]=x;
	}

}
void STACK:: pop(void)
{
	if(top<0)
	cout<<"Stack is underflow";
	else
	{
		cout<<" The poped element is "<<Stack[top];
		top=top-1;
	}
}
void STACK::display(void)
{
	int i;
	if(top<0)
	cout<< "Stack is underflow";
	else
	{
		cout<<" Stack contents from top to bottom:";
		for(i=top;i>=0;i--)
		cout<<"\t"<<Stack[i];
	}
}
void STACK::top_of_stack(void)
{
	if(top<0)
	cout<< "Stack is underflow";
	else
	cout<< "Top element is "<<Stack[top];
}
int main( )
{
STACK S;
int ch;
 cout<<"\n 1.PUSH \n 2.POP \n 3.DISPLAY ";
	cout<<" \n 4.TOP_OF_STACK ";
	cout<<" \n 5.EXIT";
		while(1)
	{
		cout<<"\n Enter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:	S.push();
				break;
			case 2: S.pop();
				break;
			case 3: S.display();
				break;
			case 4: S.top_of_stack();
				break;
			case 5: exit(1);
				break;
			defualt: cout<<"\nIt is wrong choice";
				break;
		}
	}
	getch();
}
