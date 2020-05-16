#include<iostream>
#include<stdlib.h>
#define null 0
using namespace std;
class node
{
 public :
 int info;
 node *left;
 node *right;
};
class BST
{
//private:
public:
	node *root;
BST()
{
root=null;
}
void insert(int);
void preorder(node *root);
void inorder(node *root);
void postorder(node *root);
void search(int);
node* findmin(node* r);
node* del(int x,node *t);
};
void BST::insert (int x)
{
	node *temp,*t;
	if(root==null)
	{
		root=new node;
		root->left=null;
		root->right=null;
		root->info=x;
		return;
	}
	else
	{
		temp=root;
		t=new node;
		t->left=t->right=null;
		t->info=x;
		while(1)
		{
			if(temp->info==x)
			{
				cout<<"dupe node";
				return;
			}
			else
			{
			if(x>temp->info)
			{
				if(temp->right==null)
					{
						temp->right=t;
						return;
					}
				else
				temp=temp->right;
			}
			else
			{
				if(temp->left==null)
				{
					temp->left=t;
					return;
				}
				else
				temp=temp->left;
			}
			}
		}
	}
}

void BST::preorder(node *root)
{
if(root!=null)
	{
	cout<<root->info<<"\t";
	preorder(root->left);
	preorder(root->right);
	}
}

void BST::postorder(node *root)
{
if(root!=null)
{
postorder(root->left);
postorder(root->right);
cout<<root->info<<"\t";
}
}

void BST::inorder(node *root)
{
if(root!=null)
{
inorder(root->left);
cout<<root->info<<"\t";
inorder(root->right);
}
}
void BST::search(int ele)
{
node *temp;
int flag=0;
temp=root;
while(flag==0 && temp !=null)
{
if(temp->info==ele)
flag=1;
else if(ele>temp->info)
temp=temp->right;
else temp=temp->left;
}
if(flag==1)
cout<<"element found";
else cout<<"element not found";
}

node* BST:: findmin(node* r)
{
if(r==null)
return null;
else if(r->left==null)
return r;
else
findmin(r->left);
}


node* BST::del(int x,node *t)
{
node *temp;
if(t==null)
cout<<"tree is empty\n";
else if(t->info>x)
t->left=del (x,t->left);
else if(t->info<x)
t->right=del (x,t->right);
else if(t->left && t->right) /* ele node has 2 children */
{
temp=findmin(t->right);
t->info=temp->info;
t->right=del (t->info,t->right);
}
else
{
temp=t;
if(t->left==null)
t=t->right;
else if(t->right==null)
t=t->left;
free(temp);
}
return t;
}

main()
{
	BST bst;
int ch,ele;
do
{
cout<<"\n1.insert\n";
cout<<"2.inorder\n";
cout<<"3.preorder\n";
cout<<"4.postorder\n";
cout<<"5.search\n";
cout<<"6.delete\n";
cout<<"7.exit\n";
cout<<"enter choice\n";
cin>>ch;
switch(ch)
{
case 1:cout<<"enter a value";
cin>>ele;
bst.insert(ele);
break;
case 2:
cout<<"inorder";
bst.inorder(bst.root);
break;
case 3:
cout<<"preorder";
bst.preorder(bst.root);
break;
case 4:
cout<<"postorder";
bst.postorder(bst.root);
break;
case 5:
cout<<"enter ele to be searched";
cin>>ele;
bst.search(ele);
break;
case 7:exit(0);
break;
case 6:
cout<<"enter ele to delete\n";
cin>>ele;
bst.del(ele,bst.root);
break;
}
}while(ch<=7);
}
