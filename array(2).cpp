#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
class Array{
	private:
		int Maxsize;
		int A[20];
		int size;
	public:
		Array(){
			Maxsize=20;
			size=0;
		}
	void Read_Array();
	void Display();
	void Transverse_Backward();
	void Insert(int Location,int Element);
	void Delete(int Location);
	void search(int Element);
};
void Array::Read_Array(){
	int i,n;
	cout<<"Enter the size of an array";
	cin>>n;
	if(n>Maxsize){
		cout<<"Array of the size can't be created";
		cout<<"Maximum size is "<<Maxsize;
		return;
	}
	else
	{
		for(i=0;i<n;i++)
		cin>>A[i];
	}
	size=n;
}
void Array::Display(){
	int i;
	for(i=0;i<size;i++){
		cout<<A[i]<<"\t";
		cout<<endl;
	}
}
void Array::Transverse_Backward(){
	int i;
	for(i=size-1;i>=0;i--){
		cout<<A[i]<<"\t";
		cout<<endl;
	}
}
void Array::search(int Element){
	int i;
	for(i=0;i<=size-1;i++){
		if(Element=A[i])
		return(i+1);
	}
	return(-1);
}
void Array::Insert(int Location,int Element){
	int i;
	if(size>=Maxsize){
		cout<<"sorry,array overflow";
		return;
	}
	for(i=size-1;i>=Location-1;i--){
		A[i+1]=A[i];
	}
	A[Location-1]=Element;
	size=size+1;
}
void Array::Delete(int Location){
	int i;
	for(i=Location;i<size;i++){
		A[i-1]=A[i];
	}
	A[size-1]=0;
	size=size-1;
}
int main(){
	Array A;
	int ch,ans,a;
	do{
		cout<<"---Menu---\n";
		cout<<"1.Read_Array \n";
		cout<<"2.Display\n";
		cout<<"3.Transverse Backward\n";
		cout<<"4.Insert\n";
		cout<<"5.Delete\n";
		cout<<"6.Search";
		cout<<"7.Exit";
		cout<<"\n Enter your choice:";
		cin>>ch;
		switch(ch){
			case 1:
				A.Read_Array();
				break;
			case 2:
				A.Transverse_Backward();
				break;
			case 3:
				A.Transverse_Backward();
				break;
			case 4:
				A.Insert(3,66);
				A.Display();
				break;
			case 5:
				cout<<endl;
				A.Delete(3);
				A.Display();
				break;
			case 6:
				cout<<endl;
				a=A.search(66);
				if(a!=-1)
				cout<<"Element 66 is found at position"<<endl;
				else
				cout<<"\n Element 66 is not found";
				break;
			case 7:
				exit(0);
				break;
		}
	cout<<"\n Do you want to continue?(Y->1/N->0)";
	cin>>ans;
	while(ans==1);
	};
}
