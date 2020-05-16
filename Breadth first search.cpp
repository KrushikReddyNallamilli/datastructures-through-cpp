#include <iostream>
#include<stdlib.h>
using namespace std;
int visit[20],queue[20],adj[5][5],n;
int front=-1;
int rear=-1;

void insert(int  item)
{
	rear++;
	queue[rear]=item;
}

int	del( )
{
	int item;
	item=queue[++front];
	return item;
}

int isempty()
{
	if(front==rear)
		return 1;
	else return 0;
}

void init()
{
int i;
for(i=0;i<n;i++)
visit[i]=0;
}

void bfs()
{
	int v,i;
	cout<<"enter from which node u want to start the traverse";
	cin>>v;
	insert(v);
	visit[v]=1;
	while(!(isempty()))
	{
		v=del();
			cout<<v<<"->";
		for(i=0;i<n;i++)
			if(adj[v][i]==1 && visit[i]==0)
		{
			insert(i);
			visit[i]=1;
		}
	}
}

int main()
{
	int  i,j;
	cout<<"enter no of vertices";
	cin>>n;
	init();
	cout<<"enter adj matrix";
	for(i=0;i<n;i++)
	{
		cout<<"enter row"<<i;
		for(j=0;j<n;j++)
			cin>>adj[i][j];
	}
	cout<<"\n BFS travalsal of  given graph is\n";
	bfs();
	return 0;
}
