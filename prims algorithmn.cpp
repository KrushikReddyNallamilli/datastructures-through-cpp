#include<iostream>
#define infinity 999
using namespace std;
int n, cost[10][10],adj[10][10];
void prim()
{
 int i,j,k,l,x;
 int nr[20];
 int min_cost,temp,tree[10][3];
 min_cost=0;
  /* For first smallest edge */
 temp=999;
 for(i=1;i<=n;i++)
 {
     for(j=1;j<=n;j++)
     {
        if(cost[i][j]<temp && cost[i][j] !=0)
        {
        temp=cost[i][j];
        k=i;
        l=j;
        }
     }
 }
 cout<<" first min cost edge is "<<temp;

 /* Now we have fist smallest edge in graph */
 tree[1][1]=k;
 tree[1][2]=l;
 tree[1][3]=temp;
 min_cost=temp;

 /* Now we have to find min dist of each vertex from either k or l
by initialising nr[] array */

 for(i=1;i<=n;i++)
    {
    if(cost[i][k]< cost[i][l])
	nr[i]=k;
    else
	nr[i]=l;
    }
 /* To indicate visited vertex initialise nr[] for them to 0 */
 nr[k]=0;
 nr[l]=0;
 /* Now find out remaining n-2 edges */
 temp=999;
 for(i=2;i<=n-1;i++)
    {
    for(j=1;j<=n;j++)
       {
       if(nr[j]
		   !=0 && cost[j][nr[j]] < temp)
           {
	   temp=cost[j][nr[j]];
           x=j;
           }
       }
 /* Now we have got next vertex */
 tree[i][1]=x;
 tree[i][2]=nr[x];
 tree[i][3]=cost[x][nr[x]];
 min_cost=min_cost+cost[x][nr[x]];
 nr[x]=0;

 /* Now find if x is nearest to any vertex than its previous near value */

    for(j=1;j<=n;j++)
    {
    if(nr[j]!=0 && cost[j][nr[j]] > cost[j][x])
	 nr[j]=x;
    }
    temp=999;
 }

 cout<<"\n The min spanning tree is:- ";
 for(i=1;i<=n-1;i++)
    {
    for(j=1;j<=3;j++)
	   cout<<tree[i][j];
    cout<<"\n";
    }

 cout<<"\n Min cost:-"<< min_cost;
}


int main()
{
int i,j;
cout<<"enter no of nodes";
cin>>n;
cout<<"enter adj matrix";
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
cin>>adj[i][j];
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
if(i==j)
cost[i][j]=0;
else if(adj[i][j]!=0)
{
cout<<"enter edge cost" <<  i <<j ;
cin>>cost[i][j];
}
else cost[i][j]=infinity;
}
   cout<<" \nThe matrix is:- ";
    for(i=1;i<=n;i++)
    {
      for(j=1;j<=n;j++)
	   cout<<cost[i][j];
      cout<<"\n";
    }
 prim();
 return 0;
}
