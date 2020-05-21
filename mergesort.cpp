  /* Program for MERGE SORT */
#include<iostream>
#include<stdlib.h>
using namespace std;
void mergesort(int a[],int n);
void msort(int a[],int t[],int l,int r);
void merge(int a[],int t[],int fb,int sb,int se);
main()
{

	int a[20],i,n;
	cout<<"\n Enter number of elements:";
	cin>>n;
	cout<<"\n Enter "<<n<<" element ";
	for(i=0;i<n;i++)
	cin>>a[i];
	cout<<"\n Before sorting,the elements are:";
	for(i=0;i<n;i++)
	cout<<a[i];
	mergesort(a,n);
	cout<<"\n\n After sorting, the elements are:";
	for(i=0;i<n;i++)
	cout<<a[i];
}
void mergesort(int a[],int n)
{
	int *t,l,r;
	l=0;r=n-1;
	t=(int *)malloc(n*sizeof(int));
	msort(a,t,l,r);
	free(t);
}
void msort(int a[],int t[],int l,int r)
{
	int c;
	if(l<r)
	{
		c=(l+r)/2;
		msort(a,t,l,c);
		msort(a,t,c+1,r);
		merge(a,t,l,c+1,r);
	}
}
void merge(int a[],int t[],int fb,int sb,int se)
{
	int i,n,fe,tp;
	fe=sb-1;
	tp=fb;
	n=se-fb+1;
	while((fb<=fe)&&(sb<=se))
	{
		if(a[fb]<a[sb])
		t[tp++]=a[fb++];
		else
		t[tp++]=a[sb++];
	}
	while(fb<=fe)
	t[tp++]=a[fb++];
	while(sb<=se)
	t[tp++]=a[sb++];
	for(i=1;i<=n;i++,se--)
	a[se]=t[se];
}
