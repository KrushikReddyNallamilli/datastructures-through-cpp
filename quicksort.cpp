#include<iostream>
#include<stdlib.h>
using namespace std;
void quicksort(int a[],int lb,int ub)
{
int i,j,pivot;
if(lb<ub)
{
i=lb;
j=ub;
pivot=lb;
while(i<j)
{
while(a[i]<=a[pivot] && i<ub)
i++;
while(a[j]>a[pivot] && j>lb)
j--;
if(i<j)
swap(a[i],a[j]);
}
swap(a[pivot],a[j]);
quicksort(a,lb,j-1);
quicksort(a,j+1,ub);
}
}

void swap(int *a,int *b)
{
int t;
t=*a;
*a=*b;
*b=t;
}
int main()
{
int a[20],n,i;
cout<<"enter no of elememts";
cin>>n;
cout<<"enter elements";
for(i=0;i<n;i++)
cin>>a[i];
cout<<"\nelements before sorting\n";
for(i=0;i<n;i++)
cout<<a[i];
quicksort(a,0,n-1);
cout<<"\nelements after sorting\n";
for(i=0;i<n;i++)
cout<<a[i];
return 0;
}
