/* program for DFS*/
#include <iostream>
#include<stdlib.h>
using namespace std;
int visit[20],stack[20],adj[10][10],n;
int top=-1;
void push(int  item)
{
	top++;
	stack[top]=item;
		}
int	pop( )
{
	int item;
	item=stack[top--];
	return item;
}

int isempty()
{
	if(top==-1)
		return 1;
	else return 0;
}

void init()
{
int i;
for(i=0;i<20;i++)
visit[i]=0;
}

void dfs()
{
	int v,i;
	cout<<"enter from which node u want to traverse";
	cin>>v;
	push(v);
	visit[v]=1;
	while(!(isempty()))
	{
		v=pop();
			cout<<v;
		for(i=0;i<n;i++)
			if(adj[v][i]==1 && visit[i]==0)
		{
			push(i);
			visit[i]=1;
		}
	}
}

 main()
{
	int  i,j;
	init();
	cout<<"enter no of vertices";
	cin>>n;
	cout<<"enter adj matrix\n";
	for(i=0;i<n;i++)
	{
		cout<<"enter "<<i<<"row";
		for(j=0;j<n;j++)
			cin>>adj[i][j];
	}
	cout<<"\n DFS travalsal of  given graph is";
	dfs();
	return 0;
}
