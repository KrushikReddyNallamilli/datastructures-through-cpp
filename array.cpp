#include<conio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
class Array
{
private :
int MaxSize;
int A[20];
int Size;
public :
Array() // constructor
{
MaxSize=20;
Size=0;
}
void Read_Array();
void Display( ); // Traverse_Forward( )
void Traverse_Backward( );
void Insert(int Location, int Element);
void Delete (int Location);
int Search(int Element);
};
void Array :: Read_Array( )
{
int i, N;
cout<<" Enter size of array";
cin>> N;
if( N >MaxSize)
{
cout<< " Array of this size cannot be created";
cout<< "Maximum size is"<<MaxSize ;
return;
}
else
{
for (i=0;i<N;i++)
{
cin>> A[i];
}
Size=N;
}
}
void Array :: Display( )
{
int i;
for (i=0;i<Size;i++)
cout<< A[i]<< "\t";
cout<<endl;
}
void Array :: Traverse_Backward( )
{
int i;
for (i=Size-1; i>=0; i--)
cout<< A[i] <<"\t";
cout<<endl;
}
int Array ::Search (int Element)
{
int i;
for (i=0; i< Size-1; i++)
{
if (Element == A[i])
return (i+1);
}
return(-1);
}
void Array :: Insert (int Location, int Element)
{
int i;
if (Size>=MaxSize)
{
cout<< "Sorry, Array Overflow";
return;
}
for (i=Size-1; i>=Location-1; i--)
{
A[i + 1] = A[i]; //shifting element to right by 1 position
}
A[Location-1] = Element;
Size=Size+1;
}
void Array ::Delete (int Location)
{
int i;
for (i=Location;i<Size;i++)
{
A[i-1] = A[i]; // shifting elements to left by 1 position
}
A[Size-1] = 0; // Store 0 at last location to mark it empty
Size=Size-1;
}
int main()
{
Array A;
int ch,ans,a;
do
{       
	cout<<"\n****** MENU *********\n";
	cout<<"    1. Read Array\n";
	cout<<"	   2. Display\n";
	cout<<"    3. Traverse Backward\n";
	cout<<"	   4. Insert\n";
	cout<<"    5. Delete\n";
	cout<<"	   6. Search\n";
	cout<<"	   7. Exit\n";
	cout<<"\n Enter your choice";
	cin>>ch;
	switch(ch)
	{
		case 1:
			A.Read_Array();
			break;
		case 2:
			A.Display( ); // Traverse_Forward( )
			break;
		case 3:
			A.Traverse_Backward( );
			break;
		case 4:
			A.Insert(3,66);
			A.Display( );
			break;
		case 5:
			cout<<endl;
			A.Delete (3); // delete 3rd element
			A.Display( );
			break;
		case 6:
			cout<<endl;
			a=A.Search(66);
			if(a!=-1)
			cout<<"Element 66 is found at position"<<a;
			else
			cout<<"\n Element 66 is Not found!!!";
			case 7:
			exit(0);
		break;
	}
cout<<"\n Do you want to continue? [Y->1/N->0]";
cin>>ans;
}while(ans==1);
}
